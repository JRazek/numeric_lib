#pragma once

#include <cmath>
#include <cstdlib>
#include <limits>
#include <tuple>
#include <type_traits>

#include "jr_numeric/utils/concepts.hpp"

namespace jr_numeric::differential {
using concepts::FloatingPoint;
using concepts::ScalarField;

namespace implementation {

template <concepts::FloatingPoint T>
consteval auto differentiationEpsilon() -> T {
  return std::sqrt(std::numeric_limits<T>::epsilon());
}

}  // namespace implementation
// N - # of variable to differentiate by in Args
template <
    std::size_t N,
    FloatingPoint... Args,
    FloatingPoint T = std::common_type_t<Args...>,
    ScalarField<sizeof...(Args)> ScalarFieldType>
auto partialDerivative(ScalarFieldType const& function, Args&&... args)
    -> std::invoke_result_t<ScalarFieldType, Args...> {
  auto tup = std::make_tuple(static_cast<T>(args)...);
  auto& el = std::get<N>(tup);

  constexpr auto kEpsilon = implementation::differentiationEpsilon<T>();

  el -= kEpsilon;

  const auto val = std::apply(function, tup);

  el += 2 * kEpsilon;

  const auto val_h = std::apply(function, tup);

  return (val_h - val) / (2 * kEpsilon);
}

}  // namespace jr_numeric::differential
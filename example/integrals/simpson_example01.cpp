#include <fmt/core.h>

#include <cmath>
#include <numbers>

#include "integrals/simpson.hpp"

auto main() -> int {
  integrals::Integral<double> integral{0.0, std::numbers::pi / 2, [](double x) { return std::cos(x); }};

  auto const res = integrals::simpson(integral, 1000);

  fmt::print("Result: {}\n", res);
}
#include <fmt/core.h>

#include <numbers>

#include "jr_numeric/differential/derivatives.hpp"

auto main() -> int {
  using jr_numeric::differential::partialDerivative;
  using f = float;
  using d = double;
  using ld = long double;

  auto function = [](double x, double y) { return std::sin(x) + y; };

  auto res1 = partialDerivative<0, f>(function, 2 * std::numbers::pi, 2.0);

  auto res2 = partialDerivative<0, d>(function, 2 * std::numbers::pi, 2.0);

  auto res3 = partialDerivative<0, ld>(function, 2 * std::numbers::pi, 2.0);

  fmt::print("differentiation of f(x) = x^2 + y^2 wrt x\n");
  fmt::print("float: {}, double: {}, long double: {}\n", res1, res2, res3);
}

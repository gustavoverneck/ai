#pragma once 

#include <vector>
#include <utility>

namespace linear_regression {
/**
 * @brief Fits a line y = a * x + b to the data using least squares.
 * 
 * Uses the formulas:
 *   a = (n * Σ(xy) - Σx * Σy) / (n * Σ(x^2) - (Σx)^2)
 *   b = (Σy * Σ(x^2) - Σx * Σ(xy)) / (n * Σ(x^2) - (Σx)^2)
 *
 * @param x Vector of x values.
 * @param y Vector of y values (must be same size as x).
 * @return std::pair<double, double> (a, b) where a is the slope and b is the intercept.
 * @throws std::invalid_argument if input vectors are not the same non-zero length.
 * @throws std::runtime_error if the denominator is zero (cannot fit line).
 */
std::pair<double, double> fit(const std::vector<double>& x, const std::vector<double>& y);

} 

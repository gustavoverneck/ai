#include "linear_regression.h"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <utility>
#include <numeric> // for std::accumulate

namespace linear_regression {

std::pair<double, double> fit(const std::vector<double>& x, const std::vector<double>& y) {
    size_t n = x.size();
    if (n != y.size() || n == 0) {
        throw std::invalid_argument("Input vectors must have the same non-zero length.");
    }
    double sum_x = std::accumulate(x.begin(), x.end(), 0.0);
    double sum_y = std::accumulate(y.begin(), y.end(), 0.0);
    double sum_xx = 0.0, sum_xy = 0.0;
    for (size_t i = 0; i < n; i++) {
        sum_xx += x[i] * x[i];
        sum_xy += x[i] * y[i];
    }
    double denom = n * sum_xx - sum_x * sum_x;
    if (denom == 0) {
        throw std::runtime_error("Denominator is zero, can't fit line.");
    }

    double a = (n * sum_xy - sum_x * sum_y) / denom;
    double b = (sum_y * sum_xx - sum_x * sum_xy) / denom;
    return {a, b};
};

double predict(double a, double b, double x) {
    return a * x + b;
}

double predict_x(double a, double b, double y) {
    if (a == 0) throw std::invalid_argument("Slope a cannot be zero for inverse prediction.");
    return (y - b) / a;
}

} // namespace linear_regression

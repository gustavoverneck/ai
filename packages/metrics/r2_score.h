#pragma once 

#include <vector>
#include <stdexcept>

namespace ai {
namespace metrics {

/**
 * @brief Calculates the coefficient of determination (R² score) between true and predicted values.
 *
 * The R² score, also known as the coefficient of determination, measures the proportion of the variance
 * in the dependent variable that is predictable from the independent variable(s). It is commonly used
 * to evaluate the performance of regression models.
 *
 * @param y_true A vector of true target values.
 * @param y_pred A vector of predicted values.
 * @return The R² score as a double. Returns 0.0 if the variance of y_true is zero to avoid division by zero.
 * @throws std::invalid_argument if the input vectors are not the same size or are empty.
 *
 * @note R² score ranges from -∞ to 1.0, where 1.0 indicates perfect prediction, and lower values indicate
 * worse performance.
 */
double r2_score(const std::vector<double>& y_true, const std::vector<double>& y_pred) {

    if (y_true.size() != y_pred.size() || y_true.empty()) {
        throw std::invalid_argument("Vectors must be the same size and non-empty");
    }
    double mean = 0.0;
    for (double val : y_true) {
        mean += val;
    }
    mean /= y_true.size();

    double ss_tot = 0.0;
    double ss_res = 0.0;
    for (size_t i = 0; i < y_true.size(); ++i) {
        ss_tot += (y_true[i] - mean) * (y_true[i] - mean);
        ss_res += (y_true[i] - y_pred[i]) * (y_true[i] - y_pred[i]);
    }
    if (ss_tot == 0.0) {
        return 0.0; // Avoid division by zero
    }
    return 1.0 - (ss_res / ss_tot);
}

} // namespace ai
} // namespace metrics
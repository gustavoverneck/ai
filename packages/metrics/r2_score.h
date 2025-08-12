// packages/metrics/r2_score.h

#pragma once 

#include <Eigen/Dense>
#include <stdexcept>

namespace ai {
namespace metrics {

/**
 * @brief Calculates the coefficient of determination (R² score) between true and predicted values using Eigen vectors.
 *
 * The R² score, also known as the coefficient of determination, measures the proportion of the variance
 * in the dependent variable that is predictable from the independent variable(s). It is commonly used
 * to evaluate the performance of regression models.
 *
 * @param y_true An Eigen vector of true target values.
 * @param y_pred An Eigen vector of predicted values.
 * @return The R² score as a double. Returns 0.0 if the variance of y_true is zero to avoid division by zero.
 * @throws std::invalid_argument if the input vectors are not the same size or are empty.
 *
 * @note R² score ranges from -∞ to 1.0, where 1.0 indicates perfect prediction, and lower values indicate
 * worse performance.
 */
inline double r2_score(const Eigen::VectorXd& y_true, const Eigen::VectorXd& y_pred) {
    if (y_true.size() != y_pred.size() || y_true.size() == 0) {
        throw std::invalid_argument("Vectors must be the same size and non-empty");
    }
    double mean = y_true.mean();
    double ss_tot = (y_true.array() - mean).square().sum();
    double ss_res = (y_true - y_pred).squaredNorm();
    if (ss_tot == 0.0) {
        return 0.0; // Avoid division by zero
    }
    return 1.0 - (ss_res / ss_tot);
}

} // namespace ai
} // namespace metrics
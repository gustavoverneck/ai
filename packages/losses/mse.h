#pragma once 

#include <Eigen/Dense>
#include <stdexcept>

namespace ai {
namespace losses {

/**
 * @brief Computes the Mean Squared Error (MSE) between two Eigen vectors.
 *
 * This function calculates the average of the squared differences between
 * corresponding elements in the true and predicted value vectors.
 *
 * @param y_true An Eigen vector of true values.
 * @param y_pred An Eigen vector of predicted values.
 * @return The mean squared error as a double.
 * @throws std::invalid_argument if the input vectors are not the same size or are empty.
 */
inline double mse(const Eigen::VectorXd& y_true, const Eigen::VectorXd& y_pred) {
    if (y_true.size() != y_pred.size() || y_true.size() == 0) {
        throw std::invalid_argument("Vectors must be the same size and non-empty");
    }
    return (y_true - y_pred).squaredNorm() / y_true.size();
}

} // namespace losses
} // namespace ai
#pragma once 

#include <vector>
#include <stdexcept>

namespace ai {
namespace losses {

/**
 * @brief Computes the Mean Squared Error (MSE) between two vectors.
 *
 * This function calculates the average of the squared differences between
 * corresponding elements in the true and predicted value vectors.
 *
 * @param y_true A vector of true values.
 * @param y_pred A vector of predicted values.
 * @return The mean squared error as a double.
 * @throws std::invalid_argument if the input vectors are not the same size or are empty.
 */
double mse(const std::vector<double>& y_true, const std::vector<double>& y_pred) {
    if (y_true.size() != y_pred.size() || y_true.empty()) {
        throw std::invalid_argument("Vectors must be the same size and non-empty");
    }
    double sum = 0.0;
    for (size_t i = 0; i < y_true.size(); ++i) {
        double diff = y_true[i] - y_pred[i];
        sum += diff * diff;
    }
    return sum / y_true.size();
}

} // namespace losses
} // namespace ai
// packages/math/activations.h

#pragma once 

#include <Eigen/Dense>
#include <cmath>

namespace ai {
namespace math { 

/**
 * @brief Computes the sigmoid activation function element-wise on the input vector.
 *
 * The sigmoid function is defined as 1 / (1 + exp(-z)), where z is each element of the input vector.
 * This function is commonly used in neural networks as an activation function.
 *
 * @param z Input vector of type Eigen::VectorXd.
 * @return Eigen::VectorXd Output vector where each element is the sigmoid of the corresponding input element.
 */
inline Eigen::VectorXd sigmoid (const Eigen::VectorXd& z) {
    return 1.0 / (1.0 + (-z.array()).exp());
}


} // namespace math
} // namespace ai
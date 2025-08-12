#pragma once 

#include <Eigen/Dense>
#include "losses/mse.h"
#include "metrics/r2_score.h"

namespace ai {

class LinearRegression {
public:
    LinearRegression() : a_(0.0), b_(0.0), fitted_(false) {}

    /**
     * @brief Fits the model to data using least squares.
     * 
     * Equation:
     *   y = a * x + b
     */
    void fit(const Eigen::VectorXd& x, const Eigen::VectorXd& y) {
        if (x.size() != y.size() || x.size() == 0)
            throw std::invalid_argument("x and y must have the same non-zero length");

        // Design matrix: [x 1]
        Eigen::MatrixXd A(x.size(), 2);
        A.col(0) = x;
        A.col(1) = Eigen::VectorXd::Ones(x.size());
        // Solve for [a, b] in least squares sense
        Eigen::Vector2d coeffs = A.colPivHouseholderQr().solve(y);
        a_ = coeffs(0);
        b_ = coeffs(1);
        fitted_ = true;
    }

    /**
     * @brief Predicts y from a single x using the fitted model.
     */
    double predict(double x) const {
        check_fitted();
        return a_ * x + b_;
    }

    /**
     * @brief Predicts y values from a vector of x values.
     */
    Eigen::VectorXd predict(const Eigen::VectorXd& x_vals) const {
        check_fitted();
        if (x_vals.size() == 0) return Eigen::VectorXd();
        return a_ * x_vals.array() + b_;
    }

    /**
     * @brief Predicts x given a y value using the fitted model.
     */
    double predict_x(double y) const {
        check_fitted();
        if (a_ == 0.0)
            throw std::runtime_error("Slope is zero; cannot solve for x.");
        return (y - b_) / a_;
    }
    
    /**
     * @brief Returns the slope (a) of the fitted line.
     */
    double get_slope() const { check_fitted(); return a_; }

    double get_intercept() const { check_fitted(); return b_; }

    double score(const Eigen::VectorXd& x, const Eigen::VectorXd& y) const {
        auto y_pred = predict(x);
        return ai::metrics::r2_score(y, y_pred);
    }

    double loss(const Eigen::VectorXd& x, const Eigen::VectorXd& y) const {
        auto y_pred = predict(x);
        return ai::losses::mse(y, y_pred);
    }


private:
    double a_, b_;
    bool fitted_;

    void check_fitted() const {
        if (!fitted_)
            throw std::runtime_error("Model is not fitted yet.");
    }
};


} // namespace ml
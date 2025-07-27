#pragma once 

#include <vector>
#include <utility>
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
    void fit(const std::vector<double>& x, const std::vector<double>& y) {
        if (x.size() != y.size() || x.empty())
            throw std::invalid_argument("x and y must have the same non-zero length");

        const size_t n = x.size();
        double sum_x = 0.0, sum_y = 0.0, sum_xy = 0.0, sum_x2 = 0.0;

        for (size_t i = 0; i < n; ++i) {
            sum_x += x[i];
            sum_y += y[i];
            sum_xy += x[i] * y[i];
            sum_x2 += x[i] * x[i];
        }

        double denominator = n * sum_x2 - sum_x * sum_x;
        if (denominator == 0.0)
            throw std::runtime_error("Cannot fit line: denominator is zero");

        a_ = (n * sum_xy - sum_x * sum_y) / denominator;
        b_ = (sum_y * sum_x2 - sum_x * sum_xy) / denominator;
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
    std::vector<double> predict(const std::vector<double>& x_vals) const {
        check_fitted();
        std::vector<double> result;
        result.reserve(x_vals.size());
        for (double x : x_vals)
            result.push_back(predict(x));
        return result;
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
    
    /**
     * @brief Predicts y values for each x in the input vector using the fitted model.
     */
    double get_intercept() const { check_fitted(); return b_; }

    /**
     * @brief Predicts y values for each x in the input vector using the fitted model.
     */
    double score(const std::vector<double>& x, const std::vector<double>& y) const {
        auto y_pred = predict(x);
        return ai::metrics::r2_score(y, y_pred);
    }

    /**
     * @brief Calculates the mean squared error (MSE) loss between the predicted and actual values.
     */
    double loss(const std::vector<double>& x, const std::vector<double>& y) const {
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
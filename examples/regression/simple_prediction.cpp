#include "linear_regression.h"
#include <iostream>
#include <Eigen/Dense>

int main() {
    Eigen::VectorXd x(5);
    x << 1, 2, 3, 4, 5;
    Eigen::VectorXd y(5);
    y << 2, 4, 6, 8, 10;

    ai::regression::LinearRegression model;
    model.fit(x, y);

    std::cout << "a (slope): " << model.get_slope() << "\n";
    std::cout << "b (intercept): " << model.get_intercept() << "\n";

    double pred = model.predict(6);
    std::cout << "Prediction for x = 6: " << pred << "\n";

    // Use new methods
    double mse_val = model.loss(x, y);
    double r2_val = model.score(x, y);
    std::cout << "MSE: " << mse_val << "\n";
    std::cout << "R2 Score: " << r2_val << "\n";
}
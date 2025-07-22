#include <iostream>
#include <vector>
#include "linear_regression.h"

int main() {
    std::cout << "Example: linear_regression/simple_prediction" << std::endl;

    // Example data: x and y values
    std::vector<double> x = {1, 2, 3, 4, 5};
    std::vector<double> y = {2, 4, 5, 4, 5};

    // Fit the line y = a * x + b
    auto [a, b] = linear_regression::fit(x, y);

    std::cout << "Fitted line: y = " << a << " * x + " << b << std::endl;

    double x_pred = 6.0;

    // Predict using linear_regression::predict
    double y_pred_func = linear_regression::predict(a, b, x_pred);
    std::cout << "Prediction using predict(): x = " << x_pred << " y = " << y_pred_func << std::endl;

    // Predict x for a given y using linear_regression::predict_x
    double y_target = 7.0;
    double x_pred_func = linear_regression::predict_x(a, b, y_target);
    std::cout << "Prediction using predict_x() for y = " << y_target << ": x = " << x_pred_func << std::endl;

    return 0;
}

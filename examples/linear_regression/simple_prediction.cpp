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

    // Predict a value
    double x_pred = 6.0;
    double y_pred = a * x_pred + b;
    std::cout << "Prediction for x = " << x_pred << ": y = " << y_pred << std::endl;

    return 0;
}

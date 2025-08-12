// packages/classification/logistic_regression.h

#pragma once

#include <Eigen/Dense>
#include <cmath>
#include "math/activations.h"

namespace ai {
namespace classification {

class LogisticRegression {
public:
    LogisticRegression(double learning_rate = 0.01, int n_interactions = 1000)
     : learning_rate_(learning_rate), n_iterations_(n_interactions) {}
    
    void fit() {
        
    }

    Eigen::VectorXd predict_proba(const Eigen::MatrixXd& X) const {
        
    }

    Eigen::VectorXd predict(const Eigen::MatrixXd& X) const {
        
    }
    
private:
    double learning_rate_;
    int n_iterations_;
    Eigen::VectorXd weights_;

};     
} // namespace classification
} // namespace ai
#ifndef COBRAMODELPARSER_MODEL_HPP
#define COBRAMODELPARSER_MODEL_HPP

#include <Eigen/Core>

namespace CobraModelParser {

    class Model {
    public:
        const Eigen::MatrixXd &getA() const {
            return A;
        }

        const std::string &getModelDescription() const {
            return ModelDescription;
        }

        void setModelDescription(const std::string &ModelDescription) {
            Model::ModelDescription = ModelDescription;
        }

        void setA(const Eigen::MatrixXd &A) {
            Model::A = A;
        }

        const Eigen::VectorXd &getB() const {
            return b;
        }

        void setB(const Eigen::VectorXd &b) {
            Model::b = b;
        }

    private:
        Eigen::MatrixXd A;
        Eigen::VectorXd b;
        std::string ModelDescription;
    };

}


#endif //COBRAMODELPARSER_MODEL_HPP

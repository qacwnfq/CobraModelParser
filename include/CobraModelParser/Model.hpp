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
            return description;
        }

        void setModelDescription(const std::string &description) {
            Model::description = description;
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

        const std::string &getOrigin() const {
            return origin;
        }

        void setOrigin(const std::string &origin) {
            Model::origin = origin;
        }

    private:
        friend class ModelBuilder;

        Eigen::MatrixXd A;
        Eigen::VectorXd b;
        std::string description;
        std::string origin;
    };

}


#endif //COBRAMODELPARSER_MODEL_HPP

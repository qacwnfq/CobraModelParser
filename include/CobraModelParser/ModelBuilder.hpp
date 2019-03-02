#ifndef COBRAMODELPARSER_MODELBUILDER_HPP
#define COBRAMODELPARSER_MODELBUILDER_HPP

#include <Eigen/Core>
#include <vector>

#include "CobraModelParser/Model.hpp"
#include "CobraModelParser/MatlabV5/MatlabV5ArrayDataTypeParser.hpp"
#include "CobraModelParser/MatlabV5/MatlabV5DataElement.hpp"

namespace CobraModelParser {

    class ModelBuilder {
    public:

        ModelBuilder &setModelOrigin(const std::string &modelOrigin) {
            this->modelOrigin = modelOrigin;
            return *this;
        }

        ModelBuilder &setModelDescription(const std::string &modelDescription) {
            this->modelDescription = modelDescription;
            return *this;
        }

        ModelBuilder &setData(const Eigen::MatrixXd &A, const Eigen::VectorXd &b) {
            this->A = A;
            this->b = b;
            return *this;
        }

        Model build() {
            Model model;
            model.origin = modelOrigin;
            model.description = modelDescription;
            model.setA(A);
            model.setB(b);
            return model;
        }

    private:
        std::string modelOrigin;
        std::string modelDescription;
        Eigen::VectorXd b;
        Eigen::MatrixXd A;
    };
}

#endif //COBRAMODELPARSER_MODELBUILDER_HPP

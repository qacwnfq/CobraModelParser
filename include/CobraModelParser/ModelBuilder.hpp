#ifndef COBRAMODELPARSER_MODELBUILDER_HPP
#define COBRAMODELPARSER_MODELBUILDER_HPP

#include <vector>

#include "CobraModelParser/Model.hpp"
#include "CobraModelParser/MatlabV5ArrayDataTypeParser.hpp"
#include "CobraModelParser/MatlabV5DataElement.hpp"

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

        ModelBuilder &setData(const MatlabV5DataElement &data) {
            this->data = data;
            return *this;
        }

        Model build(const std::string& endianIndicator) {
            Model model = MatlabV5ArrayDataTypeParser::parseModelFromMatlabV5DataElement(data, endianIndicator);
            model.origin = modelOrigin;
            model.description = modelDescription;
            return model;
        }

    private:
        std::string modelOrigin;
        std::string modelDescription;
        MatlabV5DataElement data;

    };
}

#endif //COBRAMODELPARSER_MODELBUILDER_HPP

#ifndef COBRAMODELPARSER_MODELBUILDER_HPP
#define COBRAMODELPARSER_MODELBUILDER_HPP

#include <vector>

#include "CobraModelParser/Model.hpp"
#include "CobraModelParser/MatlabV5DataElement.hpp"

namespace CobraModelParser {
    class ModelBuilder {
        Model build(std::vector<MatlabV5DataElement> dataElements);
    };
}

#endif //COBRAMODELPARSER_MODELBUILDER_HPP

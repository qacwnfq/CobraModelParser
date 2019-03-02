#ifndef COBRAMODELPARSER_MATLABV5ARRAYDIMENSIONSELEMENT_HPP
#define COBRAMODELPARSER_MATLABV5ARRAYDIMENSIONSELEMENT_HPP

#include <ostream>
#include "MatlabV5ArrayDataSubelement.hpp"

namespace CobraModelParser {
    class MatlabV5ArrayDimensionsElement: public MatlabV5ArrayDataSubelement {
    public:
        const std::vector<size_t> &getDimensionSizes() const {
            return dimensionSizes;
        }

        void setDimensionSizes(const std::vector<size_t> &dimensionSizes) {
            MatlabV5ArrayDimensionsElement::dimensionSizes = dimensionSizes;
        }

    public:

    private:
        std::vector<size_t> dimensionSizes;
    };
}

#endif //COBRAMODELPARSER_MATLABV5ARRAYDIMENSIONSELEMENT_HPP

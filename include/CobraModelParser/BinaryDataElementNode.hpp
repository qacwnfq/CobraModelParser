#ifndef COBRAMODELPARSER_BINARYDATAELEMENTNODE_HPP
#define COBRAMODELPARSER_BINARYDATAELEMENTNODE_HPP

#include <memory>
#include <vector>
#include "Byte.hpp"
#include "DataElementTag.hpp"

namespace CobraModelParser{
    class BinaryDataElementNode {
    private:
        DataElementTag dataElementTag;
        std::vector<Byte> binaryData;
        std::vector<std::unique_ptr<BinaryDataElementNode>> children;
        std::unique_ptr<BinaryDataElementNode> parent;
    };
}

#endif //COBRAMODELPARSER_BINARYDATAELEMENTNODE_HPP

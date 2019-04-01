#ifndef COBRAMODELPARSER_DATAELEMENTNODE_HPP
#define COBRAMODELPARSER_DATAELEMENTNODE_HPP


#include <memory>
#include <vector>
#include "DataElementTag.hpp"

namespace CobraModelParser {

    class DataElementNode {
    public:
    };

    template <typename T>
    class DataElementNodeImpl : public DataElementNode {
    private:
        DataElementTag dataElementTag;
        T value;
        std::vector<std::unique_ptr<DataElementNode>> children;
        std::unique_ptr<DataElementNode> parent;


    };
}

#endif //COBRAMODELPARSER_DATAELEMENTNODE_HPP

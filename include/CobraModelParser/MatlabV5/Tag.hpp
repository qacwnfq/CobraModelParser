#ifndef COBRAMODELPARSER_MATLABV5_TAG_HPP
#define COBRAMODELPARSER_MATLABV5_TAG_HPP

#include <vector>

#include "CobraModelParser/Exceptions.hpp"
#include "CobraModelParser/MatlabV5/DataType.hpp"

namespace CobraModelParser::MatlabV5 {
    class Tag {
    public:
        Tag(const std::vector<char> &bytes) {
        }

        const DataType &getType() const {
            return type;
        }

        size_t getNumberOfBytes() const {
            return numberOfBytes;
        }

    private:

        DataType type;
        size_t numberOfBytes;
    };
}

#endif //COBRAMODELPARSER_MATLABV5_TAG_HPP

#ifndef COBRAMODELPARSER_MATLABV5_TAG_HPP
#define COBRAMODELPARSER_MATLABV5_TAG_HPP

#include <vector>
#include <ostream>

#include "CobraModelParser/Exceptions.hpp"
#include "CobraModelParser/MatlabV5/DataType.hpp"

namespace CobraModelParser {
    namespace MatlabV5 {
        class Tag {
        public:
            Tag() {}
            const DataType &getType() const {
                return type;
            }

            friend std::ostream &operator<<(std::ostream &os, const Tag &tag) {
                os << "type: " << tag.type << " numberOfBytes: " << tag.numberOfBytes;
                return os;
            }

            size_t getNumberOfBytes() const {
                return numberOfBytes;
            }

        private:
            friend class TagParser;

            Tag(const DataType &type, size_t numberOfBytes) : type(type), numberOfBytes(numberOfBytes) {}

            DataType type;
            size_t numberOfBytes;
        };
    }
}

#endif //COBRAMODELPARSER_MATLABV5_TAG_HPP

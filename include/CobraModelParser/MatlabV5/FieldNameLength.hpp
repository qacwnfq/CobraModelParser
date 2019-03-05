#ifndef COBRAMODELPARSER_MATLABV5_FIELDNAMELENGTH_HPP
#define COBRAMODELPARSER_MATLABV5_FIELDNAMELENGTH_HPP

#include <algorithm>
#include <cstddef>
#include <ostream>
#include <CobraModelParser/ByteParser.hpp>
#include "CobraModelParser/ByteQueue.hpp"
#include "DataTypeTable.hpp"

namespace CobraModelParser {
    namespace MatlabV5 {
        class FieldNameLength {
        public:
            static FieldNameLength
            fromByteQueue(ByteQueue &byteQueue, const ByteParser &byteParser) {
                std::vector<Byte> byteBlock = byteQueue.popByteBlock();

                if (byteParser.getEndianIndicator() == "IM") {
                    std::iter_swap(byteBlock.begin(), byteBlock.begin() + 2);
                    std::iter_swap(byteBlock.begin() + 1, byteBlock.begin() + 3);
                }

                auto numberOfBytes = byteParser.parseIntegerType<size_t>(
                        std::vector<Byte>(byteBlock.begin(), byteBlock.begin() + 2));
                if (numberOfBytes != 4) {
                    throw UnexpectedSizeException(4, numberOfBytes);
                }
                auto typeLookUp = byteParser.parseIntegerType<size_t>(
                        std::vector<Byte>(byteBlock.begin() + 2, byteBlock.begin() + 4));
                const DataType &type = DataTypeTable::lookUp(typeLookUp);
                if (type != DataTypeTable::lookUp(5)) {
                    throw UnexpectedDataTypeException(DataTypeTable::lookUp(5).getSymbol(), type.getSymbol());
                }

                auto maxSize = byteParser.parseIntegerType<size_t>(
                        std::vector<Byte>(byteBlock.begin() + 4, byteBlock.end()));

                return FieldNameLength(maxSize);
            }

            FieldNameLength(const size_t &maxSize) : maxSize(maxSize) {}

            friend std::ostream &operator<<(std::ostream &os, const FieldNameLength &length) {
                os << "maxSize: " << length.maxSize;
                return os;
            }

            size_t getMaxSize() const {
                return maxSize;
            }


        private:
            size_t maxSize;
        };
    }
}

#endif //COBRAMODELPARSER_MATLABV5_FIELDNAMELENGTH_HPP

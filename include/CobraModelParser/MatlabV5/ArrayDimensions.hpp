#include <utility>

#ifndef COBRAMODELPARSER_MATLABV5_ARRAYDIMENSIONS_HPP
#define COBRAMODELPARSER_MATLABV5_ARRAYDIMENSIONS_HPP

#include <vector>
#include <ostream>
#include <iostream>

#include "CobraModelParser/ByteParser.hpp"
#include "CobraModelParser/MatlabV5/TagParser.hpp"

namespace CobraModelParser {
    namespace MatlabV5 {
        class ArrayDimensions {
        public:
            ArrayDimensions(Tag tag, const std::vector<size_t> &dimensionSizes) : tag(std::move(tag)), dimensionSizes(
                    dimensionSizes) {}

            const Tag &getTag() const {
                return tag;
            }

            const std::vector<size_t> &getDimensionSizes() const {
                return dimensionSizes;
            }

            friend std::ostream &operator<<(std::ostream &os, const ArrayDimensions &dimensions) {
                os << "tag: " << dimensions.tag;
                return os;
            }

            static ArrayDimensions
            fromByteQueue(ByteQueue &byteQueue, const ByteParser &byteParser,
                          const TagParser &tagParser) {
                Tag tag = tagParser.parseTag(byteQueue);
                if (tag.getType() != DataTypeTable::lookUp(5)) {
                    throw UnexpectedDataTypeException(DataTypeTable::lookUp(5).getSymbol(), tag.getType().getSymbol());
                }
                if (tag.getNumberOfBytes() % tag.getType().getSize() != 0) {
                    throw UnexpectedSizeException(tag.getNumberOfBytes() / tag.getType().getSize(),
                                                  tag.getNumberOfBytes());
                }

                size_t numberOfBlocksToRead = std::ceil(
                        static_cast<long double>(tag.getNumberOfBytes()) / byteQueue.MINIMAL_BYTE_BLOCK_SIZE);

                std::vector<Byte> byteBlock = byteQueue.popByteBlock();

                size_t dimension_x = byteParser.parseIntegerType<size_t>(std::vector<Byte>(byteBlock.begin(),
                                                                                           byteBlock.begin() + 4));
                size_t dimension_y = byteParser.parseIntegerType<size_t>(std::vector<Byte>(byteBlock.begin() + 4,
                                                                                           byteBlock.begin() + 8));

                std::vector<size_t> dimensionSizes;
                dimensionSizes.push_back(dimension_x);
                dimensionSizes.push_back(dimension_y);
                return ArrayDimensions(tag, dimensionSizes);
            }

            ArrayDimensions() = default;

        private:
            Tag tag;
            std::vector<size_t> dimensionSizes;
        };
    }
}


#endif //COBRAMODELPARSER_MATLABV5_ARRAYDIMENSIONS_HPP

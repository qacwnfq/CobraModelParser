#ifndef COBRAMODELPARSER_MATLABV5_FIELD_HPP
#define COBRAMODELPARSER_MATLABV5_FIELD_HPP

#include "Tag.hpp"
#include "ArrayFlags.hpp"
#include "ArrayDimensions.hpp"
#include "ArrayName.hpp"

namespace CobraModelParser {
    namespace MatlabV5 {
        class Field {
        public:
            const std::string &getFieldName() const {
                return fieldName;
            }

            const Tag &getTag() const {
                return tag;
            }

            const ArrayFlags &getArrayFlags() const {
                return arrayFlags;
            }

            const ArrayDimensions &getArrayDimensions() const {
                return arrayDimensions;
            }

            const ArrayName &getArrayName() const {
                return arrayName;
            }

            const std::vector<Byte> &getData() const {
                return data;
            }

            static Field
            fromByteQueue(ByteQueue &byteQueue,
                          const ByteParser &byteParser,
                          const TagParser &tagParser,
                          const std::string &fieldName) {

                Tag tag = tagParser.parseTag(byteQueue);

                const ArrayFlags &flags = ArrayFlags::fromByteQueue(byteQueue, byteParser, tagParser);
                const ArrayDimensions &dimensions = ArrayDimensions::fromByteQueue(byteQueue, byteParser, tagParser);
                const ArrayName &name = ArrayName::fromByteQueue(byteQueue, byteParser, tagParser);

                size_t numberOfDataBytesInField = tag.getNumberOfBytes() -
                        8 -
                        flags.getTag().getNumberOfBytes() -
                        8 -
                        dimensions.getTag().getNumberOfBytes() -
                        8 -
                        name.getTag().getNumberOfBytes();

                std::vector<Byte> data = byteQueue.popByteBlocks(numberOfDataBytesInField / ByteQueue::BYTE_BLOCK_SIZE);

                return Field(tag,
                        flags,
                        dimensions,
                        name,
                        data);

            }

            Field() = default;

            Field(const Tag &tag, const ArrayFlags &arrayFlags, const ArrayDimensions &arrayDimensions,
                  const ArrayName &arrayName, const std::vector<Byte> &data) : tag(tag), arrayFlags(arrayFlags),
                                                                               arrayDimensions(arrayDimensions),
                                                                               arrayName(arrayName), data(data) {}

        private:
            std::string fieldName;
            Tag tag;
            ArrayFlags arrayFlags;
            ArrayDimensions arrayDimensions;
            ArrayName arrayName;
            std::vector<Byte> data;

        };
    }
}

#endif //COBRAMODELPARSER_FIELD_HPP

#ifndef COBRAMODELPARSER_MATLABV5_FIELDNAMES_HPP
#define COBRAMODELPARSER_MATLABV5_FIELDNAMES_HPP

#include <CobraModelParser/ByteQueue.hpp>
#include <CobraModelParser/ByteParser.hpp>
#include <iostream>
#include "TagParser.hpp"
#include "FieldNameLength.hpp"

namespace CobraModelParser {
    namespace MatlabV5 {
        class FieldNames {
        public:

            static FieldNames
            fromByteQueue(ByteQueue &byteQueue,
                          const ByteParser &byteParser,
                          const TagParser &tagParser,
                          const FieldNameLength& fieldNameLength) {
                Tag tag = tagParser.parseTag(byteQueue);
                if (tag.getType() != DataTypeTable::lookUp(1)) {
                    throw UnexpectedDataTypeException(DataTypeTable::lookUp(1).getSymbol(), tag.getType().getSymbol());
                }

                size_t numberOfFields = tag.getNumberOfBytes()/fieldNameLength.getMaxSize();

                if(tag.getNumberOfBytes() % ByteQueue::BYTE_BLOCK_SIZE!=0) {
                    throw UnexpectedSizeException(ByteQueue::BYTE_BLOCK_SIZE, tag.getNumberOfBytes());
                }
                std::vector<Byte> bytes = byteQueue.popByteBlocks(tag.getNumberOfBytes()/ByteQueue::BYTE_BLOCK_SIZE);

                std::vector<std::string> fieldNames;
                for(size_t i=0; i<tag.getNumberOfBytes(); i+=fieldNameLength.getMaxSize()) {
                    std::string name = byteParser.parseString(
                            std::vector<Byte>(bytes.begin()+i, bytes.begin()+(i+fieldNameLength.getMaxSize())));
                fieldNames.push_back(name);
                }
                return FieldNames(tag, fieldNames);
            }

            FieldNames(const Tag &tag, const std::vector<std::string> &fieldNames) : tag(tag), fieldNames(fieldNames) {}

            const Tag &getTag() const {
                return tag;
            }

            const std::vector<std::string> &getFieldNames() const {
                return fieldNames;
            }


        private:
            Tag tag;
            std::vector<std::string> fieldNames;
        };
    }
}

#endif //COBRAMODELPARSER_MATLABV5_FIELDNAMES_HPP

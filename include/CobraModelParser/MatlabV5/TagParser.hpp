#ifndef COBRAMODELPARSER_MATLABV5_TAGPARSER_HPP
#define COBRAMODELPARSER_MATLABV5_TAGPARSER_HPP

#include "CobraModelParser/ByteParser.hpp"
#include "CobraModelParser/ByteQueue.hpp"
#include "CobraModelParser/MatlabV5/Tag.hpp"
#include "CobraModelParser/MatlabV5/DataTypeTable.hpp"

namespace CobraModelParser {
    namespace MatlabV5 {
        class TagParser {
        public:
            explicit TagParser(const ByteParser& byteParser) : byteParser(byteParser) {}

            Tag parseTag(const std::vector<Byte> &bytes) const {
                if (bytes.size() != TAG_SIZE) {
                    throw UnexpectedSizeException(TAG_SIZE, bytes.size());
                }

                auto numberOfBytes = byteParser.parseNumericType<size_t>(
                        std::vector<Byte>(bytes.begin() + 4, bytes.end()));

                auto dataTypeLookUp = byteParser.parseNumericType<size_t>(
                        std::vector<Byte>(bytes.begin(), bytes.begin() + 4));

                DataType dataType = DataTypeTable::lookUp(dataTypeLookUp);

                return Tag(dataType, numberOfBytes);
            }

            Tag parseTag(ByteQueue &byteQueue) const {
                return parseTag(byteQueue.popByteBlock());
            }

        private:
            static constexpr size_t TAG_SIZE = 8;
            ByteParser byteParser;
        };


    }
}

#endif //COBRAMODELPARSER_MATLABV5_TAGPARSER_HPP

#ifndef COBRAMODELPARSER_MATLABV5_TAGPARSER_HPP
#define COBRAMODELPARSER_MATLABV5_TAGPARSER_HPP

#include "CobraModelParser/ByteParser.hpp"
#include "CobraModelParser/MatlabV5/Tag.hpp"
#include "CobraModelParser/MatlabV5/DataTypeTable.hpp"

namespace CobraModelParser::MatlabV5 {
    class TagParser {
    public:
        TagParser(ByteParser byteParser) : byteParser(byteParser) {}


        Tag parseTag(const std::vector<byte> &bytes) {
            if (bytes.size() != TAG_SIZE) {
                throw UnexpectedSizeException(TAG_SIZE, bytes.size());
            }

            size_t dataTypeLookUp = byteParser.parseNumericType<size_t>(
                    std::vector<byte>(bytes.begin(), bytes.begin() + 4));
            DataType dataType = DataTypeTable::lookUp(dataTypeLookUp);
            size_t numberOfBytes = byteParser.parseNumericType<size_t>(
                    std::vector<byte>(bytes.begin() + 4, bytes.end()));

            return Tag(dataType, numberOfBytes);

        }

    private:
        static constexpr size_t TAG_SIZE = 8;
        ByteParser byteParser;
    };


}

#endif //COBRAMODELPARSER_MATLABV5_TAGPARSER_HPP

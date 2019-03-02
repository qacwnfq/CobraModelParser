#ifndef COBRAMODELPARSER_MATLABV5_BODY_HPP
#define COBRAMODELPARSER_MATLABV5_BODY_HPP

#include <iostream>
#include "CobraModelParser/ByteQueue.hpp"
#include "CobraModelParser/ByteParser.hpp"
#include "CobraModelParser/MatlabV5/DataElement.hpp"
#include "CobraModelParser/MatlabV5/TagParser.hpp"

namespace CobraModelParser::MatlabV5 {
    class Body {
    public:
        Body(ByteQueue &byteQueue, const ByteParser &byteParser) {

            TagParser tagParser(byteParser);

            while (byteQueue.getRemainingBytes() != 0) {
                Tag tag = tagParser.parseTag(byteQueue);
                ByteQueue data(byteQueue.popByteBlocks(tag.getNumberOfBytes() / ByteQueue::BYTE_BLOCK_SIZE));

                dataElements.push_back(DataElement(tag, data));
            }
        }

        const std::vector<DataElement> &getDataElements() const {
            return dataElements;
        }

    private:
        std::vector<DataElement> dataElements;
    };
}

#endif //COBRAMODELPARSER_MATLABV5_BODY_HPP

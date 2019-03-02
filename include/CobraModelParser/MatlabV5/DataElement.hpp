#ifndef COBRAMODELPARSER_MATLABV5_DATAELEMENT_HPP
#define COBRAMODELPARSER_MATLABV5_DATAELEMENT_HPP

#include "CobraModelParser/MatlabV5/Tag.hpp"

namespace CobraModelParser::MatlabV5 {
    class DataElement {
    public:
        DataElement(const Tag &tag, const ByteQueue &data) : tag(tag), data(data) {}

        const Tag &getTag() const {
            return tag;
        }

        const ByteQueue &getData() const {
            return data;
        }


    private:
        Tag tag;
        ByteQueue data;
    };
}

#endif //COBRAMODELPARSER_MATLABV5_DATAELEMENT_HPP

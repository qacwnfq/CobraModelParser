#ifndef COBRAMODELPARSER_MATLABV5DATAELEMENT_HPP
#define COBRAMODELPARSER_MATLABV5DATAELEMENT_HPP

#include <fstream>
#include <ostream>

#include "CobraModelParser/ByteParser.hpp"
#include "CobraModelParser/MatFileV5DataType.hpp"

namespace CobraModelParser {
    class MatlabV5DataElement {
    public:

        static MatlabV5DataElement fromFileStream(std::ifstream &file, std::string endianIndicator) {
            std::vector<char> numberOfBytes;
            std::vector<char> dataTypeLookup;
            file.read(&numberOfBytes[0], numberOfBytesFieldSize);
            file.read(&dataTypeLookup[0], dataTypeFieldSize);

            MatlabV5DataElement matlabV5DataElement(ByteParser::parseSize_t(dataTypeLookup, endianIndicator),
                                                    ByteParser::parseSize_t(numberOfBytes, endianIndicator));
//            file.read()

            return matlabV5DataElement;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        friend std::ostream &operator<<(std::ostream &os, const MatlabV5DataElement &element) {
            os << "dataType: " << element.dataType << " size: " << element.size;
            return os;
        }

    private:
        MatlabV5DataElement(unsigned int typeLookup, size_t dataSize) :
                dataType(MatFileV5DataType::lookUp(typeLookup)), size(dataSize) {};

        MatFileV5DataType dataType;
        size_t size;
        std::vector<char> data;

        static constexpr size_t numberOfBytesFieldSize = 4;
        static constexpr size_t dataTypeFieldSize = 4;


    };

}

#endif //COBRAMODELPARSER_MATLABV5DATAELEMENT_HPP

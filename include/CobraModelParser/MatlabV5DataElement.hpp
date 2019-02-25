#ifndef COBRAMODELPARSER_MATLABV5DATAELEMENT_HPP
#define COBRAMODELPARSER_MATLABV5DATAELEMENT_HPP

#include <fstream>
#include <ostream>

#include "CobraModelParser/ByteParser.hpp"
#include "CobraModelParser/MatlabFileV5DataType.hpp"

namespace CobraModelParser {
    class MatlabV5DataElement {
    public:

        static MatlabV5DataElement fromFileStream(std::ifstream &file, const std::string &endianIndicator) {

            constexpr size_t numberOfBytesFieldSize = 4;
            constexpr size_t dataTypeFieldSize = 4;

            size_t dataTypeLookup = readIntegerFromFileStream(file, dataTypeFieldSize, endianIndicator);
            size_t numberOfBytes = readIntegerFromFileStream(file, numberOfBytesFieldSize, endianIndicator);

            MatlabV5DataElement matlabV5DataElement(dataTypeLookup, numberOfBytes);

            matlabV5DataElement.data = std::vector<char>(matlabV5DataElement.size);
            file.read(&matlabV5DataElement.data[0], matlabV5DataElement.size);

            return matlabV5DataElement;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        friend std::ostream &operator<<(std::ostream &os, const MatlabV5DataElement &element) {
            os << "dataType: " << element.dataType << " size: " << element.size;
            return os;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    private:
        MatlabV5DataElement(size_t typeLookup, size_t dataSize) :
                dataType(MatlabFileV5DataType::lookUp(typeLookup)), size(dataSize) {};

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        static size_t readIntegerFromFileStream(
                std::ifstream &file,
                const size_t &blockSize,
                const std::string &endianIndicator) {
            std::vector<char> byteArray(blockSize);
            file.read(&byteArray[0], blockSize);
            return ByteParser::parse<size_t>(byteArray, endianIndicator);
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        MatlabFileV5DataType dataType;
        size_t size;
        std::vector<char> data;

    };

}

#endif //COBRAMODELPARSER_MATLABV5DATAELEMENT_HPP

#ifndef COBRAMODELPARSER_MATLABV5DATAELEMENT_HPP
#define COBRAMODELPARSER_MATLABV5DATAELEMENT_HPP

#include <fstream>
#include <ostream>

#include "CobraModelParser/ByteParser.hpp"
#include "DataType.hpp"
#include "DataTypeTable.hpp"

namespace CobraModelParser {
    class MatlabV5DataElement {
    public:

        MatlabV5DataElement() {}

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        MatlabV5DataElement(const MatlabV5DataType &dataType, const std::vector<char> &rawData) : dataType(dataType),
                                                                                                  rawData(rawData) {}

        friend std::ostream &operator<<(std::ostream &os, const MatlabV5DataElement &element) {
            os << "dataType: " << element.dataType;
            return os;
        }

        const MatlabV5DataType &getDataType() const {
            return dataType;
        }

        const std::vector<char> &getRawData() const {
            return rawData;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    private:
        MatlabV5DataElement(size_t typeLookup) :
                dataType(MatlabV5DataTypeTable::lookUp(typeLookup)) {}
                
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//        static size_t readIntegerFromFileStream(
//                std::ifstream &file,
//                const size_t &blockSize,
//                const std::string &endianIndicator) {
//            std::vector<char> byteArray(blockSize);
//            file.read(&byteArray[0], blockSize);
//            return ByteParser::parseNumericType<size_t>(byteArray, endianIndicator);
//        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        MatlabV5DataType dataType;
        std::vector<char> rawData;

    };

}

#endif //COBRAMODELPARSER_MATLABV5DATAELEMENT_HPP

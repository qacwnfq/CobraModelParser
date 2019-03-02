#ifndef COBRAMODELPARSER_MATLABV5ARRAYDATATYPEPARSER_HPP
#define COBRAMODELPARSER_MATLABV5ARRAYDATATYPEPARSER_HPP

#include <algorithm>

#include "ArrayType.hpp"
#include "ArrayTypeTable.hpp"
#include "MatlabV5ArrayFlagsElement.hpp"
#include "MatlabV5DataElement.hpp"
#include "DataType.hpp"
#include "MatlabV5ArrayDimensionsElement.hpp"
#include "CobraModelParser/Model.hpp"

namespace CobraModelParser {
    class MatlabV5ArrayDataTypeParser {
    public:
        static Model
        parseModelFromMatlabV5DataElement(const MatlabV5DataElement &matlabV5DataElement,
                                          const std::string &endianIndicator) {

//            assertDataElementIsOfTypeMATLABArray(matlabV5DataElement.getDataType());

//            std::vector<char> data = matlabV5DataElement.getRawData();
//            std::reverse(data.begin(), data.end());
//
//            const MatlabV5ArrayDataSubelement &arrayFlags = parseArrayFlagsElement(data, endianIndicator);
//            const MatlabV5ArrayDimensionsElement &dimensionsElement = parseArrayDimensions(data, endianIndicator);

            Model model;
            return model;
        }


//    private:
//
//
//        static MatlabV5ArrayDimensionsElement
//        parseArrayDimensions(std::vector<char> &data, const std::string &endianIndicator) {
//            MatlabV5ArrayDimensionsElement arrayDimensionsElement;
//
//            const DataType &arrayDimensionsType = parseDataType(data, endianIndicator);
//            arrayDimensionsElement.setType(arrayDimensionsType);
//            std::cout << "dimensions array has type: " << arrayDimensionsType << std::endl;
//
//            size_t dimensionsElementSize = parseElementSize(data, endianIndicator);
//            arrayDimensionsElement.setNumberOfBytes(dimensionsElementSize);
//            std::cout << "dimensions array has totalSize " << dimensionsElementSize << std::endl;
//
//            return arrayDimensionsElement;
//        }
//
//        static std::vector<char>
//        pop4Bytes(std::vector<char> &data, const std::string &endianIndicator) {
//            std::vector<char> byteBlock;
//            for (int i = 0; i < 4; ++i) {
//                byteBlock.push_back(data[data.size() - 1]);
//                data.pop_back();
//            }
//            if (endianIndicator == "IM") {
//                std::reverse(byteBlock.begin(), byteBlock.end());
//            } else if (endianIndicator != "MI") {
//                throw UnknownEndianIndicatorException(endianIndicator);
//            }
//            return byteBlock;
//        }
//
//        static std::vector<char> pop8Bytes(std::vector<char> &data, const std::string &endianIndicator) {
//            std::vector<char> byteBlock;
//            for (int i = 0; i < 8; ++i) {
//                byteBlock.push_back(data[data.size() - 1]);
//                data.pop_back();
//            }
//            if (endianIndicator == "IM") {
//                std::reverse(byteBlock.begin(), byteBlock.end());
//            } else if (endianIndicator != "MI") {
//                throw UnknownEndianIndicatorException(endianIndicator);
//            }
//            return byteBlock;
//        }
//
//        static void popUndefinedBytes(std::vector<char> &data, size_t numberOfBytesToPop) {
//            for(size_t i=0; i<numberOfBytesToPop; ++i) {
//                data.pop_back();
//            }
//        }
//
//        static DataType
//        parseDataType(std::vector<char> &data, const std::string &endianIndicator) {
//            std::vector<char> rawArrayFlagType = pop4Bytes(data, endianIndicator);
//            const DataType &dataType = DataTypeTable::lookUp(
//                    ByteParser::parseNumericType<size_t>(rawArrayFlagType));
//            return dataType;
//        }
//
//        static size_t
//        parseElementSize(std::vector<char> &data, const std::string &endianIndicator) {
//            std::vector<char> rawArrayFlagSize = pop4Bytes(data, endianIndicator);
//            return ByteParser::parseNumericType<size_t>(rawArrayFlagSize);
//        }
//
//        static std::vector<bool> parseArrayFlags(std::vector<char> &data, const std::string &endianIndicator) {
//            std::vector<char> flags = pop4Bytes(data, endianIndicator);
//            flags.pop_back();
//            flags.erase(flags.begin(), flags.begin() + 4);
//            assert(flags.size() == 3);
//            std::vector<bool> results;
//            for (const auto &flag : flags) {
//                results.push_back(flag != 0);
//            }
//            return results;
//        }
//
//        static ArrayType parseArrayClass(std::vector<char> &data, const std::string &endianIndicator) {
////            std::vector<char> rawArrayClass = pop8Bytes(data, endianIndicator);
////            size_t lookUpValue = ByteParser::parseNumericType<size_t>(rawArrayClass);
//            return ArrayTypeTable::lookUp(lookUpValue);
//        }
//
//        static MatlabV5ArrayFlagsElement
//        parseArrayFlagsElement(std::vector<char> &data, const std::string &endianIndicator) {
//            MatlabV5ArrayFlagsElement arrayFlagsElement;
//
//            const DataType &arrayFlagType = parseDataType(data, endianIndicator);
//            if (arrayFlagType != DataTypeTable::lookUp(6)) {
//                throw UnexpectedDataTypeException(DataTypeTable::lookUp(6), arrayFlagType);
//            }
//            arrayFlagsElement.setType(arrayFlagType);
//
//            size_t arrayFlagSize = parseElementSize(data, endianIndicator);
//            if (arrayFlagSize != 8) {
//                throw UnexpectedSizeException(8, arrayFlagSize);
//            }
//            arrayFlagsElement.setNumberOfBytes(arrayFlagSize);
//
//            std::vector<bool> flags = parseArrayFlags(data, endianIndicator);
//            arrayFlagsElement.setComplexFlag(flags[0]);
//            arrayFlagsElement.setGlobalFlag(flags[1]);
//            arrayFlagsElement.setLogicalFlag(flags[2]);
//
//            const ArrayType &arrayDataType = parseArrayClass(data, endianIndicator);
//            arrayFlagsElement.setMatlabV5ArrayDataType(arrayDataType);
//
//            return arrayFlagsElement;
//
//        }
//
//        static void assertDataElementIsOfTypeMATLABArray(const DataType &actualType) {
//            auto expectedType = DataTypeTable::lookUp(14);
//            if (expectedType != actualType) {
//                throw UnexpectedDataTypeException(expectedType, actualType);
//            }
//        }
    };
}

#endif //COBRAMODELPARSER_MATLABV5ARRAYDATATYPEPARSER_HPP

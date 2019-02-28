#ifndef COBRAMODELPARSER_MATLABV5ARRAYDATATYPEPARSER_HPP
#define COBRAMODELPARSER_MATLABV5ARRAYDATATYPEPARSER_HPP

#include <algorithm>

#include "CobraModelParser/MatlabV5ArrayDataSubelement.hpp"
#include "CobraModelParser/MatlabV5ArrayDataType.hpp"
#include "CobraModelParser/MatlabV5ArrayDataTypeTable.hpp"
#include "CobraModelParser/MatlabV5DataElement.hpp"
#include "CobraModelParser/MatlabV5DataType.hpp"
#include "CobraModelParser/Model.hpp"

namespace CobraModelParser {
    class MatlabV5ArrayDataTypeParser {
    public:
        static Model
        parseModelFromMatlabV5DataElement(const MatlabV5DataElement &matlabV5DataElement,
                                          const std::string &endianIndicator) {
            assertDataElementIsOfTypeMATLABArray(matlabV5DataElement.getDataType());

            std::vector<char> data = matlabV5DataElement.getRawData();
            std::reverse(data.begin(), data.end());

            std::vector<MatlabV5ArrayDataSubelement> arrayData;
            const MatlabV5ArrayDataSubelement &arrayFlags = parseArrayFlagsElement(data, endianIndicator);


            Model model;
            return model;
        }


    private:

        static std::vector<char> pop4Bit(std::vector<char> &data) {
            std::vector<char> byteBlock;
            for (int i = 0; i < 4; ++i) {
                byteBlock.push_back(data[data.size() - 1]);
                data.pop_back();
            }
            return byteBlock;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        static std::vector<char> popByte(std::vector<char> &data) {
            std::vector<char> byteBlock;
            for (int i = 0; i < 8; ++i) {
                byteBlock.push_back(data[data.size() - 1]);
                data.pop_back();
            }
            return byteBlock;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////


        static MatlabV5DataType
        parseArrayFlagType(std::vector<char> &data, const std::string &endianIndicator) {
            std::vector<char> rawArrayFlagType = pop4Bit(data);
            const MatlabV5DataType &dataType = MatlabV5DataTypeTable::lookUp(
                    ByteParser::parse<size_t>(rawArrayFlagType, endianIndicator));
            if (dataType != MatlabV5DataTypeTable::lookUp(6)) {
                throw UnexpectedDataTypeException(MatlabV5DataTypeTable::lookUp(6), dataType);
            }
            return dataType;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        static size_t
        parseArrayFlagSize(std::vector<char> &data, const std::string &endianIndicator) {
            std::vector<char> rawArrayFlagSize = pop4Bit(data);
            size_t size = ByteParser::parse<size_t>(rawArrayFlagSize, endianIndicator);
            if (size != 8) {
                throw UnexpectedSizeException(8, size);
            }
            return size;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        static std::vector<bool> parseArrayFlags(std::vector<char> &data, const std::string &endianIndicator) {
            popByte(data);
            popByte(data);
            std::vector<char> flags = popByte(data);
            flags.pop_back();
            flags.erase(flags.begin(), flags.begin() + 4);
            assert(flags.size() == 3);
            std::vector<bool> results;
            if(endianIndicator=="MI") {
               for(const auto& flag : flags) {
                  results.push_back(flag != 0);
               }
            }
            else {
                for(auto reverseIterator = flags.rbegin(); reverseIterator!=flags.rend(); ++reverseIterator) {
                    results.push_back(*reverseIterator != 0);
                }
            }
            return results;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        static MatlabV5ArrayDataType parseArrayClass(std::vector<char> &data, const std::string &endianIndicator) {
            std::vector<char> rawArrayClass = popByte(data);
            popByte(data);
            popByte(data);
            popByte(data);
            popByte(data);
            size_t lookUpValue = ByteParser::parse<size_t>(rawArrayClass, endianIndicator);
            return MatlabV5ArrayDataTypeTable::lookUp(lookUpValue);
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        static MatlabV5ArrayDataSubelement
        parseArrayFlagsElement(std::vector<char> &data, const std::string &endianIndicator) {
            MatlabV5ArrayDataSubelement matlabV5ArrayDataSubelement;

            const MatlabV5DataType &arrayFlagType = parseArrayFlagType(data, endianIndicator);
//            matlabV5ArrayDataSubelement.setMatlabV5ArrayDataType(arrayFlagType);

            size_t arrayFlagSize = parseArrayFlagSize(data, endianIndicator);
            matlabV5ArrayDataSubelement.setNumberOfBytes(arrayFlagSize);

            std::vector<bool> flags = parseArrayFlags(data, endianIndicator);
            matlabV5ArrayDataSubelement.setComplexFlag(flags[0]);
            matlabV5ArrayDataSubelement.setGlobalFlag(flags[1]);
            matlabV5ArrayDataSubelement.setLogicalFlag(flags[2]);

            const MatlabV5ArrayDataType &arrayDataType = parseArrayClass(data, endianIndicator);
            matlabV5ArrayDataSubelement.setMatlabV5ArrayDataType(arrayDataType);


            return matlabV5ArrayDataSubelement;

        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        static void assertDataElementIsOfTypeMATLABArray(const MatlabV5DataType &actualType) {
            auto expectedType = MatlabV5DataTypeTable::lookUp(14);
            if (expectedType != actualType) {
                throw UnexpectedDataTypeException(expectedType, actualType);
            }
        }
    };
}

#endif //COBRAMODELPARSER_MATLABV5ARRAYDATATYPEPARSER_HPP

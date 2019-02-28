#ifndef COBRAMODELPARSER_MATLABV5ARRAYDATATYPEPARSER_HPP
#define COBRAMODELPARSER_MATLABV5ARRAYDATATYPEPARSER_HPP

#include <algorithm>

#include "CobraModelParser/MatlabV5ArrayDataSubelement.hpp"
#include "CobraModelParser/MatlabV5ArrayDataType.hpp"
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
            const MatlabV5ArrayDataSubelement &arrayFlags = parseArrayFlags(data, endianIndicator);


            Model model;
            return model;
        }


    private:

        static std::vector<char> popByteBlock(std::vector<char> &data) {
            std::vector<char> byteBlock;
            for(int i=0; i<4; ++i) {
                byteBlock.push_back(data[data.size()-1]);
                data.pop_back();
            }
            return byteBlock;
        }

        static MatlabV5ArrayDataSubelement
        parseArrayFlags(std::vector<char> &data, const std::string &endianIndicator) {
            MatlabV5ArrayDataSubelement matlabV5ArrayDataSubelement;

            std::vector<char> rawArrayFlagType = popByteBlock(data);
            const MatlabV5DataType &dataType = MatlabV5DataTypeTable::lookUp(ByteParser::parse<size_t>(rawArrayFlagType,
                    endianIndicator));
            if(dataType!=MatlabV5DataTypeTable::lookUp(6)) {
                throw UnexpectedDataTypeException(dataType, MatlabV5DataTypeTable::lookUp(6));
            }




//            size_t arrayFlagTypeLookUp = ByteParser::parse<size_t>(rawArrayType, endianIndicator);
//            const auto &arrayFlagType = MatlabV5DataType::lookUp(arrayFlagTypeLookUp);


//            matlabV5ArrayDataSubelement.setMatlabV5ArrayDataType(arrayDataType);

//            std::vector<char> rawArraySize(data.begin() + 4, data.begin() + 8);
//            size_t size = ByteParser::parse<size_t>(rawArraySize, endianIndicator);

//            matlabV5ArrayDataSubelement.setNumberOfBytes(size);

            return matlabV5ArrayDataSubelement;

        }

        static void assertDataElementIsOfTypeMATLABArray(const MatlabV5DataType &actualType) {
            auto expectedType = MatlabV5DataTypeTable::lookUp(14);
            if (expectedType != actualType) {
                throw UnexpectedDataTypeException(expectedType, actualType);
            }
        }
    };
}

#endif //COBRAMODELPARSER_MATLABV5ARRAYDATATYPEPARSER_HPP

#ifndef COBRAMODELPARSER_MATLABV5ARRAYDATATYPEPARSER_HPP
#define COBRAMODELPARSER_MATLABV5ARRAYDATATYPEPARSER_HPP

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

            std::vector<MatlabV5ArrayDataSubelement> arrayData;
            const MatlabV5ArrayDataSubelement &arrayFlags = parseArrayFlags(data, endianIndicator);


            Model model;
            return model;
        }


    private:

        static MatlabV5ArrayDataSubelement
        parseArrayFlags(std::vector<char> &data, const std::string &endianIndicator) {
            MatlabV5ArrayDataSubelement matlabV5ArrayDataSubelement;

            std::vector<char> rawArrayType(data.begin(), data.begin() + 4);
            size_t arrayFlagTypeLookUp = ByteParser::parse<size_t>(rawArrayType, endianIndicator);
            const auto &arrayFlagType = MatlabV5DataType::lookUp(arrayFlagTypeLookUp);

            if (arrayFlagType != MatlabV5DataType::lookUp(6)) {
                throw UnexpectedDataTypeException(
                        MatlabV5DataType::lookUp(6).getSymbol(), arrayFlagType.getSymbol());
            }

//            matlabV5ArrayDataSubelement.setMatlabV5ArrayDataType(arrayDataType);

            std::vector<char> rawArraySize(data.begin() + 4, data.begin() + 8);
            size_t size = ByteParser::parse<size_t>(rawArraySize, endianIndicator);

            matlabV5ArrayDataSubelement.setNumberOfBytes(size);

            return matlabV5ArrayDataSubelement;

        }

        static void assertDataElementIsOfTypeMATLABArray(const MatlabV5DataType &matlabV5DataType) {
            auto expectedType = MatlabV5DataType::lookUp(14).getSymbol();
            const std::string &actualType = matlabV5DataType.getSymbol();
            std::cout << actualType << ", " << expectedType << std::endl;
            if (expectedType != actualType) {
                throw UnexpectedDataTypeException(expectedType, actualType);
            }
        }
    };
}

#endif //COBRAMODELPARSER_MATLABV5ARRAYDATATYPEPARSER_HPP

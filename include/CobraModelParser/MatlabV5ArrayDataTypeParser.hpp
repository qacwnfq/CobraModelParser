#ifndef COBRAMODELPARSER_MATLABV5ARRAYDATATYPEPARSER_HPP
#define COBRAMODELPARSER_MATLABV5ARRAYDATATYPEPARSER_HPP

#include "CobraModelParser/MatlabV5ArrayDataType.hpp"
#include "CobraModelParser/MatlabV5DataElement.hpp"
#include "CobraModelParser/MatlabV5DataType.hpp"
#include "CobraModelParser/Model.hpp"

namespace CobraModelParser {
    class MatlabV5ArrayDataTypeParser {
    public:
        static Model parseModelFromMatlabV5DataElement(const MatlabV5DataElement &matlabV5DataElement) {
            assertDataElementIsOfTypeMATLABArray(matlabV5DataElement.getDataType());
            Model model;

            return model;
        }


    private:
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

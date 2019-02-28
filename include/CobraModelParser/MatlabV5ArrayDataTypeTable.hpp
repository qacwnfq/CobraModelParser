#ifndef COBRAMODELPARSER_MATLABV5ARRAYDATATYPETABLE_HPP
#define COBRAMODELPARSER_MATLABV5ARRAYDATATYPETABLE_HPP

#include "CobraModelParser/Exceptions.hpp"
#include "CobraModelParser/MatlabV5ArrayDataType.hpp"

namespace CobraModelParser {

    class MatlabV5ArrayDataTypeTable {
    public:
        static MatlabV5ArrayDataType lookUp(unsigned long lookupValue) {
            std::string symbol;
            std::string description;
            switch (lookupValue) {
                case 1:
                    symbol = "mxCELL_CLASS";
                    description = "Cell array";
                    return MatlabV5ArrayDataType(lookupValue, symbol, description);
                case 2:
                    symbol = "mxSTRUCT_CLASS";
                    description = "Structure";
                    return MatlabV5ArrayDataType(lookupValue, symbol, description);
                case 3:
                    symbol = "mxOBJECT_CLASS";
                    description = "Object";
                    return MatlabV5ArrayDataType(lookupValue, symbol, description);
                case 4:
                    symbol = "mxCHAR_CLASS";
                    description = "Character array";
                    return MatlabV5ArrayDataType(lookupValue, symbol, description);
                case 5:
                    symbol = "mxSPARSE_CLASS";
                    description = "Sparse array";
                    return MatlabV5ArrayDataType(lookupValue, symbol, description);
                case 6:
                    symbol = "mxDOUBLE_CLASS";
                    description = "Double precision array";
                    return MatlabV5ArrayDataType(lookupValue, symbol, description);
                case 7:
                    symbol = "mxSINGLE_CLASS";
                    description = "Single precision array";
                    return MatlabV5ArrayDataType(lookupValue, symbol, description);
                case 8:
                    symbol = "mxINT8_CLASS";
                    description = "8-bit, signed integer";
                    return MatlabV5ArrayDataType(lookupValue, symbol, description);
                case 9:
                    symbol = "mxUINT8_CLASS";
                    description = "8-bit, unsigned integer";
                    return MatlabV5ArrayDataType(lookupValue, symbol, description);
                case 10:
                    symbol = "mxINT16_CLASS";
                    description = "16-bit, signed integer";
                    return MatlabV5ArrayDataType(lookupValue, symbol, description);
                case 11:
                    symbol = "mxUINT16_CLASS";
                    description = "16-bit, unsigned integer";
                    return MatlabV5ArrayDataType(lookupValue, symbol, description);
                case 12:
                    symbol = "mxINT32_CLASS";
                    description = "32-bit, signed integer";
                    return MatlabV5ArrayDataType(lookupValue, symbol, description);
                case 13:
                    symbol = "mxUINT32_CLASS";
                    description = "32-bit, unsigned integer";
                    return MatlabV5ArrayDataType(lookupValue, symbol, description);
                case 14:
                    symbol = "mxINT64_CLASS";
                    description = "33-bit, signed integer";
                    return MatlabV5ArrayDataType(lookupValue, symbol, description);
                case 15:
                    symbol = "mxUINT64_CLASS";
                    description = "64-bit, unsigned integer";
                    return MatlabV5ArrayDataType(lookupValue, symbol, description);
                default:
                    throw UnknownDataTypeException(lookupValue);
            }
        }
    };
}

#endif //COBRAMODELPARSER_MATLABV5ARRAYDATATYPETABLE_HPP

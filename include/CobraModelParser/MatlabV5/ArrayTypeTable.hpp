#ifndef COBRAMODELPARSER_MATLABV5_ARRAYTYPETABLE_HPP
#define COBRAMODELPARSER_MATLABV5_ARRAYTYPETABLE_HPP

#include "CobraModelParser/Exceptions.hpp"
#include "CobraModelParser/MatlabV5/ArrayType.hpp"

namespace CobraModelParser {
    namespace MatlabV5 {
        class ArrayTypeTable {
        public:
            static ArrayType lookUp(unsigned long lookupValue) {
                std::string symbol;
                std::string description;
                switch (lookupValue) {
                    case 1:
                        symbol = "mxCELL_CLASS";
                        description = "Cell array";
                        return ArrayType(lookupValue, symbol, description);
                    case 2:
                        symbol = "mxSTRUCT_CLASS";
                        description = "Structure";
                        return ArrayType(lookupValue, symbol, description);
                    case 3:
                        symbol = "mxOBJECT_CLASS";
                        description = "Object";
                        return ArrayType(lookupValue, symbol, description);
                    case 4:
                        symbol = "mxCHAR_CLASS";
                        description = "Character array";
                        return ArrayType(lookupValue, symbol, description);
                    case 5:
                        symbol = "mxSPARSE_CLASS";
                        description = "Sparse array";
                        return ArrayType(lookupValue, symbol, description);
                    case 6:
                        symbol = "mxDOUBLE_CLASS";
                        description = "Double precision array";
                        return ArrayType(lookupValue, symbol, description);
                    case 7:
                        symbol = "mxSINGLE_CLASS";
                        description = "Single precision array";
                        return ArrayType(lookupValue, symbol, description);
                    case 8:
                        symbol = "mxINT8_CLASS";
                        description = "8-bit, signed integer";
                        return ArrayType(lookupValue, symbol, description);
                    case 9:
                        symbol = "mxUINT8_CLASS";
                        description = "8-bit, unsigned integer";
                        return ArrayType(lookupValue, symbol, description);
                    case 10:
                        symbol = "mxINT16_CLASS";
                        description = "16-bit, signed integer";
                        return ArrayType(lookupValue, symbol, description);
                    case 11:
                        symbol = "mxUINT16_CLASS";
                        description = "16-bit, unsigned integer";
                        return ArrayType(lookupValue, symbol, description);
                    case 12:
                        symbol = "mxINT32_CLASS";
                        description = "32-bit, signed integer";
                        return ArrayType(lookupValue, symbol, description);
                    case 13:
                        symbol = "mxUINT32_CLASS";
                        description = "32-bit, unsigned integer";
                        return ArrayType(lookupValue, symbol, description);
                    case 14:
                        symbol = "mxINT64_CLASS";
                        description = "33-bit, signed integer";
                        return ArrayType(lookupValue, symbol, description);
                    case 15:
                        symbol = "mxUINT64_CLASS";
                        description = "64-bit, unsigned integer";
                        return ArrayType(lookupValue, symbol, description);
                    default:
                        throw UnknownDataTypeException(lookupValue);
                }
            }
        };
    }
}

#endif //COBRAMODELPARSER_MATLABV5_ARRAYTYPETABLE_HPP

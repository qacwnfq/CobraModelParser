#ifndef COBRAMODELPARSER_MATLABV5_DATATYPETABLE_HPP
#define COBRAMODELPARSER_MATLABV5_DATATYPETABLE_HPP

#include "DataType.hpp"
#include "CobraModelParser/Exceptions.hpp"

namespace CobraModelParser {
    namespace MatlabV5 {
        class DataTypeTable {
        public:
            static DataType lookUp(size_t lookupValue) {
                std::string symbol;
                std::string description;
                switch (lookupValue) {
                    case 0:
                        symbol = "EMPTY";
                        description = "Empty Data Type";
                        return DataType(lookupValue, symbol, description);
                    case 1:
                        symbol = "miINT8";
                        description = "8-bit, signed";
                        return DataType(lookupValue, symbol, description);
                    case 2:
                        symbol = "miUINT8";
                        description = "8-bit, unsigned";
                        return DataType(lookupValue, symbol, description);
                    case 3:
                        symbol = "miINT16";
                        description = "16-bit, signed";
                        return DataType(lookupValue, symbol, description);
                    case 4:
                        symbol = "miUINT16";
                        description = "16-bit, unsigned";
                        return DataType(lookupValue, symbol, description);
                    case 5:
                        symbol = "miINT32";
                        description = "32-bit, signed";
                        return DataType(lookupValue, symbol, description);
                    case 6:
                        symbol = "miUINT32";
                        description = "32-bit, unsigned";
                        return DataType(lookupValue, symbol, description);
                    case 7:
                        symbol = "miSINGLE";
                        description = "IEEE 754 single format";
                        return DataType(lookupValue, symbol, description);
                    case 8:
                        symbol = "--";
                        description = "Reserved";
                        throw ReservedDataTypeException();
                    case 9:
                        symbol = "miDOUBLE";
                        description = "IEEE 754 double format";
                        return DataType(lookupValue, symbol, description);
                    case 10:
                        symbol = "--";
                        description = "Reserved";
                        throw ReservedDataTypeException();
                    case 11:
                        symbol = "--";
                        description = "Reserved";
                        throw ReservedDataTypeException();
                    case 12:
                        symbol = "miINT64";
                        description = "64-bit, signed";
                        return DataType(lookupValue, symbol, description);
                    case 13:
                        symbol = "miUINT64";
                        description = "64-bit, unsigned";
                        return DataType(lookupValue, symbol, description);
                    case 14:
                        symbol = "miMATRIX";
                        description = "MATLAB array";
                        return DataType(lookupValue, symbol, description);
                    case 15:
                        symbol = "miCOMPRESSED";
                        description = "Compressed Data";
                        break;
                    case 16:
                        symbol = "miUTF8";
                        description = "Unicode UTF-8 Encoded Character Data";
                        break;
                    case 17:
                        symbol = "miUTF16";
                        description = "Unicode UTF-16 Encoded Character Data";
                        return DataType(lookupValue, symbol, description);
                    case 18:
                        symbol = "miUTF32";
                        description = "Unicode UTF-32 Encoded Character Data";
                        return DataType(lookupValue, symbol, description);
                    default:
                        throw UnknownDataTypeException(lookupValue);
                }
            }
        };
    }
}

#endif //COBRAMODELPARSER_MATLABV5_DATATYPETABLE_HPP

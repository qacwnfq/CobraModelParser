#ifndef COBRAMODELPARSER_MATFILEV5DATATYPES_HPP
#define COBRAMODELPARSER_MATFILEV5DATATYPES_HPP

#include <string>
#include <ostream>

#include "CobraModelParser/Exceptions.hpp"

namespace CobraModelParser {
    class MatFileV5DataType {
    public:

        static MatFileV5DataType lookUp(size_t lookupValue) {
            MatFileV5DataType matFileV5DataType;
            matFileV5DataType.value = lookupValue;
            std::cout << "lookup: " << lookupValue << std::endl;
            switch (lookupValue) {
                case 1:
                    matFileV5DataType.symbol = "miINT8";
                    matFileV5DataType.description = "8-bit, signed";
                    return matFileV5DataType;
                case 2:
                    matFileV5DataType.symbol = "miUINT8";
                    matFileV5DataType.description = "8-bit, unsigned";
                    return matFileV5DataType;
                case 3:
                    matFileV5DataType.symbol = "miINT16";
                    matFileV5DataType.description = "16-bit, signed";
                    return matFileV5DataType;
                case 4:
                    matFileV5DataType.symbol = "miUINT16";
                    matFileV5DataType.description = "16-bit, unsigned";
                    return matFileV5DataType;
                case 5:
                    matFileV5DataType.symbol = "miINT32";
                    matFileV5DataType.description = "32-bit, signed";
                    return matFileV5DataType;
                case 6:
                    matFileV5DataType.symbol = "miUINT32";
                    matFileV5DataType.description = "32-bit, unsigned";
                    return matFileV5DataType;
                case 7:
                    matFileV5DataType.symbol = "miSINGLE";
                    matFileV5DataType.description = "IEEE 754 single format";
                    return matFileV5DataType;
                case 8:
                    matFileV5DataType.symbol = "--";
                    matFileV5DataType.description = "Reserved";
                    throw ReservedDataTypeException();
                case 9:
                    matFileV5DataType.symbol = "miDOUBLE";
                    matFileV5DataType.description = "IEEE 754 double format";
                    return matFileV5DataType;
                case 10:
                    matFileV5DataType.symbol = "--";
                    matFileV5DataType.description = "Reserved";
                    throw ReservedDataTypeException();
                case 11:
                    matFileV5DataType.symbol = "--";
                    matFileV5DataType.description = "Reserved";
                    throw ReservedDataTypeException();
                case 12:
                    matFileV5DataType.symbol = "miINT64";
                    matFileV5DataType.description = "64-bit, signed";
                    return matFileV5DataType;
                case 13:
                    matFileV5DataType.symbol = "miUINT64";
                    matFileV5DataType.description = "64-bit, unsigned";
                    return matFileV5DataType;
                case 14:
                    matFileV5DataType.symbol = "miMATRIX";
                    matFileV5DataType.description = "MATLAB array";
                    return matFileV5DataType;
                case 15:
                    matFileV5DataType.symbol = "miCOMPRESSED";
                    matFileV5DataType.description = "Compressed Data";
                    break;
                case 16:
                    matFileV5DataType.symbol = "miUTF8";
                    matFileV5DataType.description = "Unicode UTF-8 Encoded Character Data";
                    break;
                case 17:
                    matFileV5DataType.symbol = "miUTF16";
                    matFileV5DataType.description = "Unicode UTF-16 Encoded Character Data";
                    return matFileV5DataType;
                case 18:
                    matFileV5DataType.symbol = "miUTF32";
                    matFileV5DataType.description = "Unicode UTF-32 Encoded Character Data";
                    return matFileV5DataType;
                default:
                    throw UnknownDataTypeException(lookupValue);
            }

        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        unsigned int getValue() const {
            return value;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        const std::string &getSymbol() const {
            return symbol;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        const std::string &getDescription() const {
            return description;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        friend std::ostream &operator<<(std::ostream &os, const MatFileV5DataType &type) {
            os << "value: " << type.value << " symbol: " << type.symbol << " description: " << type.description;
            return os;
        }


    private:
        MatFileV5DataType() {};

        size_t value;
        std::string symbol;
        std::string description;

    };
}

#endif //COBRAMODELPARSER_MATFILEV5DATATYPES_HPP

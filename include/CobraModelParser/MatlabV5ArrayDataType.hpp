#ifndef COBRAMODELPARSER_MATLABV5ARRAYDATATYPE_HPP
#define COBRAMODELPARSER_MATLABV5ARRAYDATATYPE_HPP

#include <fstream>
#include <ostream>

#include "CobraModelParser/ByteParser.hpp"
#include "CobraModelParser/MatlabFileV5DataType.hpp"

namespace CobraModelParser {
    class MatlabV5ArrayDataType {
    public:
        static MatlabV5ArrayDataType lookup(size_t lookupValue) {
            MatlabV5ArrayDataType matlabV5ArrayDataType;
            matlabV5ArrayDataType.value = lookupValue;
            switch (lookupValue) {
                case 1:
                    matlabV5ArrayDataType.symbol = "mxCELL_CLASS";
                    matlabV5ArrayDataType.description = "Cell array";
                    return matlabV5ArrayDataType;
                case 2:
                    matlabV5ArrayDataType.symbol = "mxSTRUCT_CLASS";
                    matlabV5ArrayDataType.description = "Structure";
                    return matlabV5ArrayDataType;
                case 3:
                    matlabV5ArrayDataType.symbol = "mxOBJECT_CLASS";
                    matlabV5ArrayDataType.description = "Object";
                    return matlabV5ArrayDataType;
                case 4:
                    matlabV5ArrayDataType.symbol = "mxCHAR_CLASS";
                    matlabV5ArrayDataType.description = "Character array";
                    return matlabV5ArrayDataType;
                case 5:
                    matlabV5ArrayDataType.symbol = "mxSPARSE_CLASS";
                    matlabV5ArrayDataType.description = "Sparse array";
                    return matlabV5ArrayDataType;
                case 6:
                    matlabV5ArrayDataType.symbol = "mxDOUBLE_CLASS";
                    matlabV5ArrayDataType.description = "Double precision array";
                    return matlabV5ArrayDataType;
                case 7:
                    matlabV5ArrayDataType.symbol = "mxSINGLE_CLASS";
                    matlabV5ArrayDataType.description = "Single precision array";
                    return matlabV5ArrayDataType;
                case 8:
                    matlabV5ArrayDataType.symbol = "mxINT8_CLASS";
                    matlabV5ArrayDataType.description = "8-bit, signed integer";
                    return matlabV5ArrayDataType;
                case 9:
                    matlabV5ArrayDataType.symbol = "mxUINT8_CLASS";
                    matlabV5ArrayDataType.description = "8-bit, unsigned integer";
                    return matlabV5ArrayDataType;
                case 10:
                    matlabV5ArrayDataType.symbol = "mxINT16_CLASS";
                    matlabV5ArrayDataType.description = "16-bit, signed integer";
                    return matlabV5ArrayDataType;
                case 11:
                    matlabV5ArrayDataType.symbol = "mxUINT16_CLASS";
                    matlabV5ArrayDataType.description = "16-bit, unsigned integer";
                    return matlabV5ArrayDataType;
                case 12:
                    matlabV5ArrayDataType.symbol = "mxINT32_CLASS";
                    matlabV5ArrayDataType.description = "32-bit, signed integer";
                    return matlabV5ArrayDataType;
                case 13:
                    matlabV5ArrayDataType.symbol = "mxUINT32_CLASS";
                    matlabV5ArrayDataType.description = "32-bit, unsigned integer";
                    return matlabV5ArrayDataType;
                default:
                    throw UnknownDataTypeException(lookupValue);
            }
        }

        size_t getValue() const {
            return value;
        }

        const std::string &getSymbol() const {
            return symbol;
        }

        const std::string &getDescription() const {
            return description;
        }

        friend std::ostream &operator<<(std::ostream &os, const MatlabV5ArrayDataType &type) {
            os << "value: " << type.value << " symbol: " << type.symbol << " description: " << type.description;
            return os;
        }

    private:
        MatlabV5ArrayDataType() {};

        size_t value;
        std::string symbol;
        std::string description;

    };

}

#endif //COBRAMODELPARSER_MATLABV5ARRAYDATAELEMENT_HPP

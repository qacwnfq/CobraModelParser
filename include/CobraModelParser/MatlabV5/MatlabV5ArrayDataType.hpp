#ifndef COBRAMODELPARSER_MATLABV5ARRAYDATATYPE_HPP
#define COBRAMODELPARSER_MATLABV5ARRAYDATATYPE_HPP

#include <fstream>
#include <ostream>

namespace CobraModelParser {
    class MatlabV5ArrayDataType {
    public:
        MatlabV5ArrayDataType() {}

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        MatlabV5ArrayDataType(size_t value,
                              const std::string &symbol,
                              const std::string &description) : value(value), symbol(symbol),
                                                                description(description) {}

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        size_t getValue() const {
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

        friend std::ostream &operator<<(std::ostream &os, const MatlabV5ArrayDataType &type) {
            os << "value: " << type.value << " symbol: " << type.symbol << " description: " << type.description;
            return os;
        }

    private:
        size_t value;
        std::string symbol;
        std::string description;

    };

}

#endif //COBRAMODELPARSER_MATLABV5ARRAYDATAELEMENT_HPP

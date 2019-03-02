#ifndef COBRAMODELPARSER_MATFILEV5_DATATYPES_HPP
#define COBRAMODELPARSER_MATFILEV5_DATATYPES_HPP

#include <string>
#include <ostream>

namespace CobraModelParser {
    namespace MatlabV5{
            class DataType {
                public:
                DataType()
                {}

                DataType(
                        size_t
                value,
                const std::string &symbol,
                const std::string &description) : value(value), symbol(symbol), description(description)
                {}

                unsigned int getValue() const {
                    return value;
                }

                const std::string &getSymbol() const {
                    return symbol;
                }

                const std::string &getDescription() const {
                    return description;
                }

                friend std::ostream &operator<<(std::ostream &os, const DataType &type) {
                    os << "value: " << type.value << " symbol: " << type.symbol << " description: " << type.description;
                    return os;
                }

                bool operator==(const DataType &rhs) const {
                    return value == rhs.value &&
                           symbol == rhs.symbol &&
                           description == rhs.description;
                }

                bool operator!=(const DataType &rhs) const {
                    return !(rhs == *this);
                }

                private:

                size_t value;
                std::string symbol;
                std::string description;

            };
    }
}

#endif //COBRAMODELPARSER_MATFILEV5_DATATYPES_HPP

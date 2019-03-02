#ifndef COBRAMODELPARSER_MATLABV5ARRAYDATASUBELEMENT_HPP
#define COBRAMODELPARSER_MATLABV5ARRAYDATASUBELEMENT_HPP

#include <ostream>
#include "MatlabV5ArrayDataType.hpp"
#include "MatlabV5DataType.hpp"

namespace CobraModelParser {
    class MatlabV5ArrayDataSubelement {
    public:
        size_t getNumberOfBytes() const {
            return numberOfBytes;
        }

        void setNumberOfBytes(size_t numberOfBytes) {
            MatlabV5ArrayDataSubelement::numberOfBytes = numberOfBytes;
        }

        const MatlabV5DataType &getType() const {
            return type;
        }

        void setType(const MatlabV5DataType &type) {
            MatlabV5ArrayDataSubelement::type = type;
        }

        friend std::ostream &operator<<(std::ostream &os, const MatlabV5ArrayDataSubelement &subelement) {
            os << "numberOfBytes: " << subelement.numberOfBytes << " type: " << subelement.type;
            return os;
        }

    private:
        std::size_t numberOfBytes;
        MatlabV5DataType type;

    };
}

#endif //COBRAMODELPARSER_MATLABV5ARRAYDATASUBELEMENT_HPP

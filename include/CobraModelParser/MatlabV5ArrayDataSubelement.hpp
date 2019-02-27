#ifndef COBRAMODELPARSER_MATLABV5ARRAYDATASUBELEMENT_HPP
#define COBRAMODELPARSER_MATLABV5ARRAYDATASUBELEMENT_HPP

#include "CobraModelParser/MatlabV5ArrayDataType.hpp"

namespace CobraModelParser {
    class MatlabV5ArrayDataSubelement {
    public:
        const MatlabV5ArrayDataType &getMatlabV5ArrayDataType() const {
            return matlabV5ArrayDataType;
        }

        size_t getNumberOfBytes() const {
            return numberOfBytes;
        }

        void setNumberOfBytes(size_t numberOfBytes) {
            MatlabV5ArrayDataSubelement::numberOfBytes = numberOfBytes;
        }

        const std::vector<char> &getData() const {
            return data;
        }

        void setData(const std::vector<char> &data) {
            MatlabV5ArrayDataSubelement::data = data;
        }

        void setMatlabV5ArrayDataType(const MatlabV5ArrayDataType &matlabV5ArrayDataType) {
            MatlabV5ArrayDataSubelement::matlabV5ArrayDataType = matlabV5ArrayDataType;
        }

    private:
        MatlabV5ArrayDataType matlabV5ArrayDataType;

        std::size_t numberOfBytes;
        std::vector<char> data;
    };
}

#endif //COBRAMODELPARSER_MATLABV5ARRAYDATASUBELEMENT_HPP

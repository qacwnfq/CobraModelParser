#ifndef COBRAMODELPARSER_MATLABV5ARRAYFLAGSELEMENT_HPP
#define COBRAMODELPARSER_MATLABV5ARRAYFLAGSELEMENT_HPP

#include <ostream>
#include "MatlabV5ArrayDataSubelement.hpp"

namespace CobraModelParser {
    class MatlabV5ArrayFlagsElement : public MatlabV5ArrayDataSubelement {
    public:
        const MatlabV5ArrayDataType &getMatlabV5ArrayDataType() const {
            return matlabV5ArrayDataType;
        }

        void setMatlabV5ArrayDataType(const MatlabV5ArrayDataType &matlabV5ArrayDataType) {
            MatlabV5ArrayFlagsElement::matlabV5ArrayDataType = matlabV5ArrayDataType;
        }

        bool isComplexFlag() const {
            return complexFlag;
        }

        void setComplexFlag(bool complexFlag) {
            MatlabV5ArrayFlagsElement::complexFlag = complexFlag;
        }

        bool isGlobalFlag() const {
            return globalFlag;
        }

        void setGlobalFlag(bool globalFlag) {
            MatlabV5ArrayFlagsElement::globalFlag = globalFlag;
        }

        bool isLogicalFlag() const {
            return logicalFlag;
        }

        void setLogicalFlag(bool logicalFlag) {
            MatlabV5ArrayFlagsElement::logicalFlag = logicalFlag;
        }

        friend std::ostream &operator<<(std::ostream &os, const MatlabV5ArrayFlagsElement &element) {
            os << static_cast<const MatlabV5ArrayDataSubelement &>(element) << " matlabV5ArrayDataType: "
               << element.matlabV5ArrayDataType << " complexFlag: " << element.complexFlag << " globalFlag: "
               << element.globalFlag << " logicalFlag: " << element.logicalFlag;
            return os;
        }

    private:
        MatlabV5ArrayDataType matlabV5ArrayDataType;
        bool complexFlag;
        bool globalFlag;
        bool logicalFlag;
    };
}

#endif //COBRAMODELPARSER_MATLABV5ARRAYFLAGSELEMENT_HPP

#ifndef COBRAMODELPARSER_MATLABV5_TAGBUILDER_HPP
#define COBRAMODELPARSER_MATLABV5_TAGBUILDER_HPP

namespace CobraModelParser::MatlabV5 {
    class TagBuilder {


//        setBytes(std::vector<byte> )

        if(bytes.size() != TAG_SIZE) {
            throw UnexpectedSizeException(TAG_SIZE, bytes.size());
        }
    private:
        static constexpr size_t TAG_SIZE = 8;
    };

}

#endif //COBRAMODELPARSER_MATLABV5_TAGBUILDER_HPP

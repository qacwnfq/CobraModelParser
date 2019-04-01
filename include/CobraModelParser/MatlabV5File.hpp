#include <utility>

#ifndef COBRAMODELPARSER_MATLABV5FILE_HPP
#define COBRAMODELPARSER_MATLABV5FILE_HPP

#include "DataElementNode.hpp"
#include "Header.hpp"

namespace CobraModelParser {
    class MatlabV5File {
    public:
        MatlabV5File(const Header &header,
                     const DataElementNode &body,
                     const std::string &fileName) : header(header),
                                                    body(body),
                                                    fileName(fileName) {}

        const Header &getHeader() const {
            return header;
        }

        const DataElementNode &getBody() const {
            return body;
        }

        const std::string &getFileName() const {
            return fileName;
        }

    private:
        Header header;
        DataElementNode body;
        std::string fileName;
    };
}

#endif //COBRAMODELPARSER_MATLABV5FILE_HPP

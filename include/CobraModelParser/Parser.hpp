#ifndef COBRAMODELPARSER_PARSER_HPP
#define COBRAMODELPARSER_PARSER_HPP

#include <fstream>
#include <string>

#include "CobraModelParser/Exceptions.hpp"
#include "CobraModelParser/Model.hpp"

namespace CobraModelParser {

    class Parser {
    public:
        virtual Model parseModelFromFile(std::string filename) = 0;

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        void checkFileExists(std::string filename) const {
            std::ifstream file(filename, std::ios::binary | std::ios::in);
            bool fileExists = !!file;
            file.close();
            if (!fileExists) {
                throw FileNotFoundException(filename);
            }
        }

    };

}


#endif //MATLAB2EIGEN_PARSER_HPP

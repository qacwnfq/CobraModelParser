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
    };

}


#endif //MATLAB2EIGEN_PARSER_HPP

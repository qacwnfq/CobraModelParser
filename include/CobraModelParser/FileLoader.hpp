#ifndef COBRAMODELPARSER_FILELOADER_HPP
#define COBRAMODELPARSER_FILELOADER_HPP

#include <fstream>
#include <iostream>

#include "CobraModelParser/ByteQueue.hpp"

namespace CobraModelParser {
    class FileLoader { ;
    public:

        FileLoader() = delete;

        static ByteQueue loadFileContentsAsByteQueue(const std::string &file) {
            checkFileExists(file);
            std::ifstream filestream(file, std::ios::binary | std::ios::in);
            std::vector<byte> contents((std::istreambuf_iterator<char>(filestream)),
                                       (std::istreambuf_iterator<char>()));
            return ByteQueue(contents);
        }

    private:

        void static checkFileExists(const std::string &filename) {
            std::ifstream file(filename);
            bool fileExists = !!file;
            file.close();
            if (!fileExists) {
                throw FileNotFoundException(filename);
            }
        }
    };
}

#endif //COBRAMODELPARSER_FILELOADER_HPP

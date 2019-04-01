#ifndef COBRAMODELPARSER_FILELOADER_HPP
#define COBRAMODELPARSER_FILELOADER_HPP

#include <algorithm>
#include "Byte.hpp"
#include "ByteQueue.hpp"
#include <deque>
#include <fstream>
#include <iostream>
#include <vector>
#include "Exceptions.hpp"

namespace CobraModelParser {
    class FileLoader { ;
    public:

        FileLoader() = delete;

        static ByteQueue loadFileContents(const std::string &file) {
            checkFileExists(file);
            std::ifstream fileStream(file, std::ios::binary | std::ios::in);
            std::vector<Byte> contents((std::istreambuf_iterator<char>(fileStream)),
                                       (std::istreambuf_iterator<char>()));
            std::deque<Byte> result(contents.size());
            std::move(contents.begin(), contents.end(), result.begin());

            return ByteQueue(result);
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

#ifndef MATLAB2EIGEN_MATLAB2EIGEN_HPP
#define MATLAB2EIGEN_MATLAB2EIGEN_HPP

#include <exception>

#include <fstream>
#include <string>

int getMatlabfileVersion() {

}

void matlab2Eigen(std::string matlabfile) {
    std::ifstream file(matlabfile, std::ios::binary | std::ios::in);
    if(!file) {
        std::cerr << "error opening file" << std::endl;
        throw std::exception();
    }

    char header[116];
    file.read(reinterpret_cast<char*>(header), 116);
    std::cout << header << std::endl;
}


void matlab2EigenV5(std::string matlabfile);

void matlab2EigenV4(std::string matlabfile);

#endif //MATLAB2EIGEN_MATLAB2EIGEN_HPP

#ifndef COBRAMODELPARSER_MATLABV5_POLYTOPEPARSER_HPP
#define COBRAMODELPARSER_MATLABV5_POLYTOPEPARSER_HPP

#include <Eigen/Core>

#include "Fields.hpp"

namespace CobraModelParser {
    namespace MatlabV5 {
        class PolytopeParser {
        public:
            static std::pair<Eigen::MatrixXd, Eigen::VectorXd> fromFields(const Fields &fields,
                                                                          const ByteParser &byteParser,
                                                                          const TagParser &tagParser) {
                const std::map<std::string, Field> &map = fields.getFields();
                Field S = map.find("S")->second;
                Field b = map.find("b")->second;
                Field ub = map.find("ub")->second;
                Field lb = map.find("lb")->second;

                std::cout << "S: " << S.getTag() << std::endl;
                std::cout << "b: " << b.getTag() << std::endl;
                std::cout << "ub: " << ub.getTag() << std::endl;
                std::cout << "lb: " << lb.getTag() << std::endl;

                const ArrayDimensions &dimensions = S.getArrayDimensions();
                std::cout << "Sflags: " << S.getArrayFlags() << std::endl;
                auto SData = ByteQueue(S.getData());
                std::cout << "dims" << dimensions.getDimensionSizes()[0] << ", " << dimensions.getDimensionSizes()[1]
                          << std::endl;
                Tag SArraytag = tagParser.parseTag(SData);
                std::cout << "s size: " << SData.getRemainingBytes() << ", expected: "
                          << dimensions.getDimensionSizes()[0] * dimensions.getDimensionSizes()[1] * 8 << std::endl;

                std::vector<double> Scomponents;
                while(SData.getRemainingBytes() != 0) {
//                   SComponents.push_back()
                }


                Eigen::MatrixXd Aresult;
                Eigen::VectorXd bresult;
                return std::make_pair(Aresult, bresult);
            }
        };
    }
}

#endif //COBRAMODELPARSER_MATLABV5_POLYTOPEPARSER_HPP

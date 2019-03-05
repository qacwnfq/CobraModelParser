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

                Eigen::MatrixXd SMatrix = matrixFromField(S, byteParser, tagParser);
                Eigen::VectorXd bVector = vectorFromField(b, byteParser, tagParser);
                Eigen::VectorXd ubVector = vectorFromField(ub, byteParser, tagParser);
                Eigen::VectorXd lbVector = vectorFromField(lb, byteParser, tagParser);

                Eigen::MatrixXd Aresult((2 * SMatrix.rows() + 2 * SMatrix.cols()), SMatrix.cols());
                Aresult << SMatrix, -SMatrix, -Eigen::MatrixXd::Identity(SMatrix.cols(), SMatrix.cols()),
                        Eigen::MatrixXd::Identity(SMatrix.cols(), SMatrix.cols());
                Eigen::VectorXd bresult((2 * bVector.rows() + lbVector.rows() + ubVector.rows()));
                bresult << bVector, -bVector, -lbVector, ubVector;
                return std::make_pair(Aresult, bresult);
            }

            static Eigen::MatrixXd matrixFromField(const Field &field, const ByteParser &byteParser,
                                                   const TagParser &tagParser) {
                const ArrayDimensions &dimensions = field.getArrayDimensions();
                assert(dimensions.getDimensionSizes().size() == 2);
                auto data = ByteQueue(field.getData());

                Tag tag = tagParser.parseTag(data);
                assert(data.getRemainingBytes() ==
                       dimensions.getDimensionSizes()[0] * dimensions.getDimensionSizes()[1] *
                       tag.getType().getSize());

                std::vector<double> components;
                while (data.getRemainingBytes() != 0) {
                    components.push_back(byteParser.parseDouble(data.popByteBlock()));
                }

                Eigen::MatrixXd matrix(dimensions.getDimensionSizes()[0], dimensions.getDimensionSizes()[1]);
                for (size_t x = 0; x < matrix.rows(); ++x) {
                    for (size_t y = 0; y < matrix.cols(); ++y) {
                        matrix(x, y) = components[y * matrix.rows() + x];
                    }
                }
                return matrix;
            }

            static Eigen::VectorXd vectorFromField(const Field &field, const ByteParser &
            byteParser, const TagParser &tagParser) {
                const ArrayDimensions &dimensions = field.getArrayDimensions();
                auto data = ByteQueue(field.getData());

                assert(dimensions.getDimensionSizes()[1] == 1);

                Tag tag = tagParser.parseTag(data);
                assert(data.getRemainingBytes() ==
                       dimensions.getDimensionSizes()[0] * dimensions.getDimensionSizes()[1] *
                       tag.getType().getSize());

                std::vector<double> components;
                while (data.getRemainingBytes() != 0) {
                    components.push_back(byteParser.parseDouble(data.popByteBlock()));
                }

                Eigen::VectorXd v(dimensions.getDimensionSizes()[0]);
                for (size_t x = 0; x < v.rows(); ++x) {
                    v(x) = components[x];
                }
                return v;
            }
        };
    }
}

#endif //COBRAMODELPARSER_MATLABV5_POLYTOPEPARSER_HPP

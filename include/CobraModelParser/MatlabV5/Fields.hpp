#include <utility>

#ifndef COBRAMODELPARSER_MATLABV5_FIELDS_HPP
#define COBRAMODELPARSER_MATLABV5_FIELDS_HPP

#include <map>

#include <CobraModelParser/ByteQueue.hpp>
#include "TagParser.hpp"
#include "FieldNames.hpp"
#include "Field.hpp"


namespace CobraModelParser {
    namespace MatlabV5 {
        class Fields {
        public:
            static Fields
            fromByteQueue(
                    ByteQueue &byteQueue,
                    const ByteParser &byteParser,
                    const TagParser &tagParser,
                    const FieldNames &fieldNames) {
                std::map<std::string, Field> fields;
                for(const auto& name: fieldNames.getFieldNames()) {
                    fields[name] = Field::fromByteQueue(
                            byteQueue,
                            byteParser,
                            tagParser,
                            name );
                }

                return Fields(fields);
            }

            const std::map<std::string, Field> &getFields() const {
                return fields;
            }

            Fields(std::map<std::string, Field> fields) : fields(std::move(fields)) {}

        private:
            std::map<std::string, Field> fields;

        };
    }
}

#endif //COBRAMODELPARSER_MATLABV5_FIELDS_HPP

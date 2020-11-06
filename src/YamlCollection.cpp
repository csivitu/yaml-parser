#include "YamlCollection.hpp"

namespace YamlParser
{
    template <class T>
    YamlParser::valueType YamlNode<T>::getValueType()
    {
        return value.size() > 0 ? valueType::STRING : valueType::ARRAY;
    }

} // namespace YamlParser
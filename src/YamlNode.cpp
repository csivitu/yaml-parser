#include "YamlNode.hpp"

namespace YamlParser
{

    inline YamlParser::YamlNodeType YamlParser::YamlNode::getNodeType()
    {
        if (this->value->_map != nullptr)
            return YamlNodeType::MAP;
        else if (this->value->_collection != nullptr)
            return YamlNodeType::MAP;
        else
            return YamlNodeType::SCALAR;
    }
} // namespace YamlParser
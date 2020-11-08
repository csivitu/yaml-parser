#include "YamlNode.hpp"

namespace YamlParser
{

    void YamlNode::setNode(const std::string &key, const std::string &value)
    {
        this->_key = key;
        this->_value = value;
    }

    YamlParser::valueType YamlNode::getValueType()
    {
        // TODO: Check if array then check for type of array
        // TODO: If not array, check for type of number
        return valueType::FLOAT;
    }
    YamlNode::YamlNode()
    {
        this->_key = "";
        this->_value = "";
    }
} // namespace YamlParser
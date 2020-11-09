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
        hasChildren = false;
        valueIsArray = false;
        this->indent = 0;
    }

    void YamlNode::addChild(YamlNode node)
    {
        children.push_back(node);
    }

    void YamlNode::clear()
    {
        this->_key = "";
        this->_value = "";
        this->hasChildren = false;
        this->valueIsArray = false;
    }

    std::string YamlNode::getKey()
    {
        return this->_key;
    }

    std::string YamlNode::getValue()
    {
        return this->_value;
    }
} // namespace YamlParser
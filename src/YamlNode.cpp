#include "YamlNode.hpp"
#include "YamlException.hpp"
namespace YamlParser
{

    inline YamlParser::YamlNodeType YamlParser::YamlNode::getNodeType()
    {
        if (this->value->_map != nullptr)
            return YamlNodeType::MAP;
        else if (this->value->_collection != nullptr)
            return YamlNodeType::VECTOR;
        else
            return YamlNodeType::SCALAR;
    }

    void YamlNode::addChild(const YamlNode &_child)
    {

        switch (this->getNodeType())
        {
        case YamlNodeType::SCALAR:
            
            break;

        case YamlNodeType::VECTOR:

            break;

        case YamlNodeType::MAP:
            /**
             * If it contains only a single SCALAR:SCALAR mapping and we add a child,
             * We must convert this current YamlNode into type VECTOR
             * 
             * */
            break;
        };
    }

    YamlNode YamlNode::getChildren()
    {
        // return this->value;
    }

} // namespace YamlParser
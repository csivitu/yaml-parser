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
            /**
             * If current node is of type SCALAR, we need to convert the current node 
             * into type VECTOR and create a new node who's child will be _child
             * */
            break;

        case YamlNodeType::VECTOR:
            /**
             * If current node is type VECTOR, then we append _child
            */
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
    YamlNode YamlNode::operator[](std::string const &obj)
    {
        /**
             * if indexing a SCALAR, it should throw an error
             * if indexing a VECTOR, it should take the index of the number (check if index is number)
             * if index is string, we consider it a map and find the value using it as key
             * 
             * 
            * */
    }

    YamlNode YamlNode::operator=(std::string const &obj)
    {
        if (this->getNodeType() == YamlNodeType::MAP)
        {
            throw VectorNodeAssignmentError();
        }
        else if (this->getNodeType() == YamlNodeType::VECTOR)
        {
            throw MapNodeAssignmentError();
        }
        /** ONLY FOR SCALARS
             * if map or collection, it should free up the map or collection and
             * assign the scalar 
             * 
             * IF anything else, throw error
             * */
    }
    YamlNode YamlNode::getChildren()
    {
        // return this->value;
    }

} // namespace YamlParser
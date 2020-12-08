#include "YamlNode.hpp"
#include "YamlException.hpp"
#include "YamlUtil.hpp"
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
    YamlNode YamlNode::operator[](std::string const &obj)
    {
        /**
             * if indexing a SCALAR, it should throw an error
             * if indexing a VECTOR, it should take the index of the number (check if index is number)
             * if index is string, we consider it a map and find the value using it as key
             * 
             * 
            * */
        if (this->getNodeType() == YamlNodeType::SCALAR)
        {
            throw YamlException("Unable to index type SCALAR");
        }

        if (is_number(obj))
        {
            // we have to index a VECTOR
            return this->value->_collection->at(stoi(obj));
        }
        else
        {
            // we have to index a MAP
            return this->value->_map->lower_bound(obj)->second;
        }
    }

    YamlNode YamlNode::operator=(std::string const &obj)
    {
        if (this->getNodeType() == YamlNodeType::MAP)
        {
            throw YamlException("Unable to assign type SCALAR to type MAP");
        }
        else if (this->getNodeType() == YamlNodeType::VECTOR)
        {
            throw YamlException("Unable to assign type SCALAR to type VECTOR");
        }
        /** ONLY FOR SCALARS
             * if map or collection, it should free up the map or collection and
             * assign the scalar 
             * 
             * IF anything else, throw error
             * */
        YamlNode node;
        node.value->scalar = obj;
        return node;
    }

    // YamlNode::YamlNode(){
    //     value = nullptr;
    // }
} // namespace YamlParser
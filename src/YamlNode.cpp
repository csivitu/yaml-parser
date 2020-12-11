#include "YamlNode.hpp"
#include "YamlException.hpp"
#include "YamlUtil.hpp"
namespace YamlParser
{

    YamlParser::YamlNodeType YamlParser::YamlNode::getNodeType()
    {
        if (this->value->_map != nullptr)
        {
            return YamlNodeType::MAP;
        }
        else if (this->value->_collection != nullptr)
        {
            return YamlNodeType::VECTOR;
        }
        else
        {
            return YamlNodeType::SCALAR;
        }
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
    YamlNode::YamlNode(std::string const &obj)
    {
        value = std::shared_ptr<_nodeValue>(new _nodeValue);
        (*this) = obj;
        // this->value->scalar = obj;
    }
    void YamlNode::operator=(std::string const &obj)
    {
        std::cout << "in =" << std::endl;
        if (this->getNodeType() == YamlNodeType::MAP)
        {
            throw YamlException("Unable to assign type SCALAR to type MAP");
        }
        else if (this->getNodeType() == YamlNodeType::VECTOR)
        {
            throw YamlException("Unable to assign type SCALAR to type VECTOR");
        }
        std::cout << "in =" << std::endl;

        /** ONLY FOR SCALARS
             * if map or collection, it should free up the map or collection and
             * assign the scalar 
             * 
             * IF anything else, throw error
             * */
        // YamlNode node;
        // node.value->scalar = obj;
        this->value->scalar = obj;
        // return node;
    }
    YamlNode::YamlNode(const char *rhs)
    {

        value = std::shared_ptr<_nodeValue>(new _nodeValue);
        // (*this) = obj;
        std::string temp = rhs;
        this->value->scalar = temp;
    }
    YamlNode::YamlNode()
    {
        value = std::shared_ptr<_nodeValue>(new _nodeValue);
    }
    std::ostream &operator<<(std::ostream &os, YamlNode &obj)
    {
        if (obj.getNodeType() == YamlNodeType::MAP)
        {
            throw YamlException("Invalid operation '<<' on YamlNodeType MAP");
        }
        else if (obj.getNodeType() == YamlNodeType::VECTOR)
        {
            std::vector<YamlNode> vec = *(obj.value->_collection);
            for (auto it : vec)
            {
                os << it.value << " ";
            }
            return os;
        }
        else
        {
            os << obj.value->scalar;
            return os;
        }
    }
} // namespace YamlParser
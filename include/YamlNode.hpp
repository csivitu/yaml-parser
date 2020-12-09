#pragma once

#include <vector>
#include <map>
#include <string>
#include <memory>
#include "YamlException.hpp"
namespace YamlParser
{
    class _nodeValue;
    class YamlNode;

    enum class YamlNodeType
    {
        MAP,
        SCALAR,
        VECTOR
    };

    class YamlNode
    {
    private:
    public:
        void operator=(std::string const &obj);
        std::shared_ptr<_nodeValue> value;
        // _nodeValue *value;

        YamlNode(std::string const &obj);
        YamlNode operator[](std::string const &obj);

        // YamlNode operator=(const char* obj);

        
        YamlNode();
         YamlNodeType getNodeType();
    };

    class _nodeValue
    {
    public:
        explicit _nodeValue(){
            _map = nullptr;
            _collection = nullptr;
            scalar = "s";
        }
        _nodeValue(const _nodeValue &) = delete;
        _nodeValue &operator=(const _nodeValue &) = delete;
        ~_nodeValue() = default;

        std::shared_ptr<std::map<std::string, YamlNode>> _map;
        std::shared_ptr<std::vector<YamlNode>> _collection;
        std::string scalar;
    };

} // namespace YamlParser

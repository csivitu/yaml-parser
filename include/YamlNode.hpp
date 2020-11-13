#pragma once

#include <vector>
#include <map>
#include <string>
#include <memory>
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
        std::unique_ptr<_nodeValue> value;

    public:
        // _nodeValue *value;

        inline YamlNodeType getNodeType();
        // function to return value
    };

    class _nodeValue
    {
    public:
        std::unique_ptr<std::map<std::string, YamlNode>> _map;
        std::unique_ptr<std::vector<YamlNode>> _collection;
        std::string scalar;
        // string , number or a float
    };

} // namespace YamlParser

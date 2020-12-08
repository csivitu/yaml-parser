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

    public:
        std::unique_ptr<_nodeValue> value;
        // _nodeValue *value;

        YamlNode operator[](std::string const &obj);
       

        YamlNode operator=(std::string const &obj);
       

        inline YamlNodeType getNodeType();
        void addChild(const YamlNode &_child);
        YamlNode getChildren();
    };

    class _nodeValue
    {
    public:
        std::unique_ptr<std::map<std::string, YamlNode>> _map;
        std::unique_ptr<std::vector<YamlNode>> _collection;
        std::string scalar;
    };

} // namespace YamlParser

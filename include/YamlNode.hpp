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
        std::shared_ptr<_nodeValue> value;
        // _nodeValue *value;

        YamlNode operator[](std::string const &obj);

        YamlNode operator=(std::string const &obj);

        inline YamlNodeType getNodeType();
    };

    class _nodeValue
    {
    public:
        explicit _nodeValue();
        _nodeValue(const _nodeValue &) = delete;
        _nodeValue &operator=(const _nodeValue &) = delete;
        ~_nodeValue() = default;

        std::shared_ptr<std::map<std::string, YamlNode>> _map;
        std::shared_ptr<std::vector<YamlNode>> _collection;
        std::string scalar;
    };

} // namespace YamlParser

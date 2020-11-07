#pragma once
#ifndef YAML_NODE_H
#define YAML_NODE_H

#include <vector>
#include <string>
namespace YamlParser
{
    enum class valueType
    {
        STRING,
        INT,
        FLOAT,
        ARRAY
    };

    template <class T>
    class YamlNode
    {
    public:
        std::string key;
        // std::string value;
        std::vector<T> value;
        
        std::vector<YamlNode> children;

        inline valueType getValueType();
    };

} // namespace YamlParser

#endif
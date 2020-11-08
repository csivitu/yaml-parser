#pragma once
#ifndef YAML_NODE_H
#define YAML_NODE_H

#include <vector>
#include <map>
#include <string>
namespace YamlParser
{
    enum class valueType
    {
        STRING,
        INT,
        FLOAT,
        STRING_ARRAY,
        INT_ARRAY,
        FLOAT_ARRAY
    };

    class YamlNode
    {
    public:
        YamlNode();
       void setNode(const std::string& , const std::string&);

        std::vector<YamlNode> children;

        inline valueType getValueType();

    private:
        std::string _key;
        std::string _value;
    };

} // namespace YamlParser

#endif
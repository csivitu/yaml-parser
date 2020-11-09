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

        template <class T>
    class TestNode
    {
    private:
        std::string key;
        
        std::vector<T> values;
    };

    class YamlNode
    {
    public:
        YamlNode();
        void setNode(const std::string &, const std::string &);
        inline valueType getValueType();
        void clear();
        void addChild(const YamlNode node);

        std::string getKey();
        std::string getValue();

        bool valueIsArray;
        bool hasChildren;
        int indent;

        // TODO: print document function
        void printYaml();

        // TODO: overload << operator for cout

        // TODO: function for yaml validation

        // TODO: overload [] operator

        std::vector<YamlNode> children;

    private:
        std::string _key;
        std::string _value;
    };

} // namespace YamlParser

#endif
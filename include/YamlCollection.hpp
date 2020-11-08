#pragma once
#ifndef YAML_COLLECTION_H
#define YAML_COLLECTION_H

#include <vector>
#include <string>

#include "YamlNode.hpp"
namespace YamlParser
{

        
    class YamlCollection
    {
    public:
        YamlCollection();

    private:
        std::vector<YamlNode>  nodes;
    };

} // namespace YamlParser

#endif
#pragma once

#ifndef YAML_PARSER_H
#define YAML_PARSER_H

#include <iostream>
#include <fstream>
#include <vector>


#include "YamlNode.hpp"
#include "YamlCollection.hpp"
namespace YamlParser
{
    class YamlParser
    {
    public:
        YamlParser(const char *_fileName, int indentation=2);
        ~YamlParser();
        bool getValidationStatus();
        void parse();
        
        template <class T>
        YamlNode<T> getDocument();
    private:
        
        std::ifstream fin;
        bool documentStatus;
        unsigned int indentation_spacing;
        bool file_exists(const char *fileName);
    };

} // namespace YamlParser

#endif

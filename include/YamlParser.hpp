#pragma once


#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <stdio.h>

#include "YamlNode.hpp"

// #include "YamlUtil.hpp"
namespace YamlParser
{
    class YamlParser
    {
    public:
        YamlParser(const char *_fileName, int indentation = 2);
        ~YamlParser();
        bool getValidationStatus();
        YamlNode parse();

        //  TODO: getDocuments() that returns a vector<YamlCollection>

    private:
        std::ifstream fin;
        bool documentStatus;
        unsigned int indentation_spacing;

        
        bool fileExists(const char *fileName);


    };

} // namespace YamlParser

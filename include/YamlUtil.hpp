#pragma once
#ifndef YAML_UTIL_H
#define YAML_UTIL_H

#include <string>
#include <fstream>
#include <streambuf>
#include <vector>
#include <algorithm>
#include <functional>
#include <string.h>

// #include <functional>

namespace YamlParser
{
    void split(const std::string &str, const std::string &delim, std::vector<std::string> &parts);
    std::string& rtrim(std::string &s);
    bool searchStringForChar(const char *searchString, const char searchChar);
    bool is_number(const std::string &s);
    std::string fileToString(const std::string &s);
} // namespace YamlParser

#endif
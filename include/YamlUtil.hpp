#pragma once
#ifndef YAML_UTIL_H
#define YAML_UTIL_H

#include <string>
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
} // namespace YamlParser

#endif
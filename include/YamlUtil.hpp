#pragma once
#ifndef YAML_UTIL_H
#define YAML_UTIL_H

#include <string>
#include <vector>

namespace YamlParser
{
    void split(const std::string &str, const std::string &delim, std::vector<std::string> &parts);
} // namespace YamlParser

#endif
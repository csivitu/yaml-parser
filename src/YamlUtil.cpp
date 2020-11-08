#include "YamlUtil.hpp"

namespace YamlParser
{

    void split(const std::string &str, const std::string &delim, std::vector<std::string> &parts)
    {
        /**accepts a string which is a line from the file and splits it using the delimiter
    and stores the individual fields in a vector of type string */
        size_t start, end = 0;
        while (end < str.size())
        {
            start = end;
            while (start < str.size() && (delim.find(str[start]) != std::string::npos))
            {
                start++; // skip initial whitespace
            }
            end = start;
            while (end < str.size() && (delim.find(str[end]) == std::string::npos))
            {
                end++; // skip to end of word
            }
            if (end - start != 0) // just ignore zero-length strings.
            {
                parts.push_back(std::string(str, start, end - start));
            }
        }
    }

    std::string &rtrim(std::string &s)
    {
        s.erase(std::find_if(s.rbegin(), s.rend(),
                             std::not1(std::ptr_fun<int, int>(std::isspace)))
                    .base(),
                s.end());
        return s;
    }

    bool searchStringForChar(const char *searchString, const char searchChar)
    {
        return strchr(searchString, searchChar);
    }
} // namespace YamlParser

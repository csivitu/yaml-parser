// #include "main.hpp"
#include "YamlParser.hpp"

int main()
{
    
    YamlParser::YamlParser yaml("./sample2.yml");
    yaml.parse();
    return 0;
}

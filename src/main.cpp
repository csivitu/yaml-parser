#include "main.hpp"
#include "YamlParser.hpp"

int main()
{
    
    YamlParser::YamlParser yaml("./sample.yml");
    yaml.parse();
    return 0;
}

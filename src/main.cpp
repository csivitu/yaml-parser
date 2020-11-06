#include "main.hpp"
#include "YamlParser.hpp"
void test()
{
    std::cout << "Hello World\n";
}

int main()
{
    YamlParser::YamlParser yaml("./sample.yml", 3);
    yaml.parse();
    return 0;
}
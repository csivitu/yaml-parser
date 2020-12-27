// #include "main.hpp"
#include "YamlParser.hpp"
#include "YamlNode.hpp"
#include "YamlException.hpp"
#include "YamlUtil.hpp"
#include <iostream>
#include <string>

void yaml_basic();

void yaml_basic()
{
    YamlParser::YamlParser root("./basic.yml");
    YamlParser::YamlNode names = root.parse();
    exit(EXIT_SUCCESS);
}

int main()
{
    yaml_basic();

    YamlParser::YamlParser yaml("./sample.yml");
    std::cout << "main\n";

    YamlParser::YamlNode node = "Hello World";

    node = "Test2";
    YamlParser::YamlNode node2 = node;

    std::string ss = node2;
    std::cout << ss;

    if (node.getNodeType() == YamlParser::YamlNodeType::MAP)
    {
        std::cout << "yes";
    }

    std::cout << node;
    std::vector<std::string> vec = {"1", "2", "3"};
    YamlParser::YamlNode t;
    std::vector<YamlParser::YamlNode> v;
    for (auto x : vec)
    {
        v.push_back(x);
    }
    for (auto i : v)
    {
        std::cout << i << " ";
    }
    // node3 = vec;
    std::cout << "main\n";

    return 0;
}
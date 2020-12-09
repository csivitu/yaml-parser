// #include "main.hpp"
#include "YamlParser.hpp"
#include "YamlNode.hpp"
#include "YamlException.hpp"
#include "YamlUtil.hpp"
#include <iostream>
#include <string>
class Test
{

public:
    std::string val;

    void operator=(std::string const &obj)
    {
        this->val = obj;
        // return *this;Y
    }
};
int main()
{
    // Test t;
    // t = "Hello World";
    // std::cout<<"|"<<t.val<<"|";

    YamlParser::YamlParser yaml("./sample.yml");
    std::cout << "main\n";

    // std::string str = "Hello World";
    YamlParser::YamlNode node = "Hello World";

    node = yaml.parse();

    std::cout << "main\n";

    return 0;
}

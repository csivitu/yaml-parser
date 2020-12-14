## Usage

```cpp
#include "main.hpp"
#include "YamlParser.hpp"

int main()
{
    YamlParser::YamlParser yaml("./sample.yml");
    yaml.parse();
    return 0;
}
```

Compile with

```bash
g++ main.cpp -lyaml-parser
```

Basic Usage

```c++
// Initialize YamlNode with type SCALAR

   YamlParser::YamlNode node("Hello World");
   YamlParser::YamlNode node2 = "Hello World";

   std::cout<<node<<" "<< node2<<"\n;
   /*
    Note: You can use the << operator only when the YamlNode has type YamlNodeType::SCALAR
   */

```

You can also interop between `YamlParser::YamlNode` and `std::string`

```c++
    std::vector<std::string> vec = {"1", "2", "3"};
    std::vector<YamlParser::YamlNode> v;

    for (auto x : vec)
    {
        v.push_back(x);
    }

    for (auto i : v)
    {
        std::cout << i << " ";
    }
```

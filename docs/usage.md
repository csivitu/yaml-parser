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
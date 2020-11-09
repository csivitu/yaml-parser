#include "YamlParser.hpp"
#include "YamlNode.hpp"
#include "YamlUtil.hpp"
namespace YamlParser
{
    YamlParser::YamlParser(const char *_fileName, int indentation)
    {

        this->indentation_spacing = indentation;
        documentStatus = false;
        if (!fileExists(_fileName))
        {
            std::cerr << "Unable to open file\n";
            return;
        }

        fin.open(_fileName);
    }

    YamlParser::~YamlParser()
    {
        fin.close();
    }
    bool YamlParser::getValidationStatus()
    {
        return documentStatus;
    }
    void YamlParser::parse()
    {
        std::string line;
        int collections = 0;

        std::cout << "parsing\n";
        YamlNode root;
        YamlNode node;

        while (std::getline(fin, line))
        {
            node.clear();
            const std::string s = rtrim(line);
            
            if (s.size() == 0 || s.at(0) == '#')
                continue;

            switch (s.at(s.size() - 1))
            {
            case ':':
                std::cout << "Block indent: " << s.substr(0, s.find_first_of(":")) << "\n";
                break;

            default:
                std::vector<std::string> vec;
                split(line, ":", vec);
                // std::cout << "size: " << vec.size() << "\n";
                node.setNode(vec.at(0), vec.at(1));
                root.addChild(node);
                std::cout << vec.at(0) << " : " << vec.at(1) << "|\n";
                break;
            }
        }
        try
        {
            auto node = root.children.at(0);
            std::cout << "Key is " <<node.getKey()<< "and value is "<<node.getValue() << "\n";
        }
        catch (...)
        {
            std::cerr << "\nname is non existent\n";
        }

        std::cout << "Collections: " << collections << "\n";
    }

    bool YamlParser::fileExists(const char *fileName)
    {
        std::ifstream infile(fileName);
        return infile.good();
    }

} // namespace YamlParser

#include "YamlParser.hpp"
#include "YamlNode.hpp"
namespace YamlParser
{
    YamlParser::YamlParser(const char *_fileName, int indentation)
    {

        this->indentation_spacing = indentation;
        documentStatus = false;
        if (!file_exists(_fileName))
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
        
        YamlNode<int> yn;
        
        std::cout << "parsing\n";

        while (std::getline(fin, line))
        {
            if (line[0] == '-')
            {
                std::cout << "start\t";
                collections++;
            }
            std::cout << line << "\n";
        }

        std::cout << "Collections: " << collections << "\n";
    }

    bool YamlParser::file_exists(const char *fileName)
    {
        std::ifstream infile(fileName);
        return infile.good();
    }
} // namespace YamlParser

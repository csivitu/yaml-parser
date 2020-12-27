#include "YamlParser.hpp"
#include "YamlNode.hpp"
#include "YamlUtil.hpp"
#include "YamlException.hpp"

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
    YamlNode YamlParser::parse()
    {
        std::string line;
        int collections = 0;

        std::cout << "parsing\n";
        bool inNode = false;
        YamlNode yn;

        while (std::getline(fin, line))
        {

            const std::string s = rtrim(line);

            if (s.size() == 0 || s.at(0) == '#')
                continue;

            if (s.at(0) == '-' || inNode)
            {
                //
                std::cout << s << "\n";
            }
        }
        try
        {
        }
        catch (const YamlException &e)
        {
            std::cerr << e.what();
        }

        std::cout << "Collections: " << collections << "\n";

        return yn;
    }

    bool YamlParser::fileExists(const char *fileName)
    {
        std::ifstream infile(fileName);
        return infile.good();
    }

} // namespace YamlParser

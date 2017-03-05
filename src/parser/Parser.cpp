#include "Parser.hpp"
#include "ErrorParser.hpp"

bool is_non_empty(std::string &line)
{
    unsigned long int i = 0;
    while (i < line.size())
    {
        if (line[i] != '\t' && line[i] != ' ')
            return (true);
        i++;
    }
    return (false);
}

void set_links(std::stringstream &str, std::map<std::string, nts::IComponent *> chipsets)
{
    std::string line;
    std::regex rgx("^(\\S+):(\\d+)\\s+(\\S+):(\\d+)");
    std::smatch match;
    while (std::getline(str, line))
        if (std::regex_search(line, match, rgx))
        {
            std::map<std::string, nts::IComponent *>::iterator it2;
            std::map<std::string, nts::IComponent *>::iterator it1;
            if ((it1 = chipsets.find(match[1])) != chipsets.end() && (it2 = chipsets.find(match[3])) != chipsets.end())
            {
                it1->second->SetLink(stoi(match[2]), *(it2->second), stoi(match[4]));
                it2->second->SetLink(stoi(match[4]), *(it1->second), stoi(match[2]));
//                std::cout << "Link set between chipsets \x1b[31m" << match[1] << "\x1b[0m and \x1b[31m" << match[3]<< "\x1b[0m with pins \x1b[32m" << match[2] << "\x1b[0m and \x1b[32m" << match[4] << "\x1b[0m." << std::endl;
            }
            else
                throw ErrorParser("Unknown component name.", ((it1 == chipsets.end()) ? (match[1]) : (match[3])));
        }
}

std::map<std::string, nts::IComponent *> create_chipset(std::stringstream &str, const std::string &file)
{
    std::string line;
    std::regex rgx("^(\\S+)\\s+([^\\s(]+)(?:\\(([^\\s]+)\\))?$");
    std::smatch match;
    std::map<std::string, nts::IComponent *> chipsets;
    while (std::getline(str, line) && line != ".links:")
        if (std::regex_search(line, match, rgx))
        {
            if (chipsets.find(match[2]) == chipsets.end())
            {
                nts::IComponent *cmpt = Create::createComponent(match[1], match[3]);
                dynamic_cast<nts::AComponent *>(cmpt)->setName(match[2]);
                chipsets[match[2]] = cmpt;
            }
            else
                throw ErrorParser("Several components share the same name.", match[2]);
        }
        else
            throw ErrorParser("Syntax error.", line);
    if (line != ".links:")
        throw ErrorParser("No links section.", file);
    set_links(str, chipsets);
    return (chipsets);
}

std::map<std::string, nts::IComponent *> parser(const char *file)
{
    std::ifstream _file(file);
    std::string line;
    std::stringstream str;
    std::regex rgx("^([^#]+)");
    std::smatch match;
    if (_file)
    {
        while (std::getline(_file, line))
            if (std::regex_search(line, match, rgx))
            {
                line = match[1];
                if (is_non_empty(line))
                    str << line << std::endl;
            }
        std::getline(str, line);
        if (line == ".chipsets:")
            return (create_chipset(str, file));
        else
            throw ErrorParser("No chipset section.", file);
    }
    else
        throw ErrorParser("No such file.", file);
    return (*new std::map<std::string, nts::IComponent *>);
}

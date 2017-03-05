#include <algorithm>
#include "Parser.hpp"
#include "IComponent.hpp"
#include "Commands.hpp"

bool cmp_icmp(const nts::IComponent *c1, const nts::IComponent *c2)
{
   return (dynamic_cast<const nts::AComponent *>(c1)->getName().compare(dynamic_cast<const nts::AComponent *>(c2)->getName()));
}

std::vector<nts::IComponent *> map_to_vector(std::map<std::string, nts::IComponent *> &chipsets)
{
    std::vector<nts::IComponent *> chipsets_v;
    for(std::map<std::string, nts::IComponent *>::iterator it = chipsets.begin(); it != chipsets.end(); ++it )
    {    
        chipsets_v.push_back(it->second);
    }
    std::sort(chipsets_v.begin(), chipsets_v.end(), cmp_icmp);
    return (chipsets_v);
}

void set_inputs(std::map<std::string, nts::IComponent *> chipsets_m, char **arg, int nb)
{
    std::map<std::string, nts::IComponent *>::iterator it;
    int input = 0;
    for(std::map<std::string, nts::IComponent *>::iterator it = chipsets_m.begin(); it != chipsets_m.end(); ++it )
        if (dynamic_cast<nts::AComponent *>((*it).second)->getType() == nts::AComponent::Type::I || dynamic_cast<nts::AComponent *>((*it).second)->getType() == nts::AComponent::Type::T)
            input++;
    std::regex rgx("^(\\S+)=(\\S+)$");
    std::smatch match;
    int i = 0;
    while (i < nb)
    {
        std::string arg_s = arg[i];
        if (std::regex_search(arg_s, match, rgx))
        {
            if ((it = chipsets_m.find(match[1])) != chipsets_m.end())
            {
                if (dynamic_cast<nts::AComponent *>((*it).second)->getType() == nts::AComponent::Type::I || dynamic_cast<nts::AComponent *>((*it).second)->getType() == nts::AComponent::Type::T)
                {
                    if (match[2] == "1")
                        (*it).second->Compute(2);
                    else if (match[2] == "0")
                        (*it).second->Compute(3);
                    else
                        throw Error("Invalid value.", match[2]);
                    input--;
                }
                else
                    throw Error("Component is not an variable input.", match[1]);
            }
            else
                throw Error("No component with this name.", match[1]);
        }
        else
            throw Error("Invalid argument.", arg[i]);
        i++;
    }
    if (input)
        throw Error("Every inputs werent set", "arguments");
}

int core(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "\x1b[31mAn error occured\x1b[0m: No arguments given \x1b[31mat\x1b[0m: main" << std::endl;
        return (1);
    }
    try
    {
        std::map<std::string, nts::IComponent *> chipsets_m = parser(av[1]);
        std::vector<nts::IComponent *> chipsets_v = map_to_vector(chipsets_m);
        set_inputs(chipsets_m, &av[2], ac - 2);
        launch(chipsets_m, chipsets_v);
    }
    catch (const Error &error)
    {
        std::cerr << "\x1b[31mAn error occured\x1b[0m: " << error.what() << " \x1b[31mat\x1b[0m: " << error.getIndicator() << std::endl;
        return (1);
    }
    return (0);
}

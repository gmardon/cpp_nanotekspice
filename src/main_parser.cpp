#include <typeinfo>
#include "../include/Parser.hpp"
#include "../include/IComponent.hpp"
#include <algorithm>

void dump(std::vector<nts::IComponent *> chipsets)
{
    for(std::vector<nts::IComponent *>::iterator it = chipsets.begin(); it != chipsets.end(); ++it )
        (*it)->Dump();
}

// void simulate()
// {

// }

void display(std::vector<nts::IComponent *> chipsets)
{
    for(std::vector<nts::IComponent *>::iterator it = chipsets.begin(); it != chipsets.end(); ++it )
        if (dynamic_cast<nts::AComponent *>(*it)->getType() == "output")
        {
            std::cout << dynamic_cast<nts::AComponent *>(*it)->getName() << "=";
            nts::Tristate_dump((*it)->Compute(1));
            std::cout << std::endl;
        }
}

bool cmp_icmp(const nts::IComponent *c1, const nts::IComponent *c2)
{
    return (dynamic_cast<const nts::AComponent *>(c1)->getName() == dynamic_cast<const nts::AComponent *>(c2)->getName());
}

std::vector<nts::IComponent *> map_to_vector(std::map<std::string, nts::IComponent *> &chipsets)
{
    std::vector<nts::IComponent *> chipsets_v;
    for(std::map<std::string, nts::IComponent *>::iterator it = chipsets.begin(); it != chipsets.end(); ++it )
        chipsets_v.push_back( it->second );
    std::sort(chipsets_v.begin(), chipsets_v.end(), cmp_icmp);
    return (chipsets_v);
}

int launch(std::map<std::string, nts::IComponent *> chipsets_m, std::vector<nts::IComponent *> chipsets_v)
{
    (void)chipsets_m;
    std::string command;
    while (1)
    {
        std::cout << "> ";
        std::cin >> command;
        if (std::cin.eof() || command == "exit")
            return (0);
        else if (command == "display")
            display(chipsets_v);
        // else if (command == "simulate")
        //     simulate();
        // else if (command == "loop")
        //     while (1)
        //         simulate();
        else if (command == "dump")
            dump(chipsets_v);
        // else if (command == "input")
        //     ;
    }
}

int main(int ac, char **av)
{
    if (ac < 2)
        return (84);
    std::map<std::string, nts::IComponent *> chipsets = parser(av[1]);
    return (launch(chipsets, map_to_vector(chipsets)));
}
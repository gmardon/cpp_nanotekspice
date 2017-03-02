#include "../include/Parser.hpp"
#include "../include/IComponent.hpp"

void dump(std::map<std::string, nts::IComponent *> chipsets)
{
    for(std::map<std::string, nts::IComponent *>::iterator it = chipsets.begin(); it != chipsets.end(); ++it )
        it->second->Dump();
}

int launch(std::map<std::string, nts::IComponent *> chipsets)
{
    std::string command;
    while (1)
    {
        std::cout << "> ";
        std::cin >> command;
        if (command == "exit")
            return (0);
        else if (command == "display")
            ;
        else if (command == "simulate")
            ;
        else if (command == "loop")
            ;
        else if (command == "dump")
            dump(chipsets);
        else if (command == "input")
            ;
    }
}

int main(int ac, char **av)
{
    if (ac < 2)
        return (84);
    std::map<std::string, nts::IComponent *> chipsets = parser(av[1]);
    return (launch(chipsets));
}
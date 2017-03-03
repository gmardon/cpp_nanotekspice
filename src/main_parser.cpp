#include <typeinfo>
#include "../include/Parser.hpp"
#include "../include/IComponent.hpp"
#include <algorithm>

void pony()
{
    std::cout << "     \x1b[38;5;221m▄▄\x1b[48;5;221;38;5;229m▄▄▄▄▄\x1b[49;38;5;221m▄▄▄\x1b[39m                                  \x1b[00m" << std::endl;
    std::cout << "   \x1b[38;5;221m▄\x1b[48;5;221;38;5;229m▄\x1b[48;5;229m█\x1b[38;5;221m▄\x1b[38;5;229m████████\x1b[48;5;221m▄▄▄\x1b[49;38;5;103m▄\x1b[48;5;103;38;5;252m▄\x1b[49;38;5;103m▄\x1b[39m                            \x1b[00m" << std::endl;
    std::cout << "  \x1b[48;5;221;38;5;221m█\x1b[49m▀\x1b[48;5;221m█\x1b[38;5;229m▄\x1b[48;5;229m███████████\x1b[48;5;103;38;5;103m█\x1b[48;5;252;38;5;252m█\x1b[38;5;146m▄\x1b[48;5;103;38;5;252m▄\x1b[49;38;5;103m▄\x1b[39m                           \x1b[00m" << std::endl;
    std::cout << "   \x1b[48;5;221;38;5;221m█\x1b[48;5;229;38;5;229m██\x1b[38;5;221m▄▄▄▄▄\x1b[48;5;221;38;5;252m▄\x1b[38;5;221m█\x1b[38;5;229m▄\x1b[48;5;229m██\x1b[38;5;221m▄\x1b[48;5;103;38;5;252m▄\x1b[48;5;252m█\x1b[48;5;103;38;5;103m█\x1b[48;5;252;38;5;252m█\x1b[48;5;103;38;5;103m█\x1b[49;38;5;221m▄\x1b[39m   \x1b[48;5;103;38;5;103m█\x1b[38;5;252m▄\x1b[38;5;103m█\x1b[49;39m \x1b[38;5;103m▄▄\x1b[39m                 \x1b[00m" << std::endl;
    std::cout << "  \x1b[48;5;221;38;5;221m█\x1b[48;5;229;38;5;229m█\x1b[38;5;221m▄\x1b[49m▀\x1b[39m  \x1b[48;5;103;38;5;103m█\x1b[48;5;252;38;5;252m██\x1b[48;5;221m▄▄▄▄▄\x1b[48;5;252m███\x1b[48;5;103m▄\x1b[48;5;252m█\x1b[48;5;103;38;5;103m█\x1b[48;5;221;38;5;221m█\x1b[49;39m  \x1b[48;5;103;38;5;103m█\x1b[48;5;252;38;5;252m██\x1b[48;5;103;38;5;103m█\x1b[38;5;252m▄\x1b[48;5;252m█\x1b[48;5;103;38;5;103m█\x1b[49;39m                 \x1b[00m" << std::endl;
    std::cout << "  \x1b[48;5;221;38;5;221m██\x1b[49;39m   \x1b[48;5;103;38;5;103m█\x1b[48;5;252;38;5;252m███\x1b[48;5;103;38;5;16m▄\x1b[48;5;16;38;5;252m▄▄\x1b[38;5;146m▄\x1b[48;5;146;38;5;16m▄\x1b[48;5;16;38;5;252m▄\x1b[48;5;252m███\x1b[38;5;221m▄\x1b[48;5;229;38;5;229m█\x1b[48;5;221;38;5;221m█\x1b[49;39m  \x1b[48;5;103;38;5;103m█\x1b[48;5;252;38;5;252m██\x1b[48;5;103;38;5;103m█\x1b[48;5;252;38;5;252m█\x1b[38;5;103m▄\x1b[49m▀\x1b[39m                 \x1b[00m" << std::endl;
    std::cout << "  \x1b[38;5;221m▀\x1b[39m    \x1b[48;5;103;38;5;103m█\x1b[48;5;252;38;5;252m██\x1b[48;5;16;38;5;16m█\x1b[48;5;146;38;5;252m▄\x1b[48;5;252m███\x1b[48;5;16;38;5;16m█\x1b[38;5;103m▄\x1b[38;5;252m▄\x1b[48;5;252m██\x1b[48;5;221;38;5;221m█\x1b[48;5;229;38;5;229m█\x1b[48;5;221;38;5;221m█\x1b[49;38;5;103m▄\x1b[48;5;103m█\x1b[48;5;252;38;5;252m██\x1b[48;5;103;38;5;103m█\x1b[48;5;252;38;5;252m█\x1b[38;5;103m▄\x1b[48;5;103;38;5;252m▄\x1b[49;38;5;103m▄▄\x1b[39m                \x1b[00m" << std::endl;
    std::cout << "      \x1b[38;5;103m▄\x1b[48;5;103m█\x1b[48;5;252;38;5;252m██\x1b[48;5;16;38;5;16m█\x1b[48;5;252;38;5;252m████\x1b[48;5;103m▄\x1b[48;5;252m███\x1b[48;5;221;38;5;221m█\x1b[48;5;229;38;5;229m█\x1b[38;5;221m▄\x1b[48;5;221;38;5;103m▄\x1b[48;5;146;38;5;146m█\x1b[48;5;103;38;5;103m█\x1b[48;5;252m▄\x1b[48;5;103m█\x1b[48;5;252;38;5;252m██\x1b[48;5;103;38;5;103m█\x1b[48;5;252;38;5;252m██\x1b[48;5;103;38;5;103m█\x1b[49;39m                \x1b[00m" << std::endl;
    std::cout << "      \x1b[48;5;103;38;5;103m█\x1b[48;5;252;38;5;252m█\x1b[48;5;146;38;5;103m▄\x1b[48;5;252;38;5;252m█████████\x1b[48;5;221;38;5;221m█\x1b[48;5;229;38;5;229m██\x1b[48;5;221;38;5;221m█\x1b[48;5;103;38;5;146m▄\x1b[48;5;146;38;5;103m▄\x1b[48;5;103m█\x1b[48;5;252;38;5;252m█\x1b[48;5;103;38;5;103m█\x1b[38;5;252m▄\x1b[38;5;103m█\x1b[48;5;252;38;5;252m██\x1b[48;5;103;38;5;103m█\x1b[48;5;221;38;5;229m▄▄▄▄▄\x1b[49;38;5;221m▄▄\x1b[39m          \x1b[00m" << std::endl;
    std::cout << "       \x1b[38;5;103m▀▀\x1b[48;5;252m▄▄▄▄▄▄\x1b[38;5;252m██\x1b[48;5;221;38;5;221m█\x1b[48;5;229;38;5;229m█\x1b[38;5;221m▄\x1b[38;5;229m█\x1b[48;5;221;38;5;221m█\x1b[48;5;146;38;5;146m█\x1b[38;5;103m▄\x1b[48;5;103m█\x1b[48;5;252;38;5;252m█\x1b[48;5;103m▄\x1b[48;5;252m█\x1b[38;5;103m▄\x1b[48;5;103m█\x1b[38;5;229m▄\x1b[48;5;229m████████\x1b[48;5;221;38;5;221m█\x1b[49;39m         \x1b[00m" << std::endl;
    std::cout << "               \x1b[48;5;103;38;5;103m█\x1b[48;5;221;38;5;221m█\x1b[48;5;229m▄\x1b[48;5;221m█\x1b[48;5;229;38;5;229m███\x1b[48;5;221;38;5;221m█\x1b[48;5;146;38;5;103m▄\x1b[48;5;103m█\x1b[48;5;252;38;5;252m█\x1b[48;5;103m▄\x1b[48;5;252m█\x1b[48;5;103;38;5;103m█\x1b[48;5;252m▄\x1b[49;38;5;221m▀▀\x1b[48;5;229m▄\x1b[38;5;229m███████\x1b[48;5;221m▄\x1b[49;38;5;221m▄\x1b[39m       \x1b[00m" << std::endl;
    std::cout << "               \x1b[48;5;103;38;5;103m█\x1b[48;5;221;38;5;252m▄\x1b[48;5;252m█\x1b[48;5;221;38;5;221m█\x1b[48;5;229m▄\x1b[48;5;221;38;5;252m▄\x1b[48;5;229;38;5;221m▄\x1b[48;5;221m█\x1b[48;5;103;38;5;234m▄\x1b[48;5;252m▄▄▄\x1b[48;5;103m▄▄\x1b[48;5;252m▄\x1b[48;5;103m▄\x1b[49m▄\x1b[48;5;221;38;5;146m▄\x1b[48;5;229m▄\x1b[38;5;229m█████\x1b[48;5;221m▄\x1b[48;5;229;38;5;221m▄▄\x1b[48;5;221m█\x1b[49;39m      \x1b[00m" << std::endl;
    std::cout << "               \x1b[38;5;103m▀\x1b[48;5;252m▄\x1b[38;5;252m██\x1b[48;5;221m▄▄\x1b[48;5;146;38;5;146m█\x1b[48;5;221;38;5;231m▄\x1b[48;5;234;38;5;234m█\x1b[48;5;237;38;5;237m█\x1b[48;5;234m▄\x1b[48;5;237;38;5;234m▄\x1b[38;5;237m██\x1b[48;5;234m▄\x1b[48;5;237;38;5;234m▄\x1b[38;5;237m█\x1b[48;5;234;38;5;234m█\x1b[48;5;146;38;5;146m█\x1b[48;5;229;38;5;221m▄\x1b[38;5;229m█████\x1b[48;5;221;38;5;221m█\x1b[49;39m \x1b[38;5;221m▀\x1b[39m      \x1b[00m" << std::endl;
    std::cout << "              \x1b[38;5;103m▄▄\x1b[48;5;103m█\x1b[48;5;252m▄▄▄\x1b[38;5;252m██\x1b[48;5;146m▄\x1b[48;5;234;38;5;234m█\x1b[48;5;237m▄\x1b[38;5;237m█\x1b[48;5;234;38;5;234m█\x1b[48;5;237;38;5;237m███\x1b[48;5;234;38;5;234m█\x1b[48;5;237;38;5;237m█\x1b[48;5;234m▄\x1b[48;5;229;38;5;234m▄\x1b[48;5;221;38;5;221m█\x1b[48;5;229;38;5;229m██████\x1b[48;5;221m▄\x1b[49;38;5;221m▄\x1b[39m      \x1b[00m" << std::endl;
    std::cout << "            \x1b[48;5;103;38;5;103m█\x1b[38;5;146m▄\x1b[38;5;103m█\x1b[38;5;252m▄\x1b[48;5;252m█████\x1b[48;5;103;38;5;103m█\x1b[48;5;252m▄\x1b[48;5;234;38;5;234m█\x1b[38;5;237m▄\x1b[48;5;237;38;5;234m▄\x1b[38;5;237m█\x1b[48;5;234;38;5;234m█\x1b[48;5;237;38;5;237m███\x1b[48;5;234;38;5;234m█\x1b[48;5;237;38;5;237m█\x1b[48;5;234;38;5;234m█\x1b[49;39m \x1b[38;5;221m▀\x1b[48;5;229m▄\x1b[38;5;229m██████\x1b[48;5;221m▄\x1b[49;38;5;221m▄▄\x1b[39m   \x1b[00m" << std::endl;
    std::cout << "            \x1b[48;5;103;38;5;103m█\x1b[48;5;146;38;5;146m█\x1b[48;5;103;38;5;103m█\x1b[48;5;252;38;5;252m██\x1b[48;5;103m▄\x1b[38;5;103m█\x1b[49m▀▀▀\x1b[39m \x1b[38;5;234m▀\x1b[48;5;237m▄\x1b[48;5;234m█\x1b[48;5;237m▄\x1b[48;5;221m▄\x1b[48;5;237m▄▄▄\x1b[48;5;221m▄\x1b[48;5;237m▄\x1b[48;5;234;38;5;103m▄\x1b[49;39m  \x1b[38;5;221m▀\x1b[48;5;229m▄\x1b[38;5;229m█\x1b[48;5;221m▄\x1b[48;5;229;38;5;221m▄▄▄\x1b[38;5;229m███\x1b[48;5;221m▄\x1b[49;38;5;221m▄▄\x1b[39m\x1b[00m" << std::endl;
    std::cout << "            \x1b[48;5;103;38;5;103m█\x1b[48;5;146;38;5;146m█\x1b[48;5;103;38;5;103m█\x1b[48;5;252;38;5;252m███\x1b[48;5;103m▄\x1b[49;38;5;103m▄\x1b[39m      \x1b[48;5;103;38;5;103m█\x1b[48;5;234;38;5;146m▄\x1b[48;5;146m█\x1b[48;5;103m▄\x1b[38;5;103m█\x1b[48;5;252m▄\x1b[48;5;234;38;5;252m▄\x1b[48;5;103m▄\x1b[49;38;5;103m▄\x1b[39m   \x1b[38;5;221m▀\x1b[48;5;229m▄▄\x1b[38;5;229m█\x1b[38;5;221m▄\x1b[49m▀▀▀▀\x1b[39m  \x1b[00m" << std::endl;
    std::cout << "            \x1b[38;5;103m▀\x1b[48;5;103m██\x1b[48;5;252;38;5;252m████\x1b[48;5;103;38;5;103m█\x1b[49;39m       \x1b[48;5;103;38;5;103m█\x1b[48;5;146;38;5;146m███\x1b[48;5;103;38;5;103m█\x1b[48;5;252;38;5;252m███\x1b[48;5;103;38;5;103m█\x1b[49m▄\x1b[39m    \x1b[38;5;221m▀▀▀\x1b[39m     \x1b[00m" << std::endl;
    std::cout << "               \x1b[38;5;103m▀\x1b[48;5;252m▄\x1b[38;5;252m█\x1b[48;5;103;38;5;103m█\x1b[49;39m        \x1b[38;5;103m▀\x1b[48;5;146m▄\x1b[38;5;146m██\x1b[48;5;103m▄\x1b[48;5;252;38;5;103m▄\x1b[38;5;252m████\x1b[48;5;103;38;5;103m█\x1b[49;39m           \x1b[00m" << std::endl;
    std::cout << "                 \x1b[38;5;103m▀\x1b[39m           \x1b[38;5;103m▀▀▀▀\x1b[48;5;252m▄\x1b[38;5;252m██\x1b[38;5;103m▄\x1b[49m▀\x1b[39m           \x1b[00m" << std::endl;
    std::cout << "                                  \x1b[38;5;103m▀▀\x1b[39m \x1b[00m" << std::endl;
}

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
        else if (command == "pony")
            pony();
        // else if (command == "input")
        //     ;
    std::regex rgx("^(\\S+)=(\\S+)$");
    std::smatch match;
    if (std::regex_search(command, match, rgx))
    {
        if (chipsets_m.find(match[1]) != chipsets_m.end())
        {
            nts::IComponent *cmpt = Create::createComponent(match[1], match[3]);
            dynamic_cast<nts::AComponent *>(cmpt)->setName(match[2]);
            chipsets_m[match[2]] = cmpt;
        }
        else
            throw ErrorParser("Several components share the same name.", match[2]);
    }
    else
        throw ErrorParser("Unknown command.", command);
    }
}

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "\x1b[31mAn error occured\x1b[0m: No arguments given \x1b[31mat\x1b[0m: main" << std::endl;
        return (1);
    }
    try
    {
        std::map<std::string, nts::IComponent *> chipsets = parser(av[1]);
        launch(chipsets, map_to_vector(chipsets));
    }
    catch (const ErrorParser &error)
    {
        std::cerr << "\x1b[31mAn error occured\x1b[0m: " << error.what() << " \x1b[31mat\x1b[0m: " << error.getIndicator() << std::endl;
        return (1);
    }
    return (0);
}
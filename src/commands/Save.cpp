#include "Save.hpp"

void save(const std::string &file, std::vector<nts::IComponent *> components)
{
    size_t size = file.size();
    std::ofstream save;
    if (size > 4 && file.substr(file.length() - 4) == ".nts")
        save.open(file);
    else
        save.open(file + ".nts");

    if (!save.is_open())
        throw Error ("Saving file impossible", file);
    save << ".chipsets:" << std::endl;
    for (auto it = components.begin(); it != components.end(); ++it)
        save << dynamic_cast<nts::AComponent *>(*it)->save() << std::endl;
    save << std::endl << ".links:" << std::endl;
    for (auto it = components.begin(); it != components.end(); ++it)
        save << *dynamic_cast<nts::AComponent *>(*it)->save_pins() << std::endl;
}
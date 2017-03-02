#include "Parser.hpp"
#include "IComponent.hpp"
int main()
{
    std::map<std::string, nts::IComponent *> chipsets = parser("test_1");

    nts::Tristate_dump(chipsets["s"]->Compute());
    std::cout << std::endl;

    return (0);
}
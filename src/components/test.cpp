#include "IComponent.hpp"
#include "c4001.hpp"

int main()
{
    nts::IComponent *c = new nts::c4001();

    delete(c);
    return (0);
}
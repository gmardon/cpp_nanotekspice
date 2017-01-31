#include "IComponent.hpp"
#include "Input.hpp"
#include "True.hpp"
#include "False.hpp"
#include "Output.hpp"

int main()
{
    nts::IComponent *i1 = new nts::Input("i1", nts::TRUE);
    nts::IComponent *i2 = new nts::Input("i2", nts::FALSE);
    nts::IComponent *o = new nts::Output("o");

    i1->Dump();
    i2->Dump();
    o->Dump();
    o->SetLink(1, *i1, 1);
    std::cout << "State of output: " << o->Compute(1) << std::endl;
    o->SetLink(1, *i2, 1);
    std::cout << "State of output: " << static_cast<nts::Tristate>(o->Compute(1)) << std::endl;
    return (0);
}
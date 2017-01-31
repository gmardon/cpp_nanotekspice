#include "IComponent.hpp"
#include "True.hpp"
#include "c4001.hpp"
#include "Output.hpp"

int main()
{
    nts::IComponent *input1 = new nts::True();
    nts::IComponent *input2 = new nts::True();
    nts::IComponent *c4001 = new nts::c4001();
    nts::IComponent *output = new nts::Output();

    c4001->SetLink(1, *input1, 1);
    c4001->SetLink(2, *input2, 1);
    output->SetLink(1, *c4001, 3);

    nts::Tristate_dump(output->Compute(1));
    return (0);
}
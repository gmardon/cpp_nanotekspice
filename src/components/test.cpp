#include "Component.hpp"

int main()
{
    nts::IComponent *inputT = new nts::True();
    nts::IComponent *inputF = new nts::False();
    nts::IComponent *c4001 = new nts::c4001();
    nts::IComponent *output = new nts::Output();

    c4001->SetLink(1, *inputT, 1);
    c4001->SetLink(2, *inputT, 1);
    output->SetLink(1, *c4001, 3);

    nts::Tristate_dump(output->Compute());
    std::cout << std::endl;

    delete inputT;
    delete inputF;
    delete c4001;
    delete output;

    return (0);
}
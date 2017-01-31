#include "Component.hpp"

int main()
{
    nts::IComponent *inputT1 = new nts::True();
    nts::IComponent *inputT2 = new nts::True();
    nts::IComponent *inputF1 = new nts::False();
    nts::IComponent *inputF2 = new nts::False();
    nts::IComponent *c4069 = new nts::c4069();
    nts::IComponent *output = new nts::Output();
/*
    output->SetLink(1, *c4069, 3);

    c4069->SetLink(1, *inputT1, 1);
    c4069->SetLink(2, *inputT2, 1);
    nts::Tristate_dump(output->Compute(1));
    std::cout << std::endl;

    c4069->SetLink(1, *inputT1, 1);
    c4069->SetLink(2, *inputF2, 1);
    nts::Tristate_dump(output->Compute(1));
    std::cout << std::endl;

    c4069->SetLink(1, *inputF1, 1);
    c4069->SetLink(2, *inputT2, 1);
    nts::Tristate_dump(output->Compute(1));
    std::cout << std::endl;

    c4069->SetLink(1, *inputF1, 1);
    c4069->SetLink(2, *inputF2, 1);
    nts::Tristate_dump(output->Compute(1));
    std::cout << std::endl;
*/
    output->SetLink(1, *c4069, 2);

    c4069->SetLink(1, *inputT1, 1);
    nts::Tristate_dump(output->Compute(1));
    std::cout << std::endl;

    c4069->SetLink(1, *inputF1, 1);
    nts::Tristate_dump(output->Compute(1));
    std::cout << std::endl;

    delete inputT1;
    delete inputT2;
    delete inputF1;
    delete inputF2;
    delete c4069;
    delete output;

    return (0);
}
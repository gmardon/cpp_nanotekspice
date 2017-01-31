#include "Component.hpp"

int main()
{
    nts::IComponent *inputT = new nts::True();
    nts::IComponent *inputF = new nts::False();
    nts::IComponent *c4013 = new nts::c4013();
    nts::IComponent *output1 = new nts::Output();
    nts::IComponent *output2 = new nts::Output();

    output1->SetLink(1, *c4013, 1);
    output2->SetLink(1, *c4013, 2);

    c4013->SetLink(3, *inputT, 1);
    c4013->SetLink(4, *inputF, 1);
    c4013->SetLink(5, *inputF, 1);
    c4013->SetLink(6, *inputF, 1);

    nts::Tristate_dump(output1->Compute(1));
    std::cout << " // ";
    nts::Tristate_dump(output2->Compute(1));
    std::cout << std::endl;

    c4013->SetLink(5, *inputT, 1);

    nts::Tristate_dump(output1->Compute(1));
    std::cout << " // ";
    nts::Tristate_dump(output2->Compute(1));
    std::cout << std::endl;

    c4013->SetLink(4, *inputT, 1);

    nts::Tristate_dump(output1->Compute(1));
    std::cout << " // ";
    nts::Tristate_dump(output2->Compute(1));
    std::cout << std::endl;

    c4013->SetLink(4, *inputF, 1);
    c4013->SetLink(6, *inputT, 1);

    nts::Tristate_dump(output1->Compute(1));
    std::cout << " // ";
    nts::Tristate_dump(output2->Compute(1));
    std::cout << std::endl;

    c4013->SetLink(4, *inputT, 1);

    nts::Tristate_dump(output1->Compute(1));
    std::cout << " // ";
    nts::Tristate_dump(output2->Compute(1));
    std::cout << std::endl;

    std::cout << std::endl;

    c4013->SetLink(3, *inputT, 1);
    c4013->SetLink(4, *inputF, 1);
    c4013->SetLink(5, *inputF, 1);
    c4013->SetLink(6, *inputF, 1);

    nts::Tristate_dump(output1->Compute(1));
    std::cout << " // ";
    nts::Tristate_dump(output2->Compute(1));
    std::cout << std::endl;

    c4013->SetLink(3, *inputF, 1);

    nts::Tristate_dump(output1->Compute(1));
    std::cout << " // ";
    nts::Tristate_dump(output2->Compute(1));
    std::cout << std::endl;




    delete inputT;
    delete inputF;
    delete c4013;
    delete output1;
    delete output2;

    return (0);
}
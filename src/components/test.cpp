#include "Component.hpp"

int main()
{
    nts::IComponent *inputT = new nts::True();
    nts::IComponent *inputF = new nts::False();
    nts::IComponent *c4008 = new nts::c4008();
    nts::IComponent *output = new nts::Output();

    output->SetLink(1, *c4008, 11);

    c4008->SetLink(6, *inputT, 1);
    c4008->SetLink(7, *inputT, 1);
    c4008->SetLink(9, *inputT, 1);

///////////////////////////////////////////////

    c4008->SetLink(4, *inputT, 1);
    c4008->SetLink(5, *inputT, 1);
    nts::Tristate_dump(output->Compute(1));
    std::cout << std::endl;

    c4008->SetLink(4, *inputT, 1);
    c4008->SetLink(5, *inputF, 1);
    nts::Tristate_dump(output->Compute(1));
    std::cout << std::endl;

    c4008->SetLink(4, *inputF, 1);
    c4008->SetLink(5, *inputT, 1);
    nts::Tristate_dump(output->Compute(1));
    std::cout << std::endl;

    c4008->SetLink(4, *inputF, 1);
    c4008->SetLink(5, *inputF, 1);
    nts::Tristate_dump(output->Compute(1));
    std::cout << std::endl;


///////////////////////////////////////////////
///////////////////////////////////////////////

    c4008->SetLink(6, *inputT, 1);
    c4008->SetLink(7, *inputF, 1);
    c4008->SetLink(9, *inputF, 1);

///////////////////////////////////////////////

    c4008->SetLink(4, *inputT, 1);
    c4008->SetLink(5, *inputT, 1);
    nts::Tristate_dump(output->Compute(1));
    std::cout << std::endl;


    c4008->SetLink(4, *inputT, 1);
    c4008->SetLink(5, *inputF, 1);
    nts::Tristate_dump(output->Compute(1));
    std::cout << std::endl;

    c4008->SetLink(4, *inputF, 1);
    c4008->SetLink(5, *inputT, 1);
    nts::Tristate_dump(output->Compute(1));
    std::cout << std::endl;

    c4008->SetLink(4, *inputF, 1);
    c4008->SetLink(5, *inputF, 1);
    nts::Tristate_dump(output->Compute(1));
    std::cout << std::endl;

    delete inputT;
    delete inputF;
    delete c4008;
    delete output;

    return (0);
}
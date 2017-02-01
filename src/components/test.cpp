#include "Component.hpp"

int main()
{
    nts::IComponent *inputT = new nts::True();
    nts::IComponent *inputF = new nts::False();
    nts::IComponent *c4017 = new nts::c4017();
    nts::IComponent *output = new nts::Output();

    c4017->SetLink();

    delete inputT;
    delete inputF;
    delete c4017;
    delete output;

    return (0);
}
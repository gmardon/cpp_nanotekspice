#include "Input.hpp"

namespace nts
{
    Input::Input(const std::string &name, Tristate state) : name(name), pin(state)
    {
    }

/*
** A réfléchir: autoriser la copie ?
    Input::Input(const Input &)
    {

    }
*/
    Input::~Input()
    {
    }

/*
**
    const Input &Input::operator=(const Input &)
    {

    }
*/
    Tristate Input::Compute(std::size_t pin_num_this)
    {
        if (pin_num_this != 1)
            return (UNDEFINED);
        return (this->pin);
    }

    void Input::SetLink(std::size_t __attribute__ ((unused)) pin_num_this, IComponent & __attribute__ ((unused)) component, std::size_t  __attribute__ ((unused)) pin_num_target)
    {
    }

    void Input::Dump(void) const
    {
        std::cout << "Input, Input " << this->name << std::endl << "\tpin 1: " << this->pin << std::endl;
    }
}
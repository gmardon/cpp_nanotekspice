#include "Output.hpp"

namespace nts
{
    Output::Output(const std::string &name) : name(name), pin(UNDEFINED), link(0), pin_link(0)
    {
    }

/*
** A réfléchir: autoriser la copie ?
    Output::Output(const Output &)
    {

    }
*/
    Output::~Output()
    {
    }

/*
**
    const Output &Output::operator=(const Output &)
    {

    }
*/
    Tristate Output::Compute(std::size_t pin_num_this)
    {
        if (pin_num_this != 1 || !this->link)
            return (UNDEFINED);
        this->pin = this->link->Compute(this->pin_link);
        return(this->pin);
    }

    void Output::SetLink(std::size_t pin_num_this, IComponent & component, std::size_t pin_num_target)
    {
        if (pin_num_this == 1)
        {
            this->link = &component;
            this->pin_link = pin_num_target;
        }
    }

    void Output::Dump(void) const
    {
        std::cout << "Output, Output " << this->name << std::endl << "pin 1: " << this->pin << std::endl;
    }
}
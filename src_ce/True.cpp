#include "True.hpp"

namespace nts
{
    True::True(const std::string &name) : name(name)
    {
    }

/*
** A réfléchir: autoriser la copie ?
    True::True(const True &)
    {

    }
*/
    True::~True()
    {
    }

/*
**
    const True &True::operator=(const True &)
    {

    }
*/
    Tristate True::Compute(std::size_t pin_num_this)
    {
        if (pin_num_this != 1)
            return (UNDEFINED);
        return (TRUE);
    }

    void True::SetLink(std::size_t __attribute__ ((unused)) pin_num_this, IComponent & __attribute__ ((unused)) component, std::size_t  __attribute__ ((unused)) pin_num_target)
    {
    }

    void True::Dump(void) const
    {
        std::cout << "Input, True " << this->name << std::endl << "pin 1: " << TRUE << std::endl;
    }
}
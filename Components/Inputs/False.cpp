#include "False.hpp"

namespace nts
{
    False::False(const std::string &name) : name(name)
    {
    }

/*
** A réfléchir: autoriser la copie ?
    False::False(const False &)
    {

    }
*/
    False::~False()
    {
    }

/*
**
    const False &False::operator=(const False &)
    {

    }
*/
    Tristate False::Compute(std::size_t pin_num_this)
    {
        if (pin_num_this != 1)
            return (UNDEFINED);
        return (FALSE);
    }

    void False::SetLink(std::size_t __attribute__ ((unused)) pin_num_this, IComponent & __attribute__ ((unused)) component, std::size_t  __attribute__ ((unused)) pin_num_target)
    {
    }

    void False::Dump(void) const
    {
        std::cout << "Input, False " << this->name << std::endl << "pin 1: " << FALSE << std::endl;
    }
}
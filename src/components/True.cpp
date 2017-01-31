#include "True.hpp"

namespace nts
{
    True::True() : name("Input True")
    {
        this->pins[0].setMode(nts::Pin::I);
        this->pins[0].setState(TRUE);
    }

    nts::Tristate True::Compute(std::size_t pin_num_this)
    {
        if (pin_num_this != 1)
            return (UNDEFINED);
        return (this->pins[0].getState());
    }

    void True::SetLink(std::size_t pin_num_this, nts::IComponent &component, std::size_t pin_num_target)
    {
        if (pin_num_this != 1)
            return ;
        this->pins[0].setComponent(component);        
        this->pins[0].setTarget(pin_num_target);        
    }

    void True::Dump(void) const
    {
        std::cout << this->name << std::endl;
    }

    True::~True(void)
    {
    }
}
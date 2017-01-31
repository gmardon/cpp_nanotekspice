#include "c4001.hpp"

namespace nts
{
    c4001::c4001()
    {
        this->pins[0].setMode(nts::Pin::I);
        this->pins[1].setMode(nts::Pin::I);
        this->pins[2].setMode(nts::Pin::O);
        this->pins[3].setMode(nts::Pin::I);
        this->pins[4].setMode(nts::Pin::I);
        this->pins[5].setMode(nts::Pin::O);
        this->pins[6].setMode(nts::Pin::I);
        this->pins[7].setMode(nts::Pin::I);
        this->pins[8].setMode(nts::Pin::O);
        this->pins[9].setMode(nts::Pin::I);
        this->pins[10].setMode(nts::Pin::I);
        this->pins[11].setMode(nts::Pin::O);
    }

    nts::Tristate c4001::Compute(std::size_t pin_num_this)
    {
        if (pin_num_this < 1 || pin_num_this > 12)
            return (UNDEFINED);
        if (pin_num_this % 3)
            return (this->pins[pin_num_this - 1].compute());
        else
            return (this->pins[pin_num_this - 3].compute() && this->pins[pin_num_this - 2].compute());
    }

    void c4001::SetLink(std::size_t pin_num_this, nts::IComponent &component, std::size_t pin_num_target)
    {
        if (pin_num_this < 1 || pin_num_this > 12)
            return ;
        pin_num_this--;
        this->pins[pin_num_this].setComponent(component);        
        this->pins[pin_num_this].setTarget(pin_num_target);        
    }

    void c4001::Dump(void) const
    {
        std::cout << "Chipset 4001" << std::endl;
    }

    c4001::~c4001(void)
    {
    }
}
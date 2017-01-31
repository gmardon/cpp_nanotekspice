#include "c4081.hpp"

namespace nts
{
    c4081::c4081()
    {
        this->pins[0].setMode(nts::Pin::I);
        this->pins[1].setMode(nts::Pin::I);
        this->pins[2].setMode(nts::Pin::O);
        this->pins[3].setMode(nts::Pin::O);
        this->pins[4].setMode(nts::Pin::I);
        this->pins[5].setMode(nts::Pin::I);
        this->pins[6].setMode(nts::Pin::VSS);
        this->pins[7].setMode(nts::Pin::I);
        this->pins[8].setMode(nts::Pin::I);
        this->pins[9].setMode(nts::Pin::O);
        this->pins[10].setMode(nts::Pin::O);
        this->pins[11].setMode(nts::Pin::I);
        this->pins[12].setMode(nts::Pin::I);
        this->pins[13].setMode(nts::Pin::VDD);
    }

    nts::Tristate c4081::Compute(std::size_t pin_num_this)
    {
        if (pin_num_this < 1 || pin_num_this > 13 || pin_num_this == 7)
            return (UNDEFINED);
        pin_num_this--;
        if (this->pins[pin_num_this].getMode() == Pin::I)
            return (this->pins[pin_num_this].compute());
        else
        {
            Tristate t1 = this->pins[pin_num_this + ((pin_num_this % 2) ? (1) : (-1))].compute();
            Tristate t2 = this->pins[pin_num_this + ((pin_num_this % 2) ? (2) : (-2))].compute();
            return ((t1 && t2));
        }
    }

    void c4081::SetLink(std::size_t pin_num_this, nts::IComponent &component, std::size_t pin_num_target)
    {
        if (pin_num_this < 1 || pin_num_this > 13 || pin_num_this == 7)
            return ;
        pin_num_this--;
        this->pins[pin_num_this].setComponent(component);        
        this->pins[pin_num_this].setTarget(pin_num_target);        
    }

    void c4081::Dump(void) const
    {
        std::cout << "Chipset 4081" << std::endl;
    }

    c4081::~c4081(void)
    {
    }
}
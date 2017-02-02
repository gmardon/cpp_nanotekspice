#include "Clock.hpp"

namespace nts
{
    Clock::Clock()
    {
        this->pins[0].setMode(nts::Pin::I);
        this->pins[0].setState(FALSE);
    }

    nts::Tristate Clock::Compute(std::size_t pin_num_this)
    {
        if (pin_num_this != 1)
        {
            if (pin_num_this == 0)
                this->pins[0].setState(!this->pins[0].getState());
            return (UNDEFINED);
        }
        return (this->pins[0].getState());
    }

    void Clock::SetLink(std::size_t pin_num_this, nts::IComponent &component, std::size_t pin_num_target)
    {
        if (pin_num_this != 1)
            return ;
        this->pins[0].setComponent(component);        
        this->pins[0].setTarget(pin_num_target);        
    }

    void Clock::Dump(void) const
    {
        std::cout << "Input Clock" << std::endl;
    }

    Clock::~Clock(void)
    {
    }
}
#include "Clock.hpp"

namespace nts
{
    Clock::Clock(const std::string &)
    {
        this->name = "Clock";
        this->type = nts::AComponent::Type::T;
        this->pins.push_back(Pin{nts::Pin::O});
        this->pins[0].setState(FALSE);
    }

    nts::Tristate Clock::Compute(std::size_t pin_num_this)
    {
       if (pin_num_this != 1)
        {
            if (pin_num_this == 0)
                this->pins[0].setState(!this->pins[0].getState());
            else if (pin_num_this == 2)
                this->pins[0].setState(TRUE);
            else if (pin_num_this == 3)
                this->pins[0].setState(FALSE);
            else
                throw Error ("Attempt to compute an invalid pin number", this->name + " " + std::to_string(pin_num_this));
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
        std::cout << "Input " << this->name << std::endl;
    }

    const std::string &Clock::save() const
    {
        return (*(new std::string ("clock " + this->name)));
    }

    Clock::~Clock(void)
    {
    }
}
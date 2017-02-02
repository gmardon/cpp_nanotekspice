#include "Input.hpp"

namespace nts
{
    Input::Input(Tristate _state)
    {
        this->name = "Trigger";
        this->pins.push_back(Pin{nts::Pin::I});
        this->pins[0].setState(_state);
    }

    nts::Tristate Input::Compute(std::size_t pin_num_this)
    {
        if (pin_num_this != 1)
        {
            if (pin_num_this == 2)
                this->pins[0].setState(TRUE);
            else if (pin_num_this == 3)
                this->pins[0].setState(FALSE);
            return (UNDEFINED);
        }
        return (this->pins[0].getState());
    }

    void Input::SetLink(std::size_t pin_num_this, nts::IComponent &component, std::size_t pin_num_target)
    {
        if (pin_num_this != 1)
            return ;
        this->pins[0].setComponent(component);        
        this->pins[0].setTarget(pin_num_target);        
    }

    void Input::Dump(void) const
    {
        std::cout << "Input " << this->name << std::endl;
    }

    Input::~Input(void)
    {
    }
}
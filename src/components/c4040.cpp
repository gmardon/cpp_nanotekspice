#include "c4040.hpp"

namespace nts
{
    c4040::c4040(const std::string &) : value(0), prevClock(FALSE)
    {
        this->name = "4040";
        this->type = nts::AComponent::Type::C;
        this->pins.push_back(Pin{nts::Pin::O});
        this->pins.push_back(Pin{nts::Pin::O});
        this->pins.push_back(Pin{nts::Pin::O});
        this->pins.push_back(Pin{nts::Pin::O});
        this->pins.push_back(Pin{nts::Pin::O});
        this->pins.push_back(Pin{nts::Pin::O});
        this->pins.push_back(Pin{nts::Pin::O});
        this->pins.push_back(Pin{nts::Pin::VSS});
        this->pins.push_back(Pin{nts::Pin::O});
        this->pins.push_back(Pin{nts::Pin::I});
        this->pins.push_back(Pin{nts::Pin::I});
        this->pins.push_back(Pin{nts::Pin::O});
        this->pins.push_back(Pin{nts::Pin::O});
        this->pins.push_back(Pin{nts::Pin::O});
        this->pins.push_back(Pin{nts::Pin::O});
        this->pins.push_back(Pin{nts::Pin::VDD});
    }

    nts::Tristate c4040::Compute(std::size_t pin_num_this)
    {
        if (pin_num_this < 1 || pin_num_this > 15 || pin_num_this == 8)
            return (UNDEFINED);
        pin_num_this--;
        if (this->pins[pin_num_this].getMode() == Pin::I)
            return (this->pins[pin_num_this].compute());
        Tristate C = this->pins[9].compute();
        Tristate R = this->pins[10].compute();
        if (C == UNDEFINED || R == UNDEFINED)
            return (UNDEFINED);
        else if (R == TRUE)
            this->value = 0;
        else if (C == FALSE && this->prevClock == TRUE)
            this->value = (this->value + 1) % 10;
        this->prevClock = C;
        std::vector<int> values = {{12, 6, 5, 7, 4, 3, 2, 0, 1, 0, 0, 9, 8}};
        int val = values[pin_num_this];
        if ((this->value >> val) & 1)
            return (TRUE);
        else
            return (FALSE);
    }

    void c4040::SetLink(std::size_t pin_num_this, nts::IComponent &component, std::size_t pin_num_target)
    {
        if (pin_num_this < 1 || pin_num_this > 15 || pin_num_this == 8)
            return ;
        pin_num_this--;
        this->pins[pin_num_this].setComponent(component);        
        this->pins[pin_num_this].setTarget(pin_num_target);        
    }

    void c4040::Dump(void) const
    {
        std::cout << "Chipset " << this->name << std::endl;
    }

    c4040::~c4040(void)
    {
    }
}
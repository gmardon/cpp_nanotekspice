#include "c4017.hpp"

namespace nts
{
    c4017::c4017() : value(0), prevClock0(FALSE), prevClock1(FALSE)
    {
        this->name = "4017";
        this->pins.push_back(Pin{nts::Pin::O});
        this->pins.push_back(Pin{nts::Pin::O});
        this->pins.push_back(Pin{nts::Pin::O});
        this->pins.push_back(Pin{nts::Pin::O});
        this->pins.push_back(Pin{nts::Pin::O});
        this->pins.push_back(Pin{nts::Pin::O});
        this->pins.push_back(Pin{nts::Pin::O});
        this->pins.push_back(Pin{nts::Pin::VSS});
        this->pins.push_back(Pin{nts::Pin::O});
        this->pins.push_back(Pin{nts::Pin::O});
        this->pins.push_back(Pin{nts::Pin::O});
        this->pins.push_back(Pin{nts::Pin::O});
        this->pins.push_back(Pin{nts::Pin::I});
        this->pins.push_back(Pin{nts::Pin::I});
        this->pins.push_back(Pin{nts::Pin::I});
        this->pins.push_back(Pin{nts::Pin::VDD});
    }

    nts::Tristate c4017::Compute(std::size_t pin_num_this)
    {
        if (pin_num_this < 1 || pin_num_this > 15 || pin_num_this == 8)
            return (UNDEFINED);
        pin_num_this--;
        if (this->pins[pin_num_this].getMode() == Pin::I)
            return (this->pins[pin_num_this].compute());
        Tristate C0 = this->pins[13].compute();
        Tristate C1 = this->pins[12].compute();
        Tristate MR = this->pins[14].compute();
        if (C0 == UNDEFINED || C1 == UNDEFINED || MR == UNDEFINED)
            return (UNDEFINED);
        else if (MR == TRUE)
            this->value = 0;
        else if (C1 == FALSE && C0 == TRUE && (this->prevClock0 == FALSE || this->prevClock1 == TRUE))
            this->value = (this->value + 1) % 10;
        this->prevClock0 = C0;
        this->prevClock1 = C1;
        std::vector<int> values = {{5, 1, 0, 2, 6, 7, 3, 0, 8, 4, 9}};
        if (values[pin_num_this] == this->value || (pin_num_this == 11 && this->value < 5))
            return (TRUE);
        else
            return (FALSE);
    }

    void c4017::SetLink(std::size_t pin_num_this, nts::IComponent &component, std::size_t pin_num_target)
    {
        if (pin_num_this < 1 || pin_num_this > 15 || pin_num_this == 8)
            return ;
        pin_num_this--;
        this->pins[pin_num_this].setComponent(component);        
        this->pins[pin_num_this].setTarget(pin_num_target);        
    }

    void c4017::Dump(void) const
    {
        std::cout << "Chipset " << this->name << std::endl;
    }

    c4017::~c4017(void)
    {
    }
}
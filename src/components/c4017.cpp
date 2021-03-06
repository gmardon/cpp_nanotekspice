#include "c4017.hpp"

namespace nts
{
    c4017::c4017(const std::string &) : value(0), changed(0), prevClock0(FALSE), prevClock1(FALSE)
    {
        this->name = "4017";
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
        if (pin_num_this == 0)
        {
            this->changed = 0;
            return (this->reset_pins());
        }
        if (pin_num_this < 1 || pin_num_this > 15 || pin_num_this == 8)
            throw Error ("Attempt to compute an invalid pin number", this->name + " " + std::to_string(pin_num_this));
        pin_num_this--;
        if (this->pins[pin_num_this].getMode() == Pin::I)
            return (this->pins[pin_num_this].compute());
        // Tristate C0 = this->pins[12].compute();
        Tristate C1 = this->pins[13].compute();
        Tristate MR = this->pins[14].compute();
        if (/*C0 == UNDEFINED || */C1 == UNDEFINED || MR == UNDEFINED)
            return (UNDEFINED);
        else if (MR == TRUE)
            this->value = 0;
        else if (C1 == TRUE && /*C0 == FALSE && */(/*this->prevClock0 == TRUE || */this->prevClock1 == FALSE) && !this->changed)
        {
            this->changed = 1;
            this->value = (this->value + 1) % 10;
        }
        // this->prevClock0 = C0;
        this->prevClock1 = C1;
        std::vector<int> values = {{5, 1, 0, 2, 6, 7, 3, 0, 8, 4, 9, 0, 0}};
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

    const std::string &c4017::save() const
    {
        return (*(new std::string ("4017 " + this->name)));
    }

    c4017::~c4017(void)
    {
    }
}
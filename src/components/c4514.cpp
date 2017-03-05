#include "c4514.hpp"

namespace nts
{
    c4514::c4514(const std::string &) : value(0), prevClock(FALSE)
    {
        this->name = "4514";
        this->type = nts::AComponent::Type::C;
        this->pins.push_back(Pin{nts::Pin::I});
        this->pins.push_back(Pin{nts::Pin::I});
        this->pins.push_back(Pin{nts::Pin::I});
        this->pins.push_back(Pin{nts::Pin::O});
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
        this->pins.push_back(Pin{nts::Pin::O});
        this->pins.push_back(Pin{nts::Pin::O});
        this->pins.push_back(Pin{nts::Pin::O});
        this->pins.push_back(Pin{nts::Pin::O});
        this->pins.push_back(Pin{nts::Pin::I});
        this->pins.push_back(Pin{nts::Pin::I});
        this->pins.push_back(Pin{nts::Pin::I});
        this->pins.push_back(Pin{nts::Pin::VDD});
    }

    nts::Tristate c4514::Compute(std::size_t pin_num_this)
    {
        if (pin_num_this < 1 || pin_num_this > 23 || pin_num_this == 12)
            return (UNDEFINED);
        pin_num_this--;
        if (this->pins[pin_num_this].getMode() == Pin::I)
            return (this->pins[pin_num_this].compute());
        else
        {
            if (this->pins[22].compute() == TRUE)
                return (FALSE);
            if (this->pins[22].compute() == UNDEFINED || this->pins[0].compute() == UNDEFINED)
                return (FALSE);
            if (this->prevClock == TRUE && this->pins[0].compute() == FALSE)
            {
                if (this->pins[1].compute() == UNDEFINED || this->pins[2].compute() == UNDEFINED || this->pins[20].compute() == UNDEFINED || this->pins[21].compute() == UNDEFINED)
                    return (UNDEFINED);
                this->value = 0;
                if (this->pins[1].compute() == TRUE)
                    this->value += 1;
                if (this->pins[2].compute() == TRUE)
                    this->value += 2;
                if (this->pins[20].compute() == TRUE)
                    this->value += 4;
                if (this->pins[21].compute() == TRUE)
                    this->value += 8;
            }
            this->prevClock = this->pins[0].compute();
            std::vector<unsigned long int> values = {{11, 9, 10, 8, 7, 6, 5, 4, 18, 17, 20, 19, 14, 13, 16, 15}};
            if (pin_num_this == values[this->value] - 1)
                return (TRUE);
            return (FALSE);
        }
    }

    void c4514::SetLink(std::size_t pin_num_this, nts::IComponent &component, std::size_t pin_num_target)
    {
        if (pin_num_this < 1 || pin_num_this > 23 || pin_num_this == 12)
            return ;
        pin_num_this--;
        this->pins[pin_num_this].setComponent(component);        
        this->pins[pin_num_this].setTarget(pin_num_target);        
    }

    void c4514::Dump(void) const
    {
        std::cout << "Chipset " << this->name << std::endl;
    }

    const std::string &c4514::save() const
    {
        return (*(new std::string ("4514 " + this->name)));
    }

    c4514::~c4514(void)
    {
    }
}
#include "c4013.hpp"

namespace nts
{
    c4013::c4013(const std::string &)
    {
        this->name = "4013";
        this->type = "4013";
        this->pins.push_back(Pin{nts::Pin::O});
        this->pins.push_back(Pin{nts::Pin::O});
        this->pins.push_back(Pin{nts::Pin::I});
        this->pins.push_back(Pin{nts::Pin::I});
        this->pins.push_back(Pin{nts::Pin::I});
        this->pins.push_back(Pin{nts::Pin::I});
        this->pins.push_back(Pin{nts::Pin::VSS});
        this->pins.push_back(Pin{nts::Pin::I});
        this->pins.push_back(Pin{nts::Pin::I});
        this->pins.push_back(Pin{nts::Pin::I});
        this->pins.push_back(Pin{nts::Pin::I});
        this->pins.push_back(Pin{nts::Pin::O});
        this->pins.push_back(Pin{nts::Pin::O});
        this->pins.push_back(Pin{nts::Pin::VDD});
    }

    nts::Tristate c4013::Compute(std::size_t pin_num_this)
    {
        if (pin_num_this < 1 || pin_num_this > 13 || pin_num_this == 7)
            return (UNDEFINED);
        pin_num_this--;
        if (this->pins[pin_num_this].getMode() == Pin::I)
            return (this->pins[pin_num_this].compute());
        else
        {
            Tristate CL = this->pins[((pin_num_this < 3) ? (2) : (10))].compute();
            Tristate R = this->pins[((pin_num_this < 3) ? (3) : (9))].compute();
            Tristate D = this->pins[((pin_num_this < 3) ? (4) : (8))].compute();
            Tristate S = this->pins[((pin_num_this < 3) ? (5) : (7))].compute();
            if (R == UNDEFINED || S == UNDEFINED)
                return (UNDEFINED);
            if (R == TRUE && S == TRUE)
            {
                this->pins[((pin_num_this < 3) ? (0) : (12))].setState(TRUE);
                this->pins[((pin_num_this < 3) ? (1) : (11))].setState(TRUE);
                return (TRUE);
            }
            else if (R == TRUE || (D == FALSE && CL == TRUE))
            {
                this->pins[((pin_num_this < 3) ? (0) : (12))].setState(FALSE);
                this->pins[((pin_num_this < 3) ? (1) : (11))].setState(TRUE);
            }
            else if (S == TRUE || (D == TRUE && CL == TRUE))
            {
                this->pins[((pin_num_this < 3) ? (0) : (12))].setState(TRUE);
                this->pins[((pin_num_this < 3) ? (1) : (11))].setState(FALSE);
            }
            else if (D == UNDEFINED || CL == UNDEFINED)
                return (UNDEFINED);
            return (this->pins[pin_num_this].getState());
        }
    }

    void c4013::SetLink(std::size_t pin_num_this, nts::IComponent &component, std::size_t pin_num_target)
    {
        if (pin_num_this < 1 || pin_num_this > 13 || pin_num_this == 7)
            return ;
        pin_num_this--;
        this->pins[pin_num_this].setComponent(component);        
        this->pins[pin_num_this].setTarget(pin_num_target);        
    }

    void c4013::Dump(void) const
    {
        std::cout << "Chipset " << this->name << std::endl;
    }

    c4013::~c4013(void)
    {
    }
}
#include "Output.hpp"

namespace nts
{
    Output::Output() : name("Output")
    {
        this->pins[0].setMode(nts::Pin::O);
    }

    nts::Tristate Output::Compute(std::size_t pin_num_this)
    {
        if (pin_num_this != 1)
            return (UNDEFINED);
        return (this->pins[0].compute());
    }

    void Output::SetLink(std::size_t pin_num_this, nts::IComponent &component, std::size_t pin_num_target)
    {
        if (pin_num_this != 1)
            return ;
        this->pins[0].setComponent(component);        
        this->pins[0].setTarget(pin_num_target);        
    }

    void Output::Dump(void) const
    {
        std::cout << this->name << std::endl;
    }

    Output::~Output(void)
    {
    }
}
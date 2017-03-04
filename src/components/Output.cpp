#include "Output.hpp"

namespace nts
{
    Output::Output(const std::string &)
    {
        this->name = "Output";
        this->type = nts::AComponent::Type::O;
        this->pins.push_back(Pin{nts::Pin::I});
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
        std::cout << "Output " << this->name << std::endl;
    }

    Output::~Output(void)
    {
    }
}
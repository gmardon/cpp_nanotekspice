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
        if (pin_num_this == 0)
            return (this->reset_pins());
        if (pin_num_this != 1)
            throw Error ("Attempt to compute an invalid pin number", this->name + " " + std::to_string(pin_num_this));
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

    const std::string &Output::save() const
    {
        return (*(new std::string ("output " + this->name)));
    }

    Output::~Output(void)
    {
    }
}
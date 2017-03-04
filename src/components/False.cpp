#include "False.hpp"

namespace nts
{
    False::False(const std::string &)
    {
        this->name = "False";
        this->type = nts::AComponent::Type::IC;
        this->pins.push_back(Pin{nts::Pin::O});
        this->pins[0].setState(FALSE);
    }

    nts::Tristate False::Compute(std::size_t pin_num_this)
    {
        if (pin_num_this != 1)
            return (UNDEFINED);
        return (this->pins[0].getState());
    }

    void False::SetLink(std::size_t pin_num_this, nts::IComponent &component, std::size_t pin_num_target)
    {
        if (pin_num_this != 1)
            return ;
        this->pins[0].setComponent(component);        
        this->pins[0].setTarget(pin_num_target);        
    }

    void False::Dump(void) const
    {
        std::cout << "Input " << this->name << std::endl;
    }

    False::~False(void)
    {
    }
}
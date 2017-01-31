#include "Pin.hpp"

namespace nts
{
    Pin::Pin() : component(0), state(UNDEFINED), target_pin(0)
    {
    }

    Pin::Pin(const Pin &other) : component(&other.getComponent()), state(other.getState()), target_pin(other.getTargetPin())
    {
    }

    Pin::~Pin()
    {
    }

    const Pin &Pin::operator=(const Pin &other)
    {
        this->component = &other.getComponent();
        this->state = other.getState();
        this->target_pin = other.getTargetPin();
        return (*this);
    }

    void Pin::setComponent(IComponent &_component) {this->component = &_component;}

    void Pin::setTarget(std::size_t _target_pin) {this->target_pin = _target_pin;}

    void Pin::setState(Tristate _state) {this->state = _state;}

    IComponent &Pin::getComponent() const {return (*this->component);}

    std::size_t Pin::getTargetPin() const {return (this->target_pin);}

    Tristate Pin::getState() const {return (this->state);}
}

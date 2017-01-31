#include "Pin.hpp"

namespace nts
{
    Pin::Pin() : mode(U), component(0), state(UNDEFINED), target_pin(0)
    {
    }

    Pin::Pin(const Pin &other) : mode(other.getMode()), component(&other.getComponent()), state(other.getState()), target_pin(other.getTargetPin())
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

    void Pin::setMode(Mode _mode) {this->mode = _mode;}

    IComponent &Pin::getComponent() const {return (*this->component);}

    std::size_t Pin::getTargetPin() const {return (this->target_pin);}

    Tristate Pin::getState() const {return (this->state);}

    nts::Tristate Pin::compute() {return (this->component->Compute(this->target_pin));}

    Pin::Mode Pin::getMode() const {return (this->mode);}
}

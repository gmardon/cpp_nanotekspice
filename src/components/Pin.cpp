#include "Pin.hpp"

namespace nts
{
    Pin::Pin(Mode _mode) : mode(_mode), component(0), calculating(0), to_reset(1), state(UNDEFINED), target_pin(0)
    {
    }

    Pin::Pin(const Pin &other) : mode(other.getMode()), component(&other.getComponent()), calculating(0), to_reset(1), state(other.getState()), target_pin(other.getTargetPin())
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
        this->calculating = 0;
        this->to_reset = 1;
        return (*this);
    }

    void Pin::setComponent(IComponent &_component) {this->component = &_component;}

    void Pin::setTarget(std::size_t _target_pin) {this->target_pin = _target_pin;}

    void Pin::setState(Tristate _state) {this->state = _state;}

    void Pin::setMode(Mode _mode) {this->mode = _mode;}

    void Pin::setCalc(int _calc) {this->calculating = _calc;}

    bool Pin::isLinked() const
    {
        if (this->component)
            return (true);
        return (false);
    }

    IComponent &Pin::getComponent() const {return (*this->component);}

    std::size_t Pin::getTargetPin() const {return (this->target_pin);}

    int Pin::getReset() const {return (this->to_reset);}

    Tristate Pin::getState() const {return (this->state);}

    nts::Tristate Pin::compute()
    {
        if (this->state != UNDEFINED)
            return (this->state);
        if (this->component)
        {
            if (this->calculating)
            {
                this->calculating = 0;
                this->state = UNDEFINED;
                to_reset = 0;
                return (UNDEFINED);
            }
            this->calculating = 1;
            this->state = this->component->Compute(this->target_pin);
            this->calculating = 0;
            return (this->state);
        }
        throw Error("Attempt to compute a linkless pin.", "FLEMME DE DIRE OU");
    }

    Pin::Mode Pin::getMode() const {return (this->mode);}
}

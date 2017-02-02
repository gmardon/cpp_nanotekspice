#ifndef PIN_HPP_
# define PIN_HPP_

# include <string>
# include <iostream>

#include "IComponent.hpp"

namespace nts
{
    class Pin
    {
    public:
        enum Mode
        {
            U = 0,
            I,
            O,
            IO,
            VSS,
            VDD
        };

    public:
        Pin(Mode = U);
        Pin(const Pin &);
        ~Pin();
        const Pin &operator=(const Pin &);

    public:
        void setComponent(IComponent &);
        void setTarget(std::size_t);
        void setState(Tristate);
        void setMode(Mode);
        IComponent &getComponent() const;
        std::size_t getTargetPin() const;
        Tristate getState() const;
        Mode getMode() const;

    public:
        nts::Tristate compute();

    private:
        Mode mode;
        nts::IComponent *component;
        Tristate state;
        std::size_t target_pin;
    };
}

#endif
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
        Pin();
        Pin(const Pin &);
        ~Pin();
        const Pin &operator=(const Pin &);

    public:
        void setComponent(IComponent &);
        void setTarget(std::size_t);
        void setState(Tristate);
        IComponent &getComponent() const;
        std::size_t getTargetPin() const;
        Tristate getState() const;

    private:
        nts::IComponent *component;
        Tristate state;
        std::size_t target_pin;
    };
}

#endif
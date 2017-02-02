#ifndef CLOCK_HPP_
# define CLOCK_HPP_

# include <string>
# include <iostream>
# include <array>

# include "IComponent.hpp"
# include "Pin.hpp"
# include "Tristate.hpp"

namespace nts
{
    class Clock : public IComponent
    {
    public:
        Clock();
        virtual nts::Tristate Compute(std::size_t pin_num_this = 1);
        virtual void SetLink(std::size_t pin_num_this, nts::IComponent &component, std::size_t pin_num_target);
        virtual void Dump(void) const;
        virtual ~Clock(void);

    private:
        std::array<Pin, 1> pins;
    };
}

#endif
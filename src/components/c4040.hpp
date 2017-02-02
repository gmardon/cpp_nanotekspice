#ifndef c4040_HPP_
# define c4040_HPP_

# include <string>
# include <iostream>
# include <array>

# include "IComponent.hpp"
# include "Pin.hpp"
# include "Tristate.hpp"

namespace nts
{
    class c4040 : public IComponent
    {
    public:
        c4040();
        virtual nts::Tristate Compute(std::size_t pin_num_this = 1);
        virtual void SetLink(std::size_t pin_num_this, nts::IComponent &component, std::size_t pin_num_target);
        virtual void Dump(void) const;
        virtual ~c4040(void);

    private:
        int value;
        Tristate prevClock;
        std::array<Pin, 16> pins;
    };
}

#endif
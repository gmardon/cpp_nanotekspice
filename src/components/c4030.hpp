#ifndef c4030_HPP_
# define c4030_HPP_

# include <string>
# include <iostream>
# include <array>

# include "IComponent.hpp"
# include "Pin.hpp"
# include "Tristate.hpp"

namespace nts
{
    class c4030 : public IComponent
    {
    public:
        c4030();
        virtual nts::Tristate Compute(std::size_t pin_num_this = 1);
        virtual void SetLink(std::size_t pin_num_this, nts::IComponent &component, std::size_t pin_num_target);
        virtual void Dump(void) const;
        virtual ~c4030(void);

    private:
        std::array<Pin, 14> pins;
    };
}
#endif
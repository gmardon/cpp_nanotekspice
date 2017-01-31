#ifndef c4069_HPP_
# define c4069_HPP_

# include <string>
# include <iostream>
# include <array>

# include "IComponent.hpp"
# include "Pin.hpp"
# include "Tristate.hpp"

namespace nts
{
    class c4069 : public IComponent
    {
    public:
        c4069();
        virtual nts::Tristate Compute(std::size_t pin_num_this = 1);
        virtual void SetLink(std::size_t pin_num_this, nts::IComponent &component, std::size_t pin_num_target);
        virtual void Dump(void) const;
        virtual ~c4069(void);

    private:
        std::array<Pin, 14> pins;
    };
}
#endif
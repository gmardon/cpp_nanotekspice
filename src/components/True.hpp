#ifndef TRUE_HPP_
# define TRUE_HPP_

# include <string>
# include <iostream>
# include <array>

# include "IComponent.hpp"
# include "Pin.hpp"
# include "Tristate.hpp"

namespace nts
{
    class True : public IComponent
    {
    public:
        True();
        virtual nts::Tristate Compute(std::size_t pin_num_this = 1);
        virtual void SetLink(std::size_t pin_num_this, nts::IComponent &component, std::size_t pin_num_target);
        virtual void Dump(void) const;
        virtual ~True(void);

    private:
        std::string name;
        std::array<Pin, 1> pins;
    };
}

#endif
#ifndef c4081_HPP_
# define c4081_HPP_

# include "AComponent.hpp"

namespace nts
{
    class c4081 : public AComponent
    {
    public:
        c4081();
        virtual nts::Tristate Compute(std::size_t pin_num_this = 1);
        virtual void SetLink(std::size_t pin_num_this, nts::IComponent &component, std::size_t pin_num_target);
        virtual void Dump(void) const;
        virtual ~c4081(void);
    };
}
#endif
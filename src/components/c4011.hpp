#ifndef c4011_HPP_
# define c4011_HPP_

# include "AComponent.hpp"

namespace nts
{
    class c4011 : public AComponent
    {
    public:
        c4011();
        virtual nts::Tristate Compute(std::size_t pin_num_this = 1);
        virtual void SetLink(std::size_t pin_num_this, nts::IComponent &component, std::size_t pin_num_target);
        virtual void Dump(void) const;
        virtual ~c4011(void);
    };
}

#endif
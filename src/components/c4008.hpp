#ifndef c4008_HPP_
# define c4008_HPP_

# include "AComponent.hpp"

namespace nts
{
    class c4008 : public AComponent
    {
    public:
        c4008();
        virtual nts::Tristate Compute(std::size_t pin_num_this = 1);
        virtual void SetLink(std::size_t pin_num_this, nts::IComponent &component, std::size_t pin_num_target);
        virtual void Dump(void) const;
        virtual ~c4008(void);
    };
}

#endif
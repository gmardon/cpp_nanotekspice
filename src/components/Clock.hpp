#ifndef CLOCK_HPP_
# define CLOCK_HPP_

# include "AComponent.hpp"

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
    };
}

#endif
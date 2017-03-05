#ifndef c4514_HPP_
# define c4514_HPP_

# include "AComponent.hpp"

namespace nts
{
    class c4514 : public AComponent
    {
    public:
        c4514(const std::string & = "");
        virtual nts::Tristate Compute(std::size_t pin_num_this = 1);
        virtual void SetLink(std::size_t pin_num_this, nts::IComponent &component, std::size_t pin_num_target);
        virtual void Dump(void) const;
        virtual ~c4514(void);

    private:
        int value;
        Tristate prevClock;
    };
}

#endif
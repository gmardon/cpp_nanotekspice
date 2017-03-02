#ifndef c4030_HPP_
# define c4030_HPP_

# include "AComponent.hpp"

namespace nts
{
    class c4030 : public AComponent
    {
    public:
        c4030(const std::string & = "");
        virtual nts::Tristate Compute(std::size_t pin_num_this = 1);
        virtual void SetLink(std::size_t pin_num_this, nts::IComponent &component, std::size_t pin_num_target);
        virtual void Dump(void) const;
        virtual ~c4030(void);
    };
}
#endif
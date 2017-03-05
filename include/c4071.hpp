#ifndef c4071_HPP_
# define c4071_HPP_

# include "AComponent.hpp"

namespace nts
{
    class c4071 : public AComponent
    {
    public:
        c4071(const std::string & = "");
        virtual nts::Tristate Compute(std::size_t pin_num_this = 1);
        virtual void SetLink(std::size_t pin_num_this, nts::IComponent &component, std::size_t pin_num_target);
        virtual void Dump(void) const;
        virtual ~c4071(void);
        virtual const std::string &save() const;
    };
}
#endif
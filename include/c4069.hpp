#ifndef c4069_HPP_
# define c4069_HPP_

# include "AComponent.hpp"

namespace nts
{
    class c4069 : public AComponent
    {
    public:
        c4069(const std::string & = "");
        virtual nts::Tristate Compute(std::size_t pin_num_this = 1);
        virtual void SetLink(std::size_t pin_num_this, nts::IComponent &component, std::size_t pin_num_target);
        virtual void Dump(void) const;
        virtual ~c4069(void);
        virtual const std::string &save() const;
    };
}
#endif
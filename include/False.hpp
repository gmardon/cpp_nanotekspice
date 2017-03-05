#ifndef FALSE_HPP_
# define FALSE_HPP_

# include "AComponent.hpp"

namespace nts
{
    class False : public AComponent
    {
    public:
        False(const std::string & = "");
        virtual nts::Tristate Compute(std::size_t pin_num_this = 1);
        virtual void SetLink(std::size_t pin_num_this, nts::IComponent &component, std::size_t pin_num_target);
        virtual void Dump(void) const;
        virtual ~False(void);
        virtual const std::string &save() const;
    };
}

#endif
#ifndef c4040_HPP_
# define c4040_HPP_

# include "AComponent.hpp"

namespace nts
{
    class c4040 : public AComponent
    {
    public:
        c4040(const std::string & = "");
        virtual nts::Tristate Compute(std::size_t pin_num_this = 1);
        virtual void SetLink(std::size_t pin_num_this, nts::IComponent &component, std::size_t pin_num_target);
        virtual void Dump(void) const;
        virtual ~c4040(void);
        virtual const std::string &save() const;

    private:
        int value;
        Tristate prevClock;
    };
}

#endif
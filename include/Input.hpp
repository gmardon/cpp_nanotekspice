#ifndef INPUT_HPP_
# define INPUT_HPP_

# include "AComponent.hpp"

namespace nts
{
    class Input : public AComponent
    {
    public:
        Input(const std::string & = "");
        virtual nts::Tristate Compute(std::size_t pin_num_this = 1);
        virtual void SetLink(std::size_t pin_num_this, nts::IComponent &component, std::size_t pin_num_target);
        virtual void Dump(void) const;
        virtual ~Input(void);
    };
}

#endif
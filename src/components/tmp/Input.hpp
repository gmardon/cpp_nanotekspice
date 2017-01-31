#ifndef INPUT_HPP_
# define INPUT_HPP_

# include <string>
# include <iostream>

# include "IComponent.hpp"

namespace nts
{
    class Input : public IComponent
    {
    public:
        Input(const std::string & = *new std::string(), Tristate = UNDEFINED);
        Input(const Input &);
        ~Input();
        const Input &operator=(const Input &);

    public:
        virtual nts::Tristate Compute(std::size_t pin_num_this = 1);
        virtual void SetLink(std::size_t pin_num_this, nts::IComponent &component, std::size_t pin_num_target);
        virtual void Dump(void) const;

    private:
        std::string name;
        Tristate pin;
    };
}

#endif
#ifndef TRUE_HPP_
# define TRUE_HPP_

# include <string>
# include <iostream>

# include "IComponent.hpp"

namespace nts
{
    class True : public IComponent
    {
    public:
        True(const std::string & = *new std::string());
        True(const True &);
        ~True();
        const True &operator=(const True &);

    public:
        virtual nts::Tristate Compute(std::size_t pin_num_this = 1);
        virtual void SetLink(std::size_t pin_num_this, nts::IComponent &component, std::size_t pin_num_target);
        virtual void Dump(void) const;

    private:
        std::string name;
    };
}

#endif
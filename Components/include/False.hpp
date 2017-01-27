#ifndef FALSE_HPP_
# define FALSE_HPP_

# include <string>
# include <iostream>

# include "IComponent.hpp"

namespace nts
{
    class False : public IComponent
    {
    public:
        False(const std::string & = *new std::string());
        False(const False &);
        ~False();
        const False &operator=(const False &);

    public:
        virtual nts::Tristate Compute(std::size_t pin_num_this = 1);
        virtual void SetLink(std::size_t pin_num_this, nts::IComponent &component, std::size_t pin_num_target);
        virtual void Dump(void) const;

    private:
        std::string name;
    };
}

#endif
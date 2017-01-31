#ifndef OUTPUT_HPP_
# define OUTPUT_HPP_

# include <string>
# include <iostream>

# include "IComponent.hpp"

namespace nts
{
    class Output : public IComponent
    {
    public:
        Output(const std::string & = *new std::string());
        Output(const Output &);
        ~Output();
        const Output &operator=(const Output &);

    public:
        virtual nts::Tristate Compute(std::size_t pin_num_this = 1);
        virtual void SetLink(std::size_t pin_num_this, nts::IComponent &component, std::size_t pin_num_target);
        virtual void Dump(void) const;

    private:
        std::string name;
        Tristate pin;
        IComponent *link;
        size_t pin_link;
    };
}

#endif
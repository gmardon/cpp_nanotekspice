#ifndef ACOMPONENTS_HPP_
# define ACOMPONENTS_HPP_

# include <string>
# include <iostream>
# include <vector>

# include "IComponent.hpp"
# include "Pin.hpp"
# include "Tristate.hpp"

# include "ErrorParser.hpp"

namespace nts
{
    class AComponent : public IComponent
    {
    public:
        enum Type
        {
            U = 0,
            IC,
            I,
            T,
            C,
            O
        };

    public:
        virtual nts::Tristate Compute(std::size_t pin_num_this = 1) = 0;
        virtual void SetLink(std::size_t pin_num_this, nts::IComponent &component, std::size_t pin_num_target) = 0;
        virtual void Dump(void) const = 0;
        virtual ~AComponent(void) {}

    public:
        const std::string &getName() const;
        Type getType() const;
        const std::vector<Pin> &getPins() const;
        void setName(const std::string &);

    protected:
        Type type;
        std::string name;
        std::vector<Pin> pins;
    };
}

#endif
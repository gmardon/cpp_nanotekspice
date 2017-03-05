#ifndef ACOMPONENTS_HPP_
# define ACOMPONENTS_HPP_

# include <string>
# include <iostream>
# include <vector>

# include "IComponent.hpp"
# include "Pin.hpp"
# include "Tristate.hpp"

# include "Error.hpp"

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
        virtual const std::string &save() const = 0;

    public:
        const std::string &getName() const;
        const std::string &getArg() const;
        Type getType() const;
        const std::vector<Pin> &getPins() const;
        void setName(const std::string &);
        void setArg(const std::string &);
        const std::string *save_pins() const;
        nts::Tristate reset_pins();

    protected:
        Type type;
        std::string name;
        std::string arg;
        std::vector<Pin> pins;
    };
}

#endif
#ifndef ICOMPONENT_HPP_
# define ICOMPONENT_HPP_

# include <cstddef>

namespace nts
{
    enum Tristate
    {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };

    class IComponent
    {
    public:
        virtual nts::Tristate Compute(std::size_t pin_num_this = 1) = 0;
        virtual void SetLink(std::size_t pin_num_this, nts::IComponent &component, std::size_t pin_num_target) = 0;
        virtual void Dump(void) const = 0;
        virtual ~IComponent(void) {}
    };
}

#endif
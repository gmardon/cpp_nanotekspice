#ifndef TRISTATE_HPP_
# define TRISTATE_HPP_

# include <string>
# include <iostream>

#include "IComponent.hpp"

namespace nts
{
    Tristate operator!(const Tristate &);
    Tristate operator&&(const Tristate &, const Tristate &);
    Tristate operator||(const Tristate &, const Tristate &);
    void Tristate_dump(const Tristate &);
}

#endif
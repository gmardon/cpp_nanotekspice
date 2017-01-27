#include "Tristate.hpp"

std::ostream &operator<<(std::ostream &os, nts::Tristate state)
{
    if (state == nts::TRUE)
        os << "TRUE";
    else if (state == nts::FALSE)
        os << "FALSE";
    else
        os << "UNDEFINED";
    return (os);
}
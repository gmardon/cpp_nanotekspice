#include "Tristate.hpp"

namespace nts
{
    Tristate operator!(const Tristate &t)
    {
        if (t == TRUE)
            return (FALSE);
        else if (t == FALSE)
            return (TRUE);
        else
            return (UNDEFINED);
    }

    Tristate operator&&(const Tristate &t1, const Tristate &t2)
    {
        if (t1 == FALSE || t2 == FALSE)
            return (FALSE);
        else if (t1 == UNDEFINED || t2 == UNDEFINED)
            return (UNDEFINED);
        else
            return (TRUE);
    }

    Tristate operator||(const Tristate &t1, const Tristate &t2)
    {
        if (t1 == TRUE || t2 == TRUE)
            return (TRUE);
        else if (t1 == UNDEFINED || t2 == UNDEFINED)
            return (UNDEFINED);
        else
            return (FALSE);
    }

    void Tristate_dump(const Tristate &t)
    {
        if (t == TRUE)
            std::cout << "1";
        else if (t == FALSE)
            std::cout << "0";
        else
            std::cout << "UNDEFINED";
    }
}
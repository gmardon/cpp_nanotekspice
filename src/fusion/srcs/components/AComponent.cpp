#include "AComponent.hpp"

namespace nts
{
    const std::string &AComponent::getName() const {return (this->name);}

    const std::vector<Pin> &AComponent::getPins() const {return (this->pins);}
}
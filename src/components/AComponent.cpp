#include "AComponent.hpp"

namespace nts
{
    void AComponent::setName(const std::string &_name) {this->name = _name;}

    const std::string &AComponent::getName() const {return (this->name);}

    const std::vector<Pin> &AComponent::getPins() const {return (this->pins);}
}
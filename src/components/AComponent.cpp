#include "AComponent.hpp"

namespace nts
{
    void AComponent::setName(const std::string &_name) {this->name = _name;}

    void AComponent::setArg(const std::string &_arg) {this->arg = _arg;}

    const std::string &AComponent::getName() const {return (this->name);}

    const std::string &AComponent::getArg() const {return (this->arg);}

    AComponent::Type AComponent::getType() const {return (this->type);}

    const std::vector<Pin> &AComponent::getPins() const {return (this->pins);}

    nts::Tristate AComponent::reset_pins()
    {
        size_t i = 0;
        while (i < this->pins.size())
        {
            this->pins[i].setState(UNDEFINED);
            i++;
        }
        return (UNDEFINED);
    }

    const std::string *AComponent::save_pins() const
    {
        size_t i = 0;
        std::string *save = new std::string(); 
        while (i < this->pins.size())
        {
            if (this->pins[i].isLinked())
                *save += this->name + ":" + std::to_string(i + 1) + " " + dynamic_cast<AComponent &>(this->pins[i].getComponent()).getName() + ":" + std::to_string(this->pins[i].getTargetPin()) + "\n";
            i++;
        }
        return (save);
    }
}
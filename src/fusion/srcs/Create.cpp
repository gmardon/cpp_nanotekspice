#include "Create.hpp"

nts::IComponent * Create::createComponent(const std::string &type, const std::string &value)
{
    std::map<std::string, std::function<nts::IComponent *(const std::string &)>> data
    {
        {"4001", {[](const std::string &value) {return (new nts::c4001(value));}}},
        {"4081", {[](const std::string &value) {return (new nts::c4081(value));}}},
        {"true", {[](const std::string &value) {return (new nts::True(value));}}},
        {"false", {[](const std::string &value) {return (new nts::False(value));}}},
        {"output", {[](const std::string &value) {return (new nts::Output(value));}}}
    };
    static std::map<std::string, std::function<nts::IComponent *(const std::string &)>>::iterator it;
    if ((it = data.find(type)) != data.end())
        return (it->second(value));
    return (NULL);
}

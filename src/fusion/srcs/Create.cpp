#include "Create.hpp"

nts::IComponent * Create::createComponent(const std::string &type, const std::string &value)
{
    std::map<std::string, std::function<nts::IComponent *(const std::string &)>> data
    {
        {"true", {[](const std::string &value) {return (new nts::True(value));}}},
        {"false", {[](const std::string &value) {return (new nts::False(value));}}},
        {"input", {[](const std::string &value) {return (new nts::Input(value));}}},
        {"clock", {[](const std::string &value) {return (new nts::Clock(value));}}},
        {"output", {[](const std::string &value) {return (new nts::Output(value));}}},
        {"4001", {[](const std::string &value) {return (new nts::c4001(value));}}},
        {"4008", {[](const std::string &value) {return (new nts::c4008(value));}}},
        {"4011", {[](const std::string &value) {return (new nts::c4011(value));}}},
        {"4013", {[](const std::string &value) {return (new nts::c4013(value));}}},
        {"4017", {[](const std::string &value) {return (new nts::c4017(value));}}},
        {"4030", {[](const std::string &value) {return (new nts::c4030(value));}}},
        {"4040", {[](const std::string &value) {return (new nts::c4040(value));}}},
        {"4069", {[](const std::string &value) {return (new nts::c4069(value));}}},
        {"4071", {[](const std::string &value) {return (new nts::c4071(value));}}},
        {"4081", {[](const std::string &value) {return (new nts::c4081(value));}}},
        // {"4094", {[](const std::string &value) {return (new nts::c4094(value));}}},
        // {"4514", {[](const std::string &value) {return (new nts::c4514(value));}}},
        // {"4801", {[](const std::string &value) {return (new nts::c4801(value));}}},
        // {"2716", {[](const std::string &value) {return (new nts::c2716(value));}}}
    };
    static std::map<std::string, std::function<nts::IComponent *(const std::string &)>>::iterator it;
    if ((it = data.find(type)) != data.end())
        return (it->second(value));
    return (NULL);
}

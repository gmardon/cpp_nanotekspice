#ifndef COMMANDS_HPP_
# define COMMANDS_HPP_

# include <string>
# include <iostream>
# include <map>
# include <vector>
# include <regex>

#include "AComponent.hpp"

int launch(std::map<std::string, nts::IComponent *>, std::vector<nts::IComponent *>);

#endif
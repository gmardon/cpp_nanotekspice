#ifndef PARSER_HPP_
# define PARSER_HPP_

# include <string>
# include <iostream>
# include <fstream>
# include <regex>
# include <map>
# include <vector>

#include "Create.hpp"

std::map<std::string, nts::IComponent *> parser(const char *file);

#endif
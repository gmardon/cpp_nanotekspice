#include "ErrorParser.hpp"

ErrorParser::ErrorParser(const std::string &message, const std::string &indicator) noexcept : _message(message), _indicator(indicator)
{
}

const char *ErrorParser::what() const noexcept
{
    return (this->_message.c_str());
}

std::string const &ErrorParser::getIndicator() const noexcept
{
    return (this->_indicator);
}
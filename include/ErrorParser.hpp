#ifndef ERRORPARSER_HPP_
# define ERRORPARSER_HPP_

# include <string>
# include <iostream>
# include <exception>

class ErrorParser : public std::exception
{
    public:
        ErrorParser(const std::string & = "Unknow error.", const std::string & = "Unknow") noexcept;
        ~ErrorParser() noexcept {};
        std::string const &getIndicator() const noexcept;
        const char * what() const noexcept;

    private:
        std::string _message;
        std::string _indicator;
};


#endif
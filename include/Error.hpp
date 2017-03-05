#ifndef ERROR_HPP_
# define ERROR_HPP_

# include <string>
# include <iostream>
# include <exception>

class Error : public std::exception
{
    public:
        Error(const std::string & = "Unknow error.", const std::string & = "Unknow") noexcept;
        ~Error() noexcept {};
        std::string const &getIndicator() const noexcept;
        const char * what() const noexcept;

    private:
        std::string _message;
        std::string _indicator;
};


#endif
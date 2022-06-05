#pragma once

#include <stdexcept>

class HelpException : public std::runtime_error {
public:
    HelpException(const char* message);
};

#include "help_exception.h"

HelpException::HelpException(const char* message) : std::runtime_error(message) {
}

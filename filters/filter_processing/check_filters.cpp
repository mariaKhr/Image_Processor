#include "check_filters.h"
#include <stdexcept>
#include <unordered_map>
#include <unordered_set>

void CheckNameOfFilter(const std::string& name) {
    static const std::unordered_set<std::string> names = {"-crop", "-gs",   "-neg",    "-sharp",
                                                          "-edge", "-blur", "-crystal"};
    if (!names.contains(name)) {
        throw std::invalid_argument("Invalid name of filter " + name);
    }
}

void CheckNumOfParams(const std::string& name, size_t num) {
    static const std::unordered_map<std::string, size_t> num_to_name = {
        {"-crop", 2}, {"-gs", 0}, {"-neg", 0}, {"-sharp", 0}, {"-edge", 1}, {"-blur", 1}, {"-crystal", 1}};
    if (num_to_name.at(name) != num) {
        throw std::invalid_argument("Invalid number of parameters for the filter " + name);
    }
}

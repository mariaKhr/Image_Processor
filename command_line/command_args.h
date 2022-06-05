#pragma once

#include "../filters/filter_info.h"
#include <string>
#include <vector>

class CommandArgs {
public:
    CommandArgs(int argc, char* argv[]);
    const std::string& InputPath() const;
    const std::string& OutputPath() const;
    const std::vector<FilterInfo>& Filters() const;

private:
    std::string input_path_;
    std::string output_path_;
    std::vector<FilterInfo> filters_info_;
};

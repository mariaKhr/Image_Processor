#include "command_args.h"
#include "help_exception.h"

CommandArgs::CommandArgs(int argc, char* argv[]) {
    if (argc == 1) {
        throw HelpException(
            "You need to enter the path to the input file, the path to the output file, filters in the following "
            "format:\n '-crop width height'\n '-gs'\n '-neg'\n '-sharp'\n '-edge threshold'\n '-blur sigma'\n "
            "'-crystal cnt'\n");
    }

    if (argc < 3) {
        throw std::invalid_argument("Too less arguments in command line");
    }

    input_path_ = argv[1];
    output_path_ = argv[2];

    FilterInfo current_filter;
    for (int i = 3; i < argc; ++i) {
        if (argv[i][0] == '-') {
            if (!current_filter.Empty()) {
                filters_info_.push_back(current_filter);
                current_filter.Clear();
            }
            current_filter.SetName(argv[i]);

        } else {
            try {
                current_filter.AddParam(std::stof(argv[i]));
            } catch (const std::invalid_argument& exc) {
                throw std::invalid_argument(argv[i]);
            }
        }
    }
    if (!current_filter.Empty()) {
        filters_info_.push_back(current_filter);
    }
}

const std::string& CommandArgs::InputPath() const {
    return input_path_;
}

const std::string& CommandArgs::OutputPath() const {
    return output_path_;
}

const std::vector<FilterInfo>& CommandArgs::Filters() const {
    return filters_info_;
}

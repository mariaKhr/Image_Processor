#include "bmp/read_bmp.h"
#include "bmp/write_bmp.h"
#include "command_line/command_args.h"
#include "command_line/help_exception.h"
#include "filters/filter_processing/process_filters.h"
#include <iostream>

int main(int argc, char* argv[]) {
    try {
        CommandArgs command_args(argc, argv);
        const std::string& input_file = command_args.InputPath();
        const std::string& output_file = command_args.OutputPath();
        const std::vector<FilterInfo>& filters = command_args.Filters();

        Image image = ReadBMP(input_file);
        ProcessFilters(filters, image);

        WriteBMP(output_file, image);

    } catch (const HelpException& exc) {
        std::cout << "Help: " << exc.what() << std::endl;
        return 0;

    } catch (const std::runtime_error& err) {
        std::cerr << "Runtime error: " << err.what() << std::endl;
        return 1;

    } catch (const std::invalid_argument& err) {
        std::cerr << "Invalid argument: " << err.what() << std::endl;
        return 1;

    } catch (const std::out_of_range& err) {
        std::cerr << "Out of range: " << err.what() << std::endl;
        return 1;

    } catch (...) {
        std::cerr << "Error!" << std::endl;
        return 1;
    }

    return 0;
}

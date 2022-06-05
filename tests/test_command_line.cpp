#include <catch.hpp>

#include "../command_line/command_args.h"
#include "command_line/help_exception.h"
#include <string.h>

TEST_CASE("FewArguments") {
    char* argv1[0];
    REQUIRE_THROWS_AS(CommandArgs(1, argv1), HelpException);

    char* argv2[1];
    REQUIRE_THROWS(CommandArgs(2, argv2));
}

TEST_CASE("Path") {
    char* program_name = strdup("./image_processor");
    char* input_path = strdup("input.bmp");
    char* output_path = strdup("output.bmp");
    char* argv[3] = {program_name, input_path, output_path};
    CommandArgs command_args(3, argv);
    REQUIRE(command_args.InputPath() == "input.bmp");
    REQUIRE(command_args.OutputPath() == "output.bmp");
}

TEST_CASE("Filters") {
    char* program_name = strdup("./image_processor");
    char* input_path = strdup("input.bmp");
    char* output_path = strdup("output.bmp");
    char* filter1 = strdup("-f1");
    char* param1 = strdup("0.5");
    char* param2 = strdup("23");
    char* filter2 = strdup("-f2");
    char* argv[7] = {program_name, input_path, output_path, filter1, param1, param2, filter2};
    CommandArgs command_args(7, argv);
    auto filters = command_args.Filters();

    REQUIRE(filters.size() == 2);
    REQUIRE(filters[0].GetName() == "-f1");
    REQUIRE(filters[0].NumOfParams() == 2);
    REQUIRE(filters[0].GetParamAt(0) == 0.5);
    REQUIRE(filters[0].GetParamAt(1) == 23.0);
    REQUIRE(filters[1].GetName() == "-f2");
    REQUIRE(filters[1].NumOfParams() == 0);
}

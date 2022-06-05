cmake_minimum_required(VERSION 3.17)
project(image_processor)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

add_executable(image_processor
        image_processor.cpp
        command_line/command_args.cpp
        command_line/command_args.h
        command_line/help_exception.cpp
        command_line/help_exception.h
        bmp/read_bmp.cpp
        bmp/write_bmp.cpp
        bmp/read_bmp.h
        bmp/write_bmp.h
        matrix/matrix.h
        image/image.h
        image/pixel.cpp
        image/pixel.h
        filters/filter_info.h
        filters/filter_info.cpp
        filters/filter.h
        filters/filter_processing/process_filters.cpp
        filters/filter_processing/process_filters.h
        filters/filter_processing/check_filters.cpp
        filters/filter_processing/check_filters.h
        filters/simple_filter/crop.cpp
        filters/simple_filter/crop.h
        filters/simple_filter/grayscale.cpp
        filters/simple_filter/grayscale.h
        filters/simple_filter/negative.cpp
        filters/simple_filter/negative.h
        filters/matrix_filter/matrix_filter.h
        filters/matrix_filter/matrix_filter.cpp
        filters/matrix_filter/sharpening.cpp
        filters/matrix_filter/sharpening.h
        filters/other_filter/edge.cpp
        filters/other_filter/edge.h
        filters/matrix_filter/blur.cpp
        filters/matrix_filter/blur.h
        filters/other_filter/crystallize.cpp
        filters/other_filter/crystallize.h)

add_catch(test_pixel
        image/pixel.cpp
        tests/test_pixel.cpp)

add_catch(test_matrix
        tests/test_matrix.cpp)

add_catch(test_image
        image/pixel.cpp
        tests/test_image.cpp)

add_catch(test_command_line
        command_line/command_args.cpp
        command_line/help_exception.cpp
        filters/filter_info.cpp
        tests/test_command_line.cpp)

add_catch(test_filters
        image/pixel.cpp
        filters/matrix_filter/matrix_filter.cpp
        filters/simple_filter/crop.cpp
        filters/simple_filter/grayscale.cpp
        filters/simple_filter/negative.cpp
        filters/matrix_filter/blur.cpp
        filters/matrix_filter/sharpening.cpp
        filters/other_filter/edge.cpp
        tests/test_filters.cpp)

add_catch(test_bmp
        image/pixel.cpp
        bmp/read_bmp.cpp
        bmp/write_bmp.cpp
        tests/test_bmp.cpp)

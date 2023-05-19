/**
 * @mainpage C++ Formatted Printing Project
 *
 * @section description_main Description
 * A C++ program that demonstrates the new formatting and printing capabilities
 * in the C++20 and C++23 specifications.
 *
 * @section notes_main Notes
 * - The C++20 and C++23 specifications are still experimental at this time;
 *   their usage may change in the future.
 * - Update the CFLAGS variable in the Makefile to compile to the desired
 *   C++ standard.
 *   - Use the -std=c++20 argument to include the C++20 <format> library's
 *     std:format function.
 *   - Use the -std=c++23 argument to include the C++20 <format> library's
 *     std:format function and the C++23 <print> library's std::print and
 *     std::println functions when they become available.
 * - Run *make help* to view Makefile run options.
 *
 * Copyright (c) 2023 Woolsey Workshop.  All rights reserved.
 */


/**
 * @file formatted_output.h
 *
 * @brief The main program header file.
 *
 * @section description_formatted_output_h Description
 * The main program header file.
 *
 * @section libraries_formatted_output_h Libraries
 * - *climits* Standard Library
 *   - https://en.cppreference.com/w/cpp/header/climits
 *   - Provides access to the *INT_MAX* macro.
 * - *cstdio* Standard Library
 *   - https://en.cppreference.com/w/cpp/header/cstdio
 *   - Provides access to the *printf* function.
 * - *format* Standard Library
 *   - https://en.cppreference.com/w/cpp/header/format
 *   - Provides access to the *format* function.
 *   - Available in the C++20 specification.
 * - *iomanip* Standard Library
 *   - https://en.cppreference.com/w/cpp/header/iomanip
 *   - Provides access to the *setprecision* and *setw* functions.
 * - *iostream* Standard Library
 *   - https://en.cppreference.com/w/cpp/header/iostream
 *   - Provides access to the *cout*, *endl*, and *fixed* objects.
 * - *print* Standard Library
 *   - https://en.cppreference.com/w/cpp/header/print
 *   - Provides access to the *print* and *println* functions.
 *   - Available in the C++23 specification.
 * - *string* Standard Library
 *   - https://en.cppreference.com/w/cpp/header/string
 *   - Provides access to the *string* class.
 *
 * @section notes_formatted_output_h Notes
 * - Source file comments are Doxygen compatible.
 *
 * @section todo_formatted_output_h TODO
 * - None.
 *
 * @section author_formatted_output_h Author(s)
 * - Created by John Woolsey on 05-01-2023.
 * - Modified by John Woolsey on 05-15-2023.
 *
 * Copyright (c) 2023 Woolsey Workshop.  All rights reserved.
 */


#ifndef FORMATTED_OUTPUT_H
#define FORMATTED_OUTPUT_H


// Includes
#include <climits>   // INT_MAX
#include <cstdio>    // printf
#include <iomanip>   // std::setprecision, std::setw
#include <iostream>  // std::cout, std::endl, std::fixed
#include <string>    // std::string

// Check availability of <format> and <print> libraries
#ifdef __has_include            // check if __has_include is available
   #if __has_include(<format>)  // check for <format> in standard library
      #include <format>         // std::format()
   #else                        // <format> library not found
      #warning "The <format> library is not available."
   #endif
   #if __has_include(<print>)   // check for <print> in standard library
      #include <print>          // std::print(), std::println()
   #else                        // <print> library not found
      #warning "The <print> library is not available."
   #endif
#else
   #warning "The __has_include check is not available."
#endif


// Defines
#ifndef M_PI
   #define M_PI 3.14159265358979323846
#endif


// Prototypes
void c_standard(std::string string_value,
                std::string int_name, int int_value,
                std::string float_name, float float_value);
void cpp_standard(std::string string_value,
                  std::string int_name, int int_value,
                  std::string float_name, float float_value);
void cpp_format(std::string string_value,
                std::string int_name, int int_value,
                std::string float_name, float float_value);
void cpp_print(std::string string_value,
               std::string int_name, int int_value,
               std::string float_name, float float_value);


#endif  // FORMATTED_OUTPUT_H

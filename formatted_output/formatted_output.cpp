/**
 * @file formatted_output.cpp
 *
 * @brief The main program implementation file.
 *
 * @section description_formatted_output_cpp Description
 * The main program implementation file.
 *
 * @section notes_formatted_output_cpp Notes
 * - Source file comments are Doxygen compatible.
 *
 * @section todo_formatted_output_cpp TODO
 * - None.
 *
 * @section author_formatted_output_cpp Author(s)
 * - Created by John Woolsey on 05-01-2023.
 * - Modified by John Woolsey on 05-03-2023.
 *
 * Copyright (c) 2023 Woolsey Workshop.  All rights reserved.
 */


// Includes
#include "formatted_output.h"


/**
 * Main function.
 *
 * Calls the various formatting demonstration functions.
 */
int main() {
   // Datatypes passed into all example formatted printing functions
   std::string world = "World";
   std::string int_max_name = "INT_MAX";
   int int_max_value = INT_MAX;
   std::string pi_name = "Pi";
   float pi_value = M_PI;

   // Example formatted printing functions
   c_standard(world, int_max_name, int_max_value, pi_name, pi_value);
   cpp_standard(world, int_max_name, int_max_value, pi_name, pi_value);
   cpp_format(world, int_max_name, int_max_value, pi_name, pi_value);
   cpp_print(world, int_max_name, int_max_value, pi_name, pi_value);
}


/**
 * Demonstrates standard C formatted printing with with the printf() function.
 *
 * @param string_value  The value of the generic string parameter.
 * @param int_name      The name of the generic integer parameter.
 * @param int_value     The value of the generic integer parameter.
 * @param float_name    The name of the generic floating point parameter.
 * @param float_value   The value of the generic floating point parameter.
 */
void c_standard(std::string string_value,
                std::string int_name, int int_value,
                std::string float_name, float float_value) {
   // Simple string
   printf("C standard formatted printing with printf():\n");
   // Simple string substitution
   printf("Hello, %s!\n", string_value.c_str());
   // Compound string and integer substitution and formatting
   printf("%7s = %10d\n", int_name.c_str(), int_value);
   // Compound string and floating point substitution and formatting
   printf("%7s = %10.5f\n\n", float_name.c_str(), float_value);
}


/**
 * Demonstrates standard C++ printing with std::cout and std::endl and standard
 * C++ formatting with std::fixed, std::setprecision(), and std::setw().
 *
 * @param string_value  The value of the generic string parameter.
 * @param int_name      The name of the generic integer parameter.
 * @param int_value     The value of the generic integer parameter.
 * @param float_name    The name of the generic floating point parameter.
 * @param float_value   The value of the generic floating point parameter.
 */
void cpp_standard(std::string string_value,
                  std::string int_name, int int_value,
                  std::string float_name, float float_value) {
   // Simple string
   std::cout << "C++ standard printing with std::cout and std::endl and formatting with std::fixed, std::setprecision(), and std::setw():\n";
   // Simple string substitution
   std::cout << "Hello, " << string_value << "!\n";
   // Compound string and integer substitution and formatting
   std::cout << std::setw(7) << int_name << " = " << std::setw(10) << int_value << "\n";
   // Compound string and floating point substitution and formatting
   std::cout << std::fixed << std::setprecision(5);  // fix the number of decimal digits to 5
   std::cout << std::setw(7) << float_name << " = " << std::setw(10) << float_value << "\n" << std::endl;
}


/**
 * Demonstrates standard C++ printing with std::cout and std::endl and <format>
 * library based formatting with std::format().  Available in C++20.
 *
 * @param string_value  The value of the generic string parameter.
 * @param int_name      The name of the generic integer parameter.
 * @param int_value     The value of the generic integer parameter.
 * @param float_name    The name of the generic floating point parameter.
 * @param float_value   The value of the generic floating point parameter.
 */
void cpp_format(std::string string_value,
                std::string int_name, int int_value,
                std::string float_name, float float_value) {
   // Check for format() function (available in C++20)
   #ifdef __cpp_lib_format
      // Simple string
      std::cout << "C++ standard printing with std::cout and std::endl and <format> based formatting with std::format():\n";
      // Simple string substitution
      std::cout << std::format("Hello, {}!\n", string_value);
      // Compound string and integer substitution and formatting
      std::cout << std::format("{0:>7s} = {1:10d}\n", int_name, int_value);
      // Compound string and floating point substitution and formatting
      std::cout << std::format("{0:>7s} = {1:10.5f}\n", float_name, float_value) << std::endl;
   #else
      std::cout << "C++ formatting with <format> based std::format() is not yet available; expected in C++20.\n" << std::endl;
   #endif
}


/**
 * Demonstrates <print> library based formatted printing with std::print() and
 * std::println().  Available in C++23.
 *
 * @param string_value  The value of the generic string parameter.
 * @param int_name      The name of the generic integer parameter.
 * @param int_value     The value of the generic integer parameter.
 * @param float_name    The name of the generic floating point parameter.
 * @param float_value   The value of the generic floating point parameter.
 */
void cpp_print(std::string string_value,
               std::string int_name, int int_value,
               std::string float_name, float float_value) {
   // Check for print() and println() functions (expected in C++23)
   #ifdef __cpp_lib_print
      // Simple string
      std::println("C++ <print> based formatted printing with std::print() and std::println():");
      // Simple string substitution
      std::print("Hello, {}!\n", string_value);
      // Compound string and integer substitution and formatting
      std::println("{0:>7s} = {1:10d}", int_name, int_value);
      // Compound string and floating point substitution and formatting
      std::println("{0:>7s} = {1:10.5f}\n", float_name, float_value);
   #else
      std::cout << "C++ formatted printing with <print> based std::print() and std::println() is not yet available; expected in C++23.\n" << std::endl;
   #endif
}

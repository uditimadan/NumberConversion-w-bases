**Number Conversion in C**

**Author**

Uditi Madan

**Overview**

This project consists of two main programs: numinfo and numconv.

**NumInfo**

numinfo basically is a command-line tool in c that checks whether a given string can be interpreted as an integer, binary, or hexadecimal value.

*Example
$ ./numinfo 1010
int: true
bin: true
hex: true*

**Working**

* Integer: A string consisting of only decimal digits (0-9).
* Binary: A string consisting of only '0' or '1'.
* Hexadecimal: A string consisting of decimal digits or letters (a-f, A-F)

**Functions**

bool is_dec_digit(char c) : *Checks if a character is a decimal digit (0-9).*
bool is_dec_str(char *s)  : *Checks if a string represents a valid decimal number.*
bool is_bin_digit(char c) : *Checks if a character is a binary digit (0 or 1).*
bool is_bin_str(char *s) : *Checks if a string represents a valid binary number.
bool is_hex_digit(char c) : *Checks if a character is a hexadecimal digit (0-9, a-f, A-F).*
bool is_hex_str(char *s) : *Checks if a string represents a valid hexadecimal number.*
Main function : *Checks if the input string is a valid integer, binary, or hexadecimal—Entry point to parse through the string.*


**NumConv**

numconv basically is a command-line tool that converts numbers between bases 2, 10, and 16. It also allows for multiple outputs based on the specified base(s).

*Example 
$ ./numconv 10 -o 2
0b1010
$ ./numconv 0xFF -o 10
255
$ ./numconv 213 -o 2 -o 16
0b11010101
0xd5*

**Working**

* The program first converts the input string into an unsigned 32-bit integer (uint32_t).
* It then converts the uint32_t value into the requested output bases and displays the results.

**Functions**

int string_to_int_base(char *str, int base) :*Converts a string in a specified base (2, 10, 16) to its integer equivalent.*
bool is_valid_binary(const char *str) :*Checks if a string contains only valid binary digits (0 or 1).*
uint32_t string_to_int(char *str) :*Converts a string to an unsigned 32-bit integer, considering the base (binary, decimal, hexadecimal).*
void int_to_string(uint32_t value, char *str, int base) :*Converts an unsigned 32-bit integer to a string in the specified base (2, 10, 16).*
void handle_output(char *argv[], uint32_t value, int start, int end) :*Handles the conversion and output of a number in different bases based on user input.*
int main(int argc, char *argv[]) :*Outputs the number in different bases— Entry point*


**License**

This project is licensed under the MIT License.

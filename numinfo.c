#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//checking if a character is a decimal digit
bool is_dec_digit(char c) {
    char integers[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (int i = 0; i < sizeof(integers); i++) {
        if (c == integers[i]) {
            return true;
        }
    }
    return false;
}

//checking if a string is a valid decimal number
bool is_dec_str(char *s) {
    for (int i = 0; i < strlen(s); i++) {
        if (!is_dec_digit(s[i])) {
            return false;
        }
    }
    return true;
}

//checking if a character is a binary digit
bool is_bin_digit(char c) {
    char binary[] = {'0', '1'};
    for (int i = 0; i < sizeof(binary); i++) {
        if (c == binary[i]) {
            return true;
        }
    }
    return false;
}

//checking if a string is a valid binary number
bool is_bin_str(char *s) {
    for (int i = 0; i < strlen(s); i++) {
        if (!is_bin_digit(s[i])) {
            return false;
        }
    }
    return true;
}

//checking if a character is a hexadecimal digit
bool is_hex_digit(char c) {
    char hexdecimal[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                         'a', 'b', 'c', 'd', 'e', 'f',
                         'A', 'B', 'C', 'D', 'E', 'F'};
    for (int i = 0; i < sizeof(hexdecimal); i++) {
        if (c == hexdecimal[i]) {
            return true;
        }
    }
    return false;
}

//checking if a string is a valid hexadecimal number
bool is_hex_str(char *s) {
    for (int i = 0; i < strlen(s); i++) {
        if (!is_hex_digit(s[i])) {
            return false;
        }
    }
    return true;
}

//main function
int main(int argc, char *argv[]) {
    //error handling
    if (argc != 2) {
        printf("usage: numinfo <value>\n");
        return 1;
    }
    //reading in the string
    char *number_string = argv[1];
    printf("int: %s\n", is_dec_str(number_string) ? "true" : "false"); //checks for decimal
    printf("bin: %s\n", is_bin_str(number_string) ? "true" : "false"); //checks for binary
    printf("hex: %s\n", is_hex_str(number_string) ? "true" : "false"); //checks for hexadecimal
    return 0;
}

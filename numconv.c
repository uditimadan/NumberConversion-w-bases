#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

//takes in the string value and checks for the base and does the conv acc
int string_to_int_base(char *str, int base) {
    int value = 0;
    while (*str) {
        int digit = 0;
        if (*str >= '0' && *str <= '9') { 
            digit = *str - '0';
        } else if (*str >= 'a' && *str <= 'f') {
            digit = *str - 'a' + 10;
        } else if (*str >= 'A' && *str <= 'F') {
            digit = *str - 'A' + 10;
        } else {
            return -1; //error handling:invalid input
        }
        value = value * base + digit;
        str++;
    }
    return value;
}

//valid binary or not
bool is_valid_binary(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '0' && str[i] != '1') {
            return false; //if not binary--1 or 0
        }
    }
    return true;
}

//basically converts binary or hexadecimal strings to integers
//unsigned 32 byte int; converting the string to int
uint32_t string_to_int(char *str) {
    uint32_t retval = 0;
    uint32_t placeval = 1;
    int base = 10;
    //determining the base of the str by looking at first two chars
    if (strncmp(str, "0b", 2) == 0) {
        base = 2;
        str += 2;
        if (!is_valid_binary(str)) {
            printf("bad input\n");
            return -1;  //indicates an error occurred
        }
    } else if (strncmp(str, "0x", 2) == 0) {
        base = 16;
        str += 2;
    }
    int len = strlen(str);
    //looping over str from the highest index down to 0
    for (int i = len - 1; i >= 0; i--) {
        int digit = 0;
        if (str[i] >= '0' && str[i] <= '9') {
            digit = str[i] - '0';
        } else if (str[i] >= 'a' && str[i] <= 'f') {
             digit = str[i] - 'a' + 10;
        } else if (str[i] >= 'A' && str[i] <= 'F') {
             digit = str[i] - 'A' + 10;
        } else {
             printf("bad input\n");
             return -1;  // error occurred
        }
        retval += digit * placeval; //adding the value to the retval
        placeval *= base; //updating to placeval to placeval * base
    }
    return retval;
}

//basically converts integers to strings-- binary, decimal, or hexadecimal
//accounting for the value and base 
void int_to_string(uint32_t value, char *str, int base) {
    char buffer[33] = {0};
    int i = 0;
    //init buffer to empty
    if (value == 0) {
        buffer[i++] = '0';
    }
    while (value != 0) {
        int rem = value % base;
        if (rem < 10) {
            buffer[i++] = rem + '0';
        } else {
            buffer[i++] = rem - 10 + 'a';
        }
        value /= base;
    }
    //reversing the copy buffer into str
        int j = 0;
        while (i > 0) {
            str[j++] = buffer[--i];
        }
        str[j] = '\0';
    }

//handles output based on the base and number
void handle_output(char *argv[], uint32_t value, int start, int end) {
    //initing and storing the results in separate output buffers for binary, decimal, and hexadecimal
    char binary_output[33] = {0};
    char decimal_output[33] = {0};
    char hex_output[33] = {0};
    //iterating through the base options
    for (int i = start; i < end; i += 2) {
        int base = string_to_int_base(argv[i], 10);
        //accounting for the different bases
        if (base == 2) {
            strcpy(binary_output, "0b");
            int_to_string(value, binary_output + 2, 2);
        } else if (base == 10) {
            int_to_string(value, decimal_output, 10);
        } else if (base == 16) {
            strcpy(hex_output, "0x");
            int_to_string(value, hex_output + 2, 16);
        } else {
            printf("Invalid base: %d\n", base);
            return;
        }
    //printing the result in the correct order
    }
    if (binary_output[0] != '\0') {
        printf("%s\n", binary_output);
    }
    if (decimal_output[0] != '\0') {
       printf("%s\n", decimal_output);
    }
    if (hex_output[0] != '\0') {
        printf("%s\n", hex_output);
    } 
 }

//main function
int main(int argc, char *argv[]) {
    if (argc < 4 || strcmp(argv[2], "-o") != 0) {
        printf("Usage: %s <number> -o <base>\n", argv[0]);
        return 1;
    }
    uint32_t value = string_to_int(argv[1]);
    //handling the edge case
    if (value == (uint32_t)-1) {
        //exit the code or terminates immediately if there is a bad input
        return 1;
    }
    //output procesing
   handle_output(argv, value, 3, argc);
   return 0;
}

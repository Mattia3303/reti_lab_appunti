#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


bool check_format(char addr[]) {
    size_t addrLen = strlen(addr);
    if (addrLen > 15 || addrLen < 7) {
        printf("Addr size wrong\n");
        return false;
    }

    int dots = 0;
    int num = 0;
    int digit_count = 0;
    bool last_was_dot = true; // Per rilevare punto iniziale o doppio punto

    for (size_t i = 0; i <= addrLen; i++) {
        char ch = addr[i];

        if (isdigit(ch)) {
            num = num * 10 + (ch - '0');
            digit_count++;

            if (digit_count > 3 || num > 255) {
                printf("Wrong number in block: %d\n", num);
                return false;
            }

            last_was_dot = false;
        }
        else if (ch == '.' || ch == '\0') {
            if (last_was_dot || digit_count == 0) {
                printf("Invalid dot position or empty block\n");
                return false;
            }

            digit_count = 0;
            num = 0;
            if (ch == '.') {
                dots++;
                if (dots > 3) {
                    printf("Too many dots\n");
                    return false;
                }
                last_was_dot = true;
            }
        }
        else {
            printf("Invalid character: %c\n", ch);
            return false;
        }
    }

    if (dots != 3) {
        printf("Wrong number of blocks\n");
        return false;
    }

    return true;
}



char* parse(uint32_t addr) {
    uint8_t b0 = addr >> 24;
    uint8_t b1 = addr >> 16;
    uint8_t b2 = addr >> 8;
    uint8_t b3 = addr;

    printf("Da b0 a b3: \n%hhu\n%hhu\n%hhu\n%hhu\n", b0, b1, b2, b3);

    char* res = malloc(15);

    sprintf(res, "%hhu.%hhu.%hhu.%hhu", b0, b1, b2, b3);
    //res = realloc(res, strlen(res) + 1);
    return res;
}

uint32_t convert(char addr[]) {
    uint8_t b0;
    uint8_t b1;
    uint8_t b2;
    uint8_t b3;

    sscanf(addr, "%hhu.%hhu.%hhu.%hhu", &b0, &b1, &b2, &b3);
    printf("Da b0 a b3: \n%hhu\n%hhu\n%hhu\n%hhu\n", b0, b1, b2, b3);

    uint32_t res = b0;
    res = res << 24;
    res += ((uint32_t)b1) << 16;
    res += ((uint32_t)b2) << 8;
    res += b3;

    return res;
}

int main(int argc, char** argv) {
    if (argc != 2)
    {
        printf("Error argc=%d\n", argc);
        exit(1);
    }
    
    char* ip_addr = argv[1];
    if (!check_format(ip_addr))
    {
        exit(1);
    }
    

    uint32_t addr = convert(ip_addr);
    printf("Addr decimal value: %u\n", addr);

    char* ipaddr_parsed = parse(addr);
    printf("Parsed addr: %s\n", ipaddr_parsed);

    return 0;
}
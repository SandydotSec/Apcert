#include <stdio.h>
#include <stdlib.h>

unsigned char* decode_data(const unsigned char* data, int length, unsigned char key) {
    int i;
    unsigned char* decoded = (unsigned char*)malloc(length + 1);
    if (!decoded) {
        return NULL;
    }

    for (i = 0; i < length; ++i) {
        decoded[i] = data[i] ^ key;
    }

    decoded[length] = '\0'; // Null-terminate the decoded string
    return decoded;
}

int main() {
    // Dữ liệu từ bộ nhớ .data đã cho
    unsigned char data[] = {
        0x5F, 0x26, 0x40, 0x40, 0x49, 0x6F, 0x79, 0x6E,
        0x6F, 0x40, 0x40, 0x39, 0x6F, 0x40, 0x40, 0x5D,
        0x6C, 0x6C, 0x58, 0x7D, 0x68, 0x7D, 0x40, 0x40,
        0x50, 0x73, 0x7F, 0x7D, 0x70, 0x40, 0x40, 0x48,
        0x79, 0x71, 0x6C, 0x40, 0x40, 0x5F, 0x50, 0x43,
        0x2A, 0x2E, 0x2F, 0x2B, 0x79, 0x28, 0x2A, 0x2A,
        0x7D, 0x6F, 0x68, 0x78, 0x5E
    };
    int length = sizeof(data) / sizeof(data[0]);
    unsigned char key = 0x1c; // Giá trị khóa

    // Giải mã dữ liệu
    unsigned char* decoded = decode_data(data, length, key);
    if (decoded) {
        printf("Decoded Data: %s\n", decoded);
        free(decoded);
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}

#include <iostream>
#include <cstring>

void decode(const unsigned char* encodedData, size_t length, unsigned char xorValue, char* decodedData) {
    for (size_t i = 0; i < length; ++i) {
        decodedData[i] = encodedData[i] ^ xorValue;
    }
    decodedData[length] = '\0';
}

int main() {
    unsigned char encodedData[] = {
        0x0F, 0x08, 0x15, 0x09, 0x0B, 0x0A, 0x15, 0x09,
        0x0E, 0x08, 0x15, 0x09, 0x03, 0x00, 0x00, 0x00
    };
    
    size_t length = sizeof(encodedData) / sizeof(encodedData[0]);

    char decodedData[256] = {0};

    unsigned char xorValue = 0x3B;


    decode(encodedData, length, xorValue, decodedData);

    std::cout << "Decoded string: " << decodedData << std::endl;

    return 0;
}

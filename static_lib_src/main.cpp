#include <iostream>

extern "C" char* encrypt(const char* rawText, int key);
extern "C" char* decrypt(const char* encryptedText, int key);

int main() {
    char* encryptedText = encrypt("Hello, world!", 200);
    if (!encryptedText) {
        std::cerr << "Encryption failed" << std::endl;
        return -1;
    }
    std::cout << encryptedText << std::endl;

    char* decryptedText = decrypt("Zwddg, Ogjdv!!", 200);
    if (!decryptedText) {
        std::cerr << "Decryption failed" << std::endl;
        delete[] encryptedText;
        return -1;
    }
    std::cout << decryptedText << std::endl;

    delete[] encryptedText;
    delete[] decryptedText;

    return 0;
}

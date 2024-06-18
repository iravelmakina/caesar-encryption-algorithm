#include <iostream>
#include <cstring>

extern "C" {
    __declspec(dllexport) char* encrypt(const char* rawText, int key) {
        char* encryptedText = new char[strlen(rawText) + 1];
        for (int i = 0; i < strlen(rawText); i++) {
            if (isalpha(rawText[i])) {
                if (isupper(rawText[i]))
                    encryptedText[i] = static_cast<char>((rawText[i] + key - 'A' + 26) % 26 + 'A');
                else encryptedText[i] = static_cast<char>((rawText[i] + key - 'a' + 26) % 26 + 'a');
            } else encryptedText[i] = rawText[i];
        }
        encryptedText[strlen(rawText)] = '\0';
        return encryptedText;
    }

    __declspec(dllexport) char* decrypt(const char* encryptedText, int key) {
        char* rawText = new char[strlen(encryptedText) + 1];
        for (int i = 0; i < strlen(encryptedText); i++) {
            if (isalpha(encryptedText[i])) {
                if (isupper(encryptedText[i]))
                    rawText[i] = static_cast<char>((encryptedText[i] - key - 'A' + 26) % 26 + 'A');
                else rawText[i] = static_cast<char>((encryptedText[i] - key - 'a' + 26) % 26 + 'a');
            } else rawText[i] = encryptedText[i];
        }
        rawText[strlen(encryptedText)] = '\0';
        return rawText;
    }
}

#include <iostream>
#include <windows.h>
#include <limits>

void toLowerCase(std::string &str) {
    for (char &c: str)
        c = static_cast<char>(tolower(c));
}

void getAndValidateUserInput(std::string &choice, std::string &message, int &key) {
    while (true) {
        std::cout << "Enter 'encrypt', 'decrypt' or 'exit': " << std::endl;
        std::cin >> choice;
        toLowerCase(choice);
        if (choice == "encrypt" || choice == "decrypt" || choice == "exit") break;
        else std::cout << "Invalid command. Please enter 'encrypt', 'decrypt' or 'exit'." << std::endl;
    }
    if (choice == "exit") return;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while (true) {
        std::cout << "Enter message: " << std::endl;
        std::getline(std::cin, message);
        if (!message.empty()) break;
        else std::cout << "Input is empty. Please enter a valid message." << std::endl;
    }

    while (true) {
        std::cout << "Enter shift: " << std::endl;
        if (!(std::cin >> key)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter an integer for the shift: " << std::endl;
        } else break;
    }
}

void processMessage(char*(*encrypt)(const char*, int), char*(*decrypt)(const char*, int), const std::string &choice,
                    std::string &message, int key) {
    char *result = nullptr;

    if (choice == "encrypt") {
        result = encrypt(message.c_str(), key);
        std::cout << "Encrypted message: " << result << std::endl;
    } else if (choice == "decrypt") {
        result = decrypt(message.c_str(), key);
        std::cout << "Decrypted message: " << result << std::endl;
    } else std::cout << "Invalid choice" << std::endl;
    delete[] result;
}


HINSTANCE loadLibrary(char*(*&encrypt)(const char*, int), char*(*&decrypt)(const char*, int)) {
    HINSTANCE handle = LoadLibrary(TEXT("../dynamic_lib_src/caesar.dll"));
    if (!handle || handle == INVALID_HANDLE_VALUE) {
        std::cout << "Library was not found" << std::endl;
        exit(-1);
    }

    encrypt = (char*(*)(const char*, int)) GetProcAddress(handle, TEXT("encrypt"));
    if (!encrypt) {
        std::cout << "Function 'encrypt' was not found" << std::endl;
        exit(-1);
    }

    decrypt = (char*(*)(const char*, int)) GetProcAddress(handle, TEXT("decrypt"));
    if (!decrypt) {
        std::cout << "Function 'decrypt' was not found" << std::endl;
        exit(-1);
    }
    return handle;
}

void runProgram(char*(*encrypt)(const char*, int), char*(*decrypt)(const char*, int)) {
    std::cout << "Welcome to the Caesar cipher program!" << std::endl;

    std::string choice, message;
    int key;

    while (true) {
        getAndValidateUserInput(choice, message, key);
        if (choice == "exit") {
            std::cout << "Exiting the program..." << std::endl;
            break;
        } else if (choice == "encrypt" || choice == "decrypt")
            processMessage(encrypt, decrypt, choice, message, key);
        else std::cout << "Invalid command. Please enter 'encrypt', 'decrypt' or 'exit'." << std::endl;
    }
}

int main() {
    char*(*encrypt)(const char*, int);
    char*(*decrypt)(const char*, int);

    HINSTANCE handle = loadLibrary(encrypt, decrypt);
    runProgram(encrypt, decrypt);
    FreeLibrary(handle);

    return 0;
}


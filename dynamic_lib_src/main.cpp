#include <iostream>
#include <windows.h>

int main() {
    HINSTANCE handle = LoadLibrary(TEXT("caesar.dll"));
    if (!handle || handle == INVALID_HANDLE_VALUE) {
        std::cout << "Library was not found" << std::endl;
        return -1;
    }

    typedef char* (*encryption_ptr)(const char*, int);
    encryption_ptr encryption = (encryption_ptr)GetProcAddress(handle, TEXT("encrypt"));
    if (!encryption) {
        std::cout << "Function 'encrypt' was not found" << std::endl;
        return -1;
    }

    typedef char* (*decryption_ptr)(const char*, int);
    decryption_ptr decryption = (decryption_ptr) GetProcAddress(handle, TEXT("decrypt"));
    if (!decryption) {
        std::cout << "Function 'decrypt' was not found" << std::endl;
        return -1;
    }

    std::cout << encryption("Hello, World!", 200) << std::endl;
    std::cout << decryption("Zwddg, Ogjdv!", 200) << std::endl;

    delete[] encryption("Hello, World!", 3);
    delete[] decryption("Khoor, Zruog!", 3);

    FreeLibrary(handle);

    return 0;
}
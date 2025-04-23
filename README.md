# Caesar Encryption Algorithm (Structured and Procedural Programming)

## Purpose of Work
The purpose of this work is to gain experience in programming using a structured and procedural paradigm by implementing a Caesar encryption/decryption algorithm. This project involves learning the compilation and linking processes by developing a dynamic library.

## Task
This lab is divided into four main subtasks:
1. **Encrypt Function**
    - Create a function `encrypt` which takes two arguments: a char array with raw text to be encrypted and an integer encryption key.
    - Prototype: `char* encrypt(char* rawText, int key);`
    - Example: Encrypting "Roses are red, violets are blue" with key 1 results in "Sptft bsf sfe, wjpmfut bsf cmvf".

2. **Decrypt Function**
    - Create a function `decrypt` which takes two arguments: a char array with encrypted text and an integer encryption key.
    - Prototype: `char* decrypt(char* encryptedText, int key);`
    - Example: Decrypting "Sptft bsf sfe, wjpmfut bsf cmvf" with key 1 results in "Roses are red, violets are blue".

3. **Caesar Cipher DLL**
    - Wrap the `encrypt` and `decrypt` functions into a dynamic-link library (DLL) for modular usage across various projects.
    - Create `caesar.dll` and ensure it exports the `encrypt` and `decrypt` functions.

4. **Testing the Dynamic Library**
    - Create a separate program to test the DLL. The user should be able to encrypt and decrypt messages using the CLI.
    - Implement simple CLI options to input messages and keys for encryption and decryption.

## How to Use
1. Clone the repository.
2. Compile the source code using a C++ compiler.
3. Run the executable.
4. Follow the on-screen instructions to use the Caesar cipher.

## Contributors
-@iravelmakina

# Caesar Encryption with Dynamic Library (C++ / Windows)

This repository contains a C++ implementation of the **Caesar cipher encryption and decryption algorithm**, structured using **procedural programming** and built as a **Windows dynamic-link library (DLL)** for modular reuse.

---

## Features

### 1. Encryption Function

Encrypts a string using the Caesar cipher with a given key.

```c
char* encrypt(char* rawText, int key);
```

Example:
```
Input:  "Roses are red, violets are blue"
Key:    1
Output: "Sptft bsf sfe, wjpmfut bsf cmvf"
```

---

### 2. Decryption Function

Decrypts Caesar-encrypted text using the same key.

```c
char* decrypt(char* encryptedText, int key);
```

Example:
```
Input:  "Sptft bsf sfe, wjpmfut bsf cmvf"
Key:    1
Output: "Roses are red, violets are blue"
```

---

### 3. Dynamic-Link Library (DLL)

The core encryption logic is compiled into a **Windows DLL**:
- Enables modular reuse across different C++ applications.
- Easy to link from other programs.

---

### 4. Command-Line Interface (CLI) Test Program

A simple CLI program demonstrates how to:
- Load the `caesar.dll`
- Pass messages and keys to `encrypt` and `decrypt`
- View the encrypted/decrypted results interactively

---

## Getting Started

### Prerequisites

- Windows OS
- C++ compiler supporting DLL creation (e.g., MSVC, MinGW)

### Build Instructions

1. Clone the repository:
   ```bash
   git clone https://github.com/iravelmakina/caesar-encryption-algorithm.git
   ```

2. Navigate to the source directories:
   - `static_lib_src/` – optional static build
   - `dynamic_lib_src/` – main DLL source
   - `program_src/` – test CLI program

3. Compile the DLL:
   ```bash
   g++ -shared -o caesar.dll dynamic_lib_src/caesar.cpp
   ```

4. Compile the test program:
   ```bash
   g++ -o encryptor program_src/main.cpp -L. -lcaesar
   ```

5. Run:
   ```bash
   ./encryptor
   ```

---

## Repository Structure

```
caesar-encryption-dll/
├── dynamic_lib_src/        # Caesar algorithm source for DLL
├── static_lib_src/         # (Optional) Static build version
├── program_src/            # CLI program using the DLL
└── README.md
```

---

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

## Contributor

- [@iravelmakina](https://github.com/iravelmakina)

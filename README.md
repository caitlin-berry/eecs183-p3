# **Project 3 - Ciphers Encryption Program**
A C++ program that implements multiple classical encryption and decryption algorithms, including Caesar, Vigenère, and Polybius ciphers. The program uses a menu-driven interface and includes a test suite to verify correctness of each component.
## **Overview**
This project focuses on implementing and applying different cryptographic techniques. The program:
- Encrypts and decrypts messages using three cipher algorithms
- Handles string manipulation and character transformations
- Validates user input to ensure correct program behavior
- Includes a test suite to verify correctness of individual functions

The project is organized across multiple files, separating functionality for each cipher and utility operations.

## **How to Run**
Compile the program:
```bash
g++ utility.cpp caesar.cpp vigenere.cpp polybius.cpp ciphers.cpp start.cpp test.cpp -o ciphers
```

Run the program:
```bash
./ciphers
```

Follow the prompts to either run test cases or use the cipher program.

## **Concepts Used**
- Modular programming with multiple source and header files
- String manipulation and character processing
- Loops and conditional logic
- Input validation and error handling
- Function decomposition and abstraction
- Writing and using test suites

## **Program Structure**
- `utility.cpp`: Helper functions for string and character operations
- `caesar.cpp`: Implementation of Caesar cipher
- `vigenere.cpp`: Implementation of Vigenère cipher
- `polybius.cpp`: Implementation of Polybius Square cipher
- `ciphers.cpp`: User interface and program logic
- `start.cpp`: Entry point and menu system
- `test.cpp`: Test suite for validating functionality

## Contributions
This project was completed with one partner. Work was divided as follows:
- Collaboratively implemented: `utility.cpp`, `caesar.cpp`, and `ciphers.cpp`
- Individually implemented: `vigenere.cpp` and `polybius.cpp` (my contributions)

## **Example Features**
- Supports encryption and decryption for multiple cipher types
- Preserves case and ignores non-alphabetic characters where appropriate
- Uses different key systems (integer shift, keyword, grid-based encoding)
- Menu-driven interface for user interaction
- Comprehensive test suite to detect implementation errors
- 
## **Example Output**
```text
Choose a cipher (Caesar, Vigenere, or Polybius): caesar
Encrypt or decrypt: encrypt
Enter a message: I solemnly swear that I am up to no good.
What is your key: 7
The encrypted message is: P zvsltusf zdlhy aoha P ht bw av uv nvvk.
```

```text
Choose a cipher (Caesar, Vigenere, or Polybius): ViGenere
Encrypt or decrypt: DECrypt
Enter a message: U lgp'a os qaoxitk iaz ltvcfqq. Teoafoq ckwhtpd riady qh.
What is your key: Mischief managed.
The decrypted message is: I don't go looking for trouble. Trouble usually finds me.
```

```text
Choose a cipher (Caesar, Vigenere, or Polybius): P
Encrypt or decrypt: E
Enter a message: EECS 183 is the best
What is your key: polybius
The encrypted message is: 15151311 435445 0511 332215 04151133
```

```text
Choose a cipher (Caesar, Vigenere, or Polybius): P
Encrypt or decrypt: enCRYPT
Enter a message: Life isn't about waiting for the storm to pass its about learning to dance in the rain
Invalid message!
```

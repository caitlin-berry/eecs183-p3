/*
 * ciphers.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Caitlin Berry, Liad Gross
 * cnberry, liadgr
 *
 * EECS 183: Project 3
 * Fall 2023
 *
 * This program runs the ciphers function which allows users to chose a cipher
 * method and whether they want to encrypt or decrypt a message they
 * entered along with a key used to encrypt/decrypt their message. The computer
 * then prints the corresponding encryption/decryption of their message.
 */

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include <iostream>
#include <string>

using namespace std;

void ciphers(){
    // ask user for cipher (Caesar, Vigenere, or Polybius)
    string cipherMove = "";
    cout << "Choose a cipher (Caesar, Vigenere, or Polybius): ";
    getline(cin, cipherMove);
    cipherMove = toUpperCase(cipherMove);
    cout << endl;
    
    // check the entered value and assign the corresponding cipher move
    if (cipherMove == "CAESAR" || cipherMove == "C"){
        cipherMove = "Caesar";
    } else if (cipherMove == "VIGENERE" || cipherMove == "V"){
        cipherMove = "Vigenere";
    } else if (cipherMove == "POLYBIUS" || cipherMove == "P"){
        cipherMove = "Polybius";
    } else {
        cout << "Invalid cipher!" << endl;
        return;
    }
    
    // ask user to encrypt or decrypt
    string encryptionMove = "";
    cout << "Encrypt or decrypt: ";
    getline(cin, encryptionMove);
    encryptionMove = toUpperCase(encryptionMove);
    cout << endl;
    
    // check the entered value and assign the corresponding encryption move
    if (encryptionMove == "ENCRYPT" || encryptionMove == "E"){
        encryptionMove = "Encrypt";
    } else if (encryptionMove == "DECRYPT" || encryptionMove == "D"){
        encryptionMove = "Decrypt";
    } else {
        cout << "Invalid mode!" << endl;
        return;
    }
    
    // get message from user
    string userMessage = "";
    cout << "Enter a message: ";
    getline(cin, userMessage);
    cout << endl;
    
    // check for errors in the user's entered message if using polybius cipher
    string checkPolybiusMessage = "";
    if (cipherMove == "Polybius"){
        userMessage = toUpperCase(userMessage);
        for (double i = 0; i < userMessage.length(); i++){
            if (isalpha(userMessage.at(i)) || isdigit(userMessage.at(i))){
                checkPolybiusMessage = "Good";
            } else if (userMessage.at(i) == ' '){
                checkPolybiusMessage = "Good";
            } else {
                checkPolybiusMessage = "Bad";
                i = userMessage.length();
            }
        }
        if (checkPolybiusMessage == "Bad"){
            cout << "Invalid message!" << endl;
            return;
        }
        
    }
    
    // get key or keyword from user
    string userKey = "";
    int userKeyInt = 0;
    cout << "What is your key: ";
    if (cipherMove == "Caesar"){
        cin >> userKeyInt;
    } else {
        getline(cin, userKey);
    }
    cout << endl;
    
    // check for errors in the user's entered key depending on the cipher type
    string checkVigenereKey = "";
    if (cipherMove == "Vigenere"){
        for (double i = 0; i < userKey.length(); i++){
            if (isalpha(userKey.at(i))){
                checkVigenereKey = "Good";
                i = userKey.length();
            } else {
                checkVigenereKey = "Bad";
            }
        }
        if (checkVigenereKey == "Bad"){
            cout << "Invalid key!" << endl;
            return;
        }
    } else if (cipherMove == "Polybius"){
        userKey = toUpperCase(userKey);
        userKey = removeDuplicate(userKey);
    }
    
    // encrypt or decrypt message using selected cipher and key(word)
    // print encrypted/decrypted message
    if (encryptionMove == "Encrypt"){
        cout << "The encrypted message is: ";
    } else if (encryptionMove == "Decrypt"){
        cout << "The decrypted message is: ";
    }
    
    // call corresponding cipher functions based on the user's entered values
    if (cipherMove == "Caesar"){
        if (encryptionMove == "Encrypt"){
            cout << caesarCipher(userMessage, userKeyInt, true) << endl;
        } else if (encryptionMove == "Decrypt"){
            cout << caesarCipher(userMessage, userKeyInt, false) << endl;
        }
    } else if (cipherMove == "Vigenere"){
        if (encryptionMove == "Encrypt"){
            cout << vigenereCipher(userMessage, userKey, true) << endl;
        } else if (encryptionMove == "Decrypt"){
            cout << vigenereCipher(userMessage, userKey, false) << endl;
        }
    } else if (cipherMove == "Polybius"){
        char grid[SIZE][SIZE];
        if (encryptionMove == "Encrypt"){
            cout << polybiusSquare(grid, userKey, userMessage, true) << endl;
        } else if (encryptionMove == "Decrypt"){
            cout << polybiusSquare(grid, userKey, userMessage, false) << endl;
        }
    }
    return;
}

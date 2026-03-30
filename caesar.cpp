/*
 * caesar.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Caitlin Berry, Liad Gross
 * cnberry, liadgr
 *
 * EECS 183: Project 3
 * Fall 2023
 *
 * This program creates another helped function that is used in other cipher
 * functions and also includes the ceasarCipher function which shifts a
 * user's message by a specific number given by the user's key.
 */

#include "caesar.h"
#include <iostream>
#include "utility.h"


// Shifts a given char c by an int n and returns the new char
char shiftAlphaCharacter(char c, int n){
    int shift = 0;
    int numOfAlphabet = 26;
    // check if n is positive or negative and return the mod of the variable to
    // shift the message by the least number of spaces
    if (n < 0) {
        int tempN = n * (-1);
        shift = tempN % numOfAlphabet;
    } else {
        shift = n % numOfAlphabet;
    }
    int number = charToInt(c);
    // reset the ASCII value of the char to the...
    int decUppercaseZ = 90;
    int decBeforeUppercaseA = 64;
    int decLowercasez = 122;
    int decBeforeLowercaseA = 96;
    int decUppercaseA = 65;
    int decAfterUppercaseZ = 91;
    int decLowercaseA = 97;
    int decAfterLowercaseZ = 123;
    for (int i = 0; i < shift; i++){
        if (n >= 0) {
            // beginning of the alphabet if the end is reached
            if(isupper(c)){
                if (number == decUppercaseZ){
                    number = decBeforeUppercaseA;
                }
                number += 1;
            } else {
                if (number == decLowercasez){
                    number = decBeforeLowercaseA;
                }
                number += 1;
            }
        } else {
            // end of the alphabet if the beginning is reached
            if(isupper(c)){
                if (number == decUppercaseA){
                    number = decAfterUppercaseZ;
                }
                number -= 1;
            } else {
                if (number == decLowercaseA){
                    number = decAfterLowercaseZ;
                }
                number -= 1;
            }
        }
    }
    char final = number;
    return final;
}

// encrypt or decrypt the users message using the user's key by shifting
// each char from the string by the int key
string caesarCipher(string original, int key, bool encrypt){
    // check if message is encrypted --> positive key to shift chars right
    // check if message is decrypted --> negative key to shift chars left
    if (!encrypt) {
        key = key * (-1);
    }
    // loop through all chars in the users message and shift them by the key
    for (int i = 0; i < original.length(); i++){
        if (isalpha(original.at(i))){
            original.at(i) = shiftAlphaCharacter(original.at(i), key);
        }
    }
    return original;
}

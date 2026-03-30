/*
 * vigenere.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Caitlin Berry, Liad Gross
 * cnberry, liadgr
 *
 * EECS 183: Project 3
 * Fall 2023
 *
 * This program encrypts/decrypts a user's message by converting the chars from
 * a users string keyword to ints and using those ints to shift each char from
 * their string message, continuously repeating the users string keyword for
 * the whole message.
 */

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "utility.h"
#include <iostream>

string vigenereCipher(string original, string keyword, bool encrypt){
    // set keyword to match the necessary form
    keyword = toUpperCase(keyword);
    keyword = removeNonAlphas(keyword);
    // create a k variable to access indecies from the keyword
    int k = -1;
    double lengthK = keyword.length() - 1;
    for (int i = 0; i < original.length(); i++){
        // only perform the following actions on alpha chars
        if (isalpha(original.at(i))){
            // increase the k value as long as it won't try to access an
            // undefined index in the keyword
            if (k < lengthK) {
                k++;
            } else {
                k = 0;
            }
            char tempChar = original.at(i);
            int tempInt = charToInt(keyword.at(k));
            int decUppercaseA = 65;
            // set the int of the "charToInt" so a=0 through z=25
            int newInt = tempInt - decUppercaseA;
            // encrypt or decrypt the specific char in the string message
            if (encrypt){
                original.at(i) = shiftAlphaCharacter(tempChar, newInt);
            } else {
                newInt = newInt * (-1);
                original.at(i) = shiftAlphaCharacter(tempChar, newInt);
            }
        }
    }
    return original;
}

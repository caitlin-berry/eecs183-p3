/*
 * utility.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Caitlin Berry, Liad Gross
 * cnberry, liadgr
 *
 * EECS 183: Project 3
 * Fall 2023
 *
 * This program creates definitions for helper functions that can be used in
 * all the cipher functions.
 */

#include "utility.h"
#include <iostream>

// take in a string of letters and return the string with all uppercase letters
string toUpperCase(string original) {
    string modified = original;
    for (int i = 0; i < modified.length(); i++) {
        int decLowercaseA= 97;
        int decLowercaseZ = 122;
        if (modified.at(i) >= decLowercaseA && modified.at(i) <= decLowercaseZ) {
            modified.at(i) = toupper(modified.at(i));
        }
    }
    return modified;
}

// take in a string that has letters, numbers, spaces, etc. and return the
// string that just has the letters
string removeNonAlphas(string original) {
    string modified = "";
    for (int i = 0; i < original.length(); i++){
        if (isalpha(original.at(i))){
            modified += original.at(i);
        }
    }
    return modified;
}

// take in a string that containes duplicate characters and retunr the string
// that only has one of each character in the string
string removeDuplicate(string original) {
    string modified = "";
    for (int i = 0 ; i < original.length(); i++){
        if (modified.find(original.at(i)) == string::npos){
            modified += original.at(i);
        }
    }
    return modified;
}

// take in a number as a data type char and return the corresponding number as
// a data type int
int charToInt(char original) {
    int charAsInt = 0;
    int dec0 = 48;
    int dec9 = 57;
    if(original >= dec0 && original <= dec9){
        charAsInt = original - dec0;
    } else {
        charAsInt = original;
    }
    return charAsInt;
}

////////////////////////////////////////////////////////////////////////////////
// Do not touch code below. ///////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void printGrid(const char grid[SIZE][SIZE]) {
    for (int col = 0; col < SIZE; col++) {
        cout << " ---";
    }
    cout << endl;
    for (int row = 0; row < SIZE; row++) {
        cout << "| ";
        for (int col = 0; col < SIZE; col++) {
            cout << string(1, grid[row][col]) + " | ";
        }
        cout << endl;
        for (int col = 0; col < SIZE; col++) {
            cout << " ---";
        }
        cout << endl;
    }
}

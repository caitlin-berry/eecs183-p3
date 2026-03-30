/*
 * polybius.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Caitlin Berry, Liad Gross
 * cnberry, liadgr
 *
 * EECS 183: Project 3
 * Fall 2023
 *
 * This program defines helper functions used in the polybiusSquare function
 * and also defines the polybiusSquare function which files in a 6x6 grid, adds
 * a keyword to the beginning of the grid, and returns the coordinates of a
 * users message in the grid or a message when given coordinates from the grid.
 */


#include "polybius.h"
#include <string>
using namespace std;

// appends the const ALNUM to the key and removes duplicate chars in the string
string mixKey(string key){
    string newKey = key + ALNUM;
    newKey = removeDuplicate(newKey);
    return newKey;
}

// assign all values from content string in their own coordinate of the grid
void fillGrid(char grid[SIZE][SIZE], string content){
    int stringIndex = 0;
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            grid[i][j] = content.at(stringIndex);
            stringIndex++;
        }
    }
}

// given a specific char, return the coordinate of the char in the grid
string findInGrid(char c, char grid[SIZE][SIZE]){
    string coordinates = "";
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            int dec0 = 48;
            if (grid[i][j] == c) {
                char k = i + dec0;
                char m = j + dec0;
                coordinates += k;
                coordinates += m;
            }
        }
    }
    return coordinates;
}

// encrypt/decrypt a user's message given a key which is mixed with ALNUM and
// returns the new version of their message
string polybiusSquare(char grid[SIZE][SIZE], string key,
                      string original, bool encrypt){
    string newKey = mixKey(key);
    fillGrid(grid, newKey);
    string newMessage = "";
    // encrypt or decrypt the award
    if (encrypt){
        // go through the original string (user message)
        for (int i = 0; i < original.length(); i++){
            // check if char needs to be modified
            if (isalpha(original.at(i)) || isdigit(original.at(i))){
                string charCoordinates = "";
                charCoordinates = findInGrid(original.at(i), grid);
                newMessage += charCoordinates;
            } else {
                newMessage += original.at(i);
            }
        }
    } else {
        // create two variables to access the coordinate as seperate values
        char coordinate1;
        char coordinate2;
        int coordinate1New = 0;
        int coordinate2New = 0;
        // go through the original string (user message)
        for (int i = 0; i < original.length(); i += 2){
            // check if the char needs to be modified
            if (isdigit(original.at(i))){
                // separate the coordinates
                coordinate1 = original.at(i);
                coordinate2 = original.at(i + 1);
                coordinate1New = charToInt(coordinate1);
                coordinate2New = charToInt(coordinate2);
                newMessage += grid[coordinate1New][coordinate2New];
            } else {
                newMessage += original.at(i);
                // decrement (i + 2) by one so i is incremented by 1 in the end
                i = i - 1;
            }
        }
    }
    return newMessage;
}

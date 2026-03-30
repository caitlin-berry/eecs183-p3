/*
 * test.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Caitlin Berry, Liad Gross
 * cnberry, liadgr
 *
 * EECS 183: Project 3
 * Fall 2023
 *
 * Create test functions for all the helped and cipher functions in the project
 */

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include <iostream>
#include <string>
using namespace std;

void testToUpperCase();
void testRemoveNonAlphas();
void testRemoveDuplicate();
void testCharToInt();
void testShiftAlphaCharacter();
void testCaesarCipher();
void testVigenereCipher();
void testFillGrid();
void testMixKey();
void testFindInGrid();
void testPolybiusSquare();

void startTests() {
    testToUpperCase();
    testRemoveNonAlphas();
    testRemoveDuplicate();
    testCharToInt();
    testShiftAlphaCharacter();
    testCaesarCipher();
    testVigenereCipher();
    testFillGrid();
    testMixKey();
    testFindInGrid();
    testPolybiusSquare();
}


void testToUpperCase() {
    cout << "Now testing function toUpperCase()" << endl;
    cout << "Expected: 'HELLO', Actual: '" << toUpperCase("hello") << "'"
         << endl;
    cout << "Expected: 'HELLO WORLD!', Actual: '"
         << toUpperCase("Hello World!") << "'" << endl;
    cout << "Expected: 'I HAVE EECS AT 10:00 A.M.', Actual: '"
         << toUpperCase("I have EECS at 10:00 A.M.") << "'" << endl;
}

void testRemoveNonAlphas() {
    cout << "Now testing function removeNonAlphas()" << endl;
    cout << "Expected: 'Hello', Actual: '" << removeNonAlphas("Hello123")
         << "'" << endl;
    cout << "Expected: 'CitlinBerry', Actual: '"
         << removeNonAlphas("C@itlin Berry") << "'" << endl;
    cout << "Expected: 'SStateSt', Actual: '"
         << removeNonAlphas("222 S State St") << "'" << endl;
}

void testRemoveDuplicate() {
    cout << "Now testing function removeDuplicate()" << endl;
    cout << "Expected: 'HELOWRD', Actual: '"
         << removeDuplicate("HELLOWORLD") << "'" << endl;
    cout << "Expected: 'RACE12', Actual: '" << removeDuplicate("RACECAR1212")
         << "'" << endl;
    cout << "Expected: '1MY2NAE3', Actual: '"
         << removeDuplicate("1MY2NAME31") << "'" << endl;
}

void testCharToInt() {
    cout << "Now testing function charToInt()" << endl;
    cout << "Expected: '1', Actual: '" << charToInt('1') << "'" << endl;
    cout << "Expected: '8', Actual: '" << charToInt('8') << "'" << endl;
    cout << "Expected: '0', Actual: '" << charToInt('0') << "'" << endl;
}

void testShiftAlphaCharacter() {
    cout << "Now testing function shiftAlphaCharacter()" << endl;
    cout << "Expected: 'a', Actual: '" << shiftAlphaCharacter('a', 0) << "'"
         << endl;
    cout << "Expected: 'd', Actual: '" << shiftAlphaCharacter('b', 2) << "'"
         << endl;
    cout << "Expected: 'y', Actual: '" << shiftAlphaCharacter('a', -2) << "'"
         << endl;
    cout << "Expected: 'x', Actual: '" << shiftAlphaCharacter('z', -2) << "'"
         << endl;
    return;
}

void testCaesarCipher() {
    cout << "Now testing function caesarCipher()" << endl;
    cout << "Expected: 'Cuuj cu qj jxu Tyqw qj 11 f.c.', Actual: '"
         << caesarCipher("Meet me at the Diag at 11 p.m.", 42, true) << endl;
    cout << "Expected: 'Meet me at the Diag at 11 p.m.', Actual: '"
         << caesarCipher("Cuuj cu qj jxu Tyqw qj 11 f.c.", 42, false) << endl;
    cout << caesarCipher("Anna: I don't even know what love is", 5, true)
         << endl;
    cout << "Now testing shiftAlphaCharacter()" << endl;
    cout << shiftAlphaCharacter('v', 5) << endl;
 }

void testVigenereCipher() {
    cout << "Now testing function vigenereCipher()" << endl;
    cout << "Expected: 'Euyb dv ee lxy Lzrk ll 11 f.g.', Actual: '"
         << vigenereCipher("Meet me at the Diag at 11 p.m.", "Squirrel!", true)
         << endl;
    cout << "Expected: 'Meet me at the Diag at 11 p.m', Actual: '"
         << vigenereCipher("Euyb dv ee lxy Lzrk ll 11 f.g", "Squirrel!", false)
         << endl;
}

void testMixKey() {
    cout << "Now testing function mixKey()" << endl;
    cout << "Expected: 'POLYBIUSACDEFGHJKMNQRTVWXZ0123456789', Actual: '"
         << mixKey("POLYBIUS") << "'" << endl;
    cout << "ExpectedL 'STRING1ABCDEFHJKLMOPQUVWXYZ023456789', Actual: '"
         << mixKey("STRING1") << "'" << endl;
    cout << "ExpectedL 'HEY123456789ABCDFGIJKLMNOPQRSTUVWXZ0', Actual: '"
         << mixKey("HEY123456789") << "'" << endl;
}

void testFillGrid() {
    char grid[SIZE][SIZE];
    cout << "Now testing function fillGrid()" << endl;
    cout << "Test case one:" << endl;
    fillGrid(grid, ALNUM);
    printGrid(grid);
    cout << "Test case two:" << endl;
    fillGrid(grid, mixKey("POLYBIUS"));
    printGrid(grid);
}

void testFindInGrid() {
    char grid[SIZE][SIZE];
    cout << "Now testing function findInGrid()" << endl;
        fillGrid(grid, ALNUM);
        printGrid(grid);
    cout << "Expected: 00, Actual: " << findInGrid('A', grid) << endl;
        fillGrid(grid, ALNUM);
        printGrid(grid);
    cout << "Expected: 43, Actual: " << findInGrid('1', grid) << endl;
        fillGrid(grid, mixKey("POLYBIUS"));
        printGrid(grid);
    cout << "Expected: 32, Actual: " << findInGrid('R', grid) << endl;
}

void testPolybiusSquare() {
    char grid[SIZE][SIZE];
    cout << "Now testing function polybiusSquare()" << endl;
    cout << "Expected: '11110533 000102 1533 341411 04113334', Actual: '"
         << polybiusSquare(grid, "183", "EECS 183 IS THE BEST", true) << "'"
         << endl;
    cout << "Expected: 'EECS 183 IS THE BEST', Actual: '"
         << polybiusSquare(grid, "183", "11110533 000102 1533 341411 04113334",
                           false) << "'" << endl;
    cout << "Exprected: 'AND WHO AM I THATS ONE SECRET ILL NEVER TELL', "
         << "Actual: '"
         << polybiusSquare(grid, "DANIEL", "010200 341422 0121 03 3114013130 220204 300411250431 030505 0204330425 31040505", false) << "'" << endl;
}

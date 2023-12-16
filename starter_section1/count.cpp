/*
 * CS106B Section Handout Test Harness: Section 1
 * ----------------------------------------------
 * These problems have been galvanized from years of
 * section handouts that have been worked on by numerous
 * instructors and TA's. Codified by Trip Master and Nick
 * Bowman for CS106B Spring 2020.
 *
 * A huge thank you to Keith Schwarz and Julie Zelenski
 * for creating an amazing testing harness!
 */
#include <iostream>
#include "SimpleTest.h"
#include "vector.h"
#include "simpio.h"
#include "strlib.h"
#include "filelib.h"
#include <fstream>
using namespace std;

/*
 * Count Numbers (Code Write)
 * ----------------------------------
 * Write a program to read through a given file and count the
 * the number of times a user inputed number appears in that file. You  
 * can assume that numbers will be composed entirely of numerical digits, 
 * optionally preceded by a single negative sign.
 */
void countNumbers(string filepath) {
    string entered_number = getLine("Please enter a number: ");
    int count = 0 ;
    ifstream stream;
    Vector<string> lines;
    if (openFile(stream, filepath)) {
        lines = readLines(stream);
    }
    Vector<string> elements_in_line;
    for (string l : lines) {
        elements_in_line = stringSplit(l, " ");
        for (string e : elements_in_line) {
            if (stringIsInteger(e)) {
                if (equalsIgnoreCase(e, entered_number)) {
                    ++count;
                }
            }
        }
    }
    cout << "The count is: " << count << endl;
}

/* * * * * Provided Tests Below This Point * * * * */

PROVIDED_TEST("Count numbers") {
    /* This isn't a full on test, since the results of countNumbers
     * depends on user input. To confirm your solution works, you'd need
    to manually check the print statements in the console. */
    EXPECT_NO_ERROR(countNumbers("res/numbers.txt"));
}

/********************************************
*	DEVELOPER:	Ian Utnehmer
* COLLABORATORS: Eduardo Mariscal
*	COURSE:	CS226 Discrete Structures
*	PROJECT: Project #5
*	LAST MODIFIED:	5/6/2024
********************************************/
/********************************************
*	Sequence Filter
*********************************************
*	PROGRAM DESCRIPTION:
*	This program takes a positive integer n
 *	as input and generates all possible bit
 *	sequences of length n that do not contain
 *	a pair of consecutive 0s.
*********************************************
*	FUNCTIONS:
* No functions used.
*********************************************/

/*********************************************
*	SETUP STATEMENTS and PURPOSE:
*********************************************/
#include <iostream> //to output to console
using namespace std; //access namespace
/*********************************************
*	MAIN PROGRAM:
*********************************************/
int main() {
    int n;
    cout << "Enter a positive integer n: ";
    cin >> n;

    // Initialize the first bit sequence
    int bitSeq = 1;

    bool hasConsecutiveZeros;

    // Loop through all bit sequences of length n
    // NOTE: 1 << n is equivalent to 2^n, as the "<<" operator is the bit-shift operator (left shift).
    // The method of bit-shifting is used to generate all possible bit sequences of length n,
    // whilst simultaneously checking for consecutive 0s.
    for (int i = 0; i < (1 << n); i++) { // The loop will continue for as long as i is less than 2^n
        // Check if the bit sequence has a pair of consecutive 0s
        hasConsecutiveZeros = false; // Reset the flag
        for (int j = 0; j < n - 1; j++) { // n - 1 because we are checking the next bit
            if ((bitSeq & (1 << j)) == 0 // Check if the current bit... (bitSeq & (1 << j)) extracts the j-th bit of bitSeq)
            && (bitSeq & (1 << (j + 1))) == 0) { // ...and the next bit are both 0 (bitSeq & (1 << (j + 1)) extracts the (j + 1)-th bit of bitSeq)
                hasConsecutiveZeros = true; // Set the flag
                break; // Exit the loop. If we find a pair of consecutive 0s, we don't need to check the rest.
            }
        }

        // Print the bit sequence if it does not have a pair of consecutive 0s
        if (!hasConsecutiveZeros) { // If the flag is not set
            for (int j = n - 1; j >= 0; j--) { // Print the bit sequence in reverse order
                cout << ((bitSeq & (1 << j)) >> j); // Extract the j-th bit of bitSeq and shift it to the right by j bits
            }
            cout << endl;
        }

        // Generate the next bit sequence
        bitSeq++; // Increment the bit sequence
    }
    return 0;
}

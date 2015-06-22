#ifndef pfd_h
#define pfd_h

// --------
// includes
// --------

#include <iostream> // istream, ostream
#include <string>   // string
#include <utility>  // pair

using namespace std;

// ------------
// pfd_read
// ------------

/**
 * read the number tasks and number of rules
 * @param is
 * @return a pair of ints, representing the beginning and end of a range, [i, j]
 */
void pfd_read (const string& s);

// ------------
// pfd_eval
// ------------

/**
 *	Determine the order of the tasks
 */
void pfd_eval ();

// -------------
// pfd_print
// -------------

/**
 * print the order of the tasks
 * @param w an ostream
 */
void pfd_print (ostream& w);

// -------------
// pfd_solve
// -------------

/**
 * @param r an istream
 * @param w an ostream
 */
void pfd_solve (istream& r, ostream& w);

#endif // pfd_h

// --------
// includes
// --------

#include <cassert>  // include
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair

#include "PFD.h"

using namespace std;

int numberOfRules, numberOfRules;


// ------------
// pfd_read
// ------------

void pfd_read (const string& s) {
    istringstream sin(s);
    sin >> numberOfTask >> numberOfRules;
}

// ------------
// pfd_eval
// ------------

void pfd_eval () {
    
	
	}

// -------------
// pfd_print
// -------------

void pfd_print (ostream& w) {
    w << "working on it" << endl;}

// -------------
// pfd_solve
// -------------

void pfd_solve (istream& r, ostream& w) {
    string s;
    getline(r, s)
        pfd_read(s);
        pfd_eval();
        pfd_print(w);
    
}
		

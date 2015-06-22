// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2015
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // include
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair

#include "Collatz.h"

using namespace std;
#define CACHESIZE 1000000


#ifdef CACHESIZE
int cacheArray [CACHESIZE] = {0,1,2,0};
#endif
// ------------
// collatz_read
// ------------

pair<int, int> collatz_read (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    return make_pair(i, j);}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
    int largest = 1;

    assert(i > 0 ); // assert that negatives aren't entered
    assert(j > 0 );
    assert(i < 1000000); //assert that numbers don't exceed 1,000,000
    assert(i < 1000000);

    if(i > j){ //swap the values
        int temp = i;
        i = j;
        j = temp;
    }

	for(int x = i; x <= j; x++){
       int t = -1; //if overflow occurs default is -1
       
       try{//checks for an overflow
	       t = collatz_recurse(x);
        }
        catch(int& e){}

	   if(t > largest)//changes largest to t if t is larger
			largest = t;
	}
	
    return largest;}

// -------------
// collatz_print
// -------------

void collatz_print (ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) {
    string s;
    while (getline(r, s)) {
        const pair<int, int> p = collatz_read(s);
        const int            i = p.first;
        const int            j = p.second;
        const int            v = collatz_eval(i, j);
        collatz_print(w, i, j, v);
    }
}
		
// -------------
// collatz_recurse
// -------------
 int collatz_recurse(int v){
    if(v < 0) // checks for an overflow
        throw 15;
    if(v < 1000000) //checks that the number can exist in the cache
        if(cacheArray[v] != 0) //checks that if the number already exist in the cache
            return cacheArray[v];
	if(v % 2 == 0){
        int t = 0;

        try{
            t = 1 + collatz_recurse(v / 2);
        }
        catch(int& e){
            throw 15;
        }

        if(v < 1000000)//checks that the number can exist in the cache
            return cacheArray[v] = t;
		return t;
    }
	else{
        int t = 0;

        try{
            t = 2 + collatz_recurse((v + (v >> 1) + 1));
        }
        catch(int& e){
            throw 15;
        }
        
        if(v < 1000000)//checks that the number can exist in the cache
            cacheArray[v] = t;
		return t;
    }
 }

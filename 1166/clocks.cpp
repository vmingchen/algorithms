/*
 * =====================================================================================
 *
 *       Filename:  clocks.cpp
 *
 *    Description:  POJ 1166. The Clocks
 *
 *        Version:  1.0
 *        Created:  06/27/2009 07:50:19 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  BUAA.edu
 *
 * =====================================================================================
 */

#include	<iostream>

using namespace std;

int otime[9] = {0};
int states[9] = {0};

const int movements[9][9] = {  
	{1, 1, 0, 1, 1, 0, 0, 0, 0},
	{1, 1, 1, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 0, 1, 1, 0, 0, 0},
	{1, 0, 0, 1, 0, 0, 1, 0, 0},//
	{0, 1, 0, 1, 1, 1, 0, 1, 0},//
	{0, 0, 1, 0, 0, 1, 0, 0, 1},
	{0, 0, 0, 1, 1, 0, 1, 1, 0},
	{0, 0, 0, 0, 0, 0, 1, 1, 1},//
	{0, 0, 0, 0, 1, 1, 0, 1, 1}//
};

void move(int *moves, int mcode, int ntimes)
{
    for (int i=0; i<9; ++i) {
	moves[i] += movements[mcode][i]*ntimes;
    }
}

bool success()
{
    int moves[9] = {0};
    for (int i=0; i<9; ++i) {
	move(moves, i, states[i]);
    }
    for (int i=0; i<9; ++i) {
	if ( (moves[i] + otime[i]) % 4 != 0 ) 
	    return false;
    }
    return true;
}

bool search(int k)
{
    if ( k == 9 ) {
	return success();
    } else {
	for (int i=0; i<4; ++i) {
	    states[k] = i;
	    if ( search(k+1) ) {
		return true;
	    }
	}
	return false;
    }
}

    int
main ( int argc, char *argv[] )
{
    int results[36], len=0;

    for (int i=0; i<9; ++i) {
	cin >> otime[i];
    }

    search(0);
    for (int i=0; i<9; ++i) {
	for (int j=0; j<states[i]; ++j) 
	    results[len++] = (i+1);
    }
    if ( len > 0 ) {
	cout << results[0];
	for (int i=1; i<len; ++i) {
	    cout << " " << results[i];
	}
	cout << endl;
    }

    return 0;
}	

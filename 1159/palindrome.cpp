/*
 * =====================================================================================
 *
 *       Filename:  palindrome.cpp
 *
 *    Description:  POJ 1159. Palindrome. Scrolling array can be applied to reduce memory
 *
 *        Version:  1.0
 *        Created:  06/19/2009 03:12:56 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  BUAA.edu
 *
 * =====================================================================================
 */


#include	<iostream>
#include	<string>

using namespace std;

const int MAX_LEN = 5000;

string palindrome;
short N, f[MAX_LEN][MAX_LEN+1] = {{0}};

int main ( int argc, char *argv[] )
{
    cin >> N >> palindrome;

    for ( int i = 0; i < N; ++i ) {
	f[i][0] = f[i][1] = 0;	// no insert is needed for empty string and char
    }

    for ( int l = 2; l <= N; ++l ) {
	for ( int i = 0; i <= N - l; ++i ) {
	    int ml = 0;
	    if ( palindrome[i] == palindrome[i+l-1] )
		ml = f[i+1][l-2];
	    else
		ml = MAX_LEN;
	    if ( (f[i+1][l-1] + 1) < ml ) ml = f[i+1][l-1] + 1;
	    if ( (f[i][l-1] + 1) < ml ) ml = f[i][l-1] + 1;
	    f[i][l] = ml;
	}
    }

    cout << f[0][N] << endl;
     
    return 0;
}	

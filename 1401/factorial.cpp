/*
 * =====================================================================================
 *
 *       Filename:  factorial.cpp
 *
 *    Description:  POJ 1401. Factorial. Number of tailing zeros of factorial.
 *
 *        Version:  1.0
 *        Created:  06/18/2009 02:59:41 PM
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


    int
main ( int argc, char *argv[] )
{
    int N, num, nZeros;
    
    cin >> N;
    for (int i=0; i<N; ++i) {
	cin >> num;
	nZeros = 0;
	while ( num ) {
	    num /= 5;
	    nZeros += num;
	}
	cout << nZeros << endl;
    }

    return 0;
}	

/*
 * =====================================================================================
 *
 *       Filename:  cornfield.cpp
 *
 *    Description:  POJ 2019
 *
 *        Version:  1.0
 *        Created:  06/15/2009 10:27:17 AM
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
    int N, B, K;

    if ( cin >> N >> B >> K ) {
	unsigned char farm[N][N];
	for (int i=0; i<N; ++i ) {
	    for (int j=0; j<N; ++j ) {
		cin >> farm[i][j];
	    }
	}
	unsigned char max, min;
	for ( int k=0; k<K; ++k ) {
	    int x, y;
	    cin >> x >> y;
	    min = 255; max = 0;
	    for ( int i=x-1; i<x-1+B; ++i ) {
		for ( int j=y-1; j<y-1+B; ++j ) {
		    if ( farm[i][j] > max ) max = farm[i][j];
		    if ( farm[i][j] < min ) min = farm[i][j];
		}
	    }
	    cout << (max-min) << endl;
	}
    }

    return 0;
}				/* ----------  end of function main  ---------- */

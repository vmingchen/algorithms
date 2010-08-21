/*
 * =====================================================================================
 *
 *       Filename:  icow.cpp
 *
 *    Description:  POJ 3665. iCow
 *
 *        Version:  1.0
 *        Created:  06/28/2009 05:46:58 PM
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

const size_t MAXN = 1001;

    int
main ( int argc, char *argv[] )
{
    int n, N, t, T;
    int rates[MAXN], res, avg, maxi, maxv, pi;

    cin >> N >> T;
    for (n=1; n<=N; ++n) {
	cin >> rates[n];
    }

    res = avg = pi = 0;
    for ( t=0; t<T; ++t ) {
	maxi = 0;
	maxv = -1;
	for ( n=1; n<=N; ++n) {
	    if ( n != pi ) rates[n] += avg;
	    if ( res && n != pi ) {
		rates[n] += 1;
		--res;
	    }
	    if ( rates[n] > maxv ) {
		maxi = n;
		maxv = rates[n];
	    }
	}
	cout << maxi << endl;
	if ( N > 1 ) {
	    avg = maxv / (N-1);
	    res = maxv - avg*(N-1);
	}
	rates[maxi] = 0;
	pi = maxi;
    }
    return 0;
}	


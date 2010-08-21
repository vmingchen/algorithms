/*
 * =====================================================================================
 *
 *       Filename:  argus.cpp
 *
 *    Description:  POJ 2051
 *
 *        Version:  1.0
 *        Created:  07/12/2009 11:22:56 PM
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

const int MAXL = 11;
const int MAXI = 1001;
const int MAXK = 10001;

inline int gcd(int a, int b) 
{
    while ( a != b ) {
	if ( a > b ) a -= b;
	else b -= a;
    }
    return a;
}

int main()
{
    char str[MAXL];
    int qnums[MAXI], periods[MAXI], N=0, K;
    int interval, circ, results[MAXK], R, r;

    while ( cin >> str && str[0] != '#' ) {
	if ( str[0] == 'R' ) {
	    cin >> qnums[N];
	    cin >> periods[N];
	    ++N;
	}
    }
    cin >> K;

    interval = periods[0];
    for (int n=1; n<N && interval>1; ++n) {
	interval = gcd(periods[n], interval);
    }

    circ = periods[0];
    for (int n=1; n<N; ++n) {
	circ *= (periods[n]/interval);
    }

    R = 0;
    for (int t=interval; t<=circ; t+=interval) {
	for (int n=0; n<N; ++n) {
	    if ( t % periods[n] == 0 ) {
		results[R++] = n;
		if ( R == MAXK ) break;
	    }
	}
	if ( R == MAXK ) break;
    }	

    r = 0;
    for (int i=0; i<K; ++i) {
	cout << qnums[results[r]] << endl;
	if ( ++r == R ) r = 0;

    }

    return 0;
}

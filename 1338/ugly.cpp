/*
 * =====================================================================================
 *
 *       Filename:  ugly.cpp
 *
 *    Description:  POJ 1138. Ugly Number
 *
 *        Version:  1.0
 *        Created:  07/13/2009 03:29:06 PM
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

const int MAXN = 1501;

inline long min(long a, long b, long c) 
{
    return a < b ? ( a < c ? a : c ) : ( b < c ? b : c );
}

int main()
{
    long mc, c2, c3, c5, n2, n3, n5, results[MAXN];
    int r = 0;

    results[++r] = 1;
    c2 = c3 = c5 = 1;
    while ( r < MAXN ) {
	n2 = results[c2]*2; 
	n3 = results[c3]*3; 
	n5 = results[c5]*5;
	mc = min(n2, n3, n5);
	results[++r] = mc;
	if ( mc == n2 ) ++c2;
	if ( mc == n3 ) ++c3;
	if ( mc == n5 ) ++c5;
    }

    int i;
    while ( cin >> i && i != 0 ) {
	cout << results[i] << endl;
    }

    return 0;
}

/*
 * =====================================================================================
 *
 *       Filename:  los.cpp
 *
 *    Description:  POJ 2533. Dynamic Programming
 *
 *        Version:  1.0
 *        Created:  06/18/2009 10:05:16 AM
 *       Revision:  none
 *       Compiler:  g++
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
    int N, l, max, max_len=0;
    // len[k] is the max length so far ending with k
    int seq[1000], len[10000];

    if ( !(cin >> N) ) return 1;

    for (int i=0; i<N; ++i) cin >> seq[i];

    for (int i=0; i<10000; ++i) len[i] = 0;

    for (int i=0; i<N; ++i) {
	max = 0;
	for(int j=0; j<seq[i]; ++j) {
	    if ( len[j] > max ) max = len[j];
	}
	l = max + 1;
	if ( l > len[seq[i]] ) len[seq[i]] = l;
    }

    max_len = 0;
    for (int i=0; i<N; ++i) {
	if ( len[seq[i]] > max_len ) {
	    max_len = len[seq[i]];
	}
    }

    cout << max_len << endl;

    return 0;
}				/* ----------  end of function main  ---------- */

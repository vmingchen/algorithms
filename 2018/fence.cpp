/*
 * =====================================================================================
 *
 *       Filename:  fence.cpp
 *
 *    Description:  POJ 2018
 *
 *        Version:  1.0
 *        Created:  06/14/2009 09:21:14 PM
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
    int N, F;
    
    if ( cin >> N >> F ) {
	int fields[N];
	for ( int i=0; i<N; ++i ) {
	    cin >> fields[i];
	}

	int st, end, sum, len;
	double max_avg = 0.0;
	end = st = sum = len = 0;
	while ( len++ < F ) {
	    sum += fields[end++];
	}
	max_avg = sum/len;

	while ( st < end ) {
	    sum += fields[++end];
	    ++len;
	    

	    while ( fields[st]*len <= sum && len> F  ) {
		sum -= fields[st++];
		--len;
	    }

	    if ( max_avg*len < sum ) {
		max_avg = sum/len;
	    }
	}
	
    }

    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

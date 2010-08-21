/*
 * =====================================================================================
 *
 *       Filename:  joseph.cpp
 *
 *    Description:  POJ 1012. Joseph.
 *
 *        Version:  1.0
 *        Created:  06/18/2009 03:23:09 PM
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
    int m, n, k;
    int guys[30], nExecuted, label, cur;

    while ( cin >> k && k != 0 ) {
	n = 2*k;
	nExecuted = 0;
	for (m=k+1; nExecuted<k; ++m) {
	    // all guys are initially alive
	    nExecuted = 0;
	    for (cur=1; cur<=n; ++cur) guys[cur] = 1;	

	    label = 0;
	    cur = 0;
	    while ( true ) {
		while ( ++cur<=n && !guys[cur] ) ;	// bypass dead guys
		if ( cur > n ) {			// reach the end
		    cur = 0;				// wrap around the end
		    while ( ++cur<=n && !guys[cur] ) ;	// bypass dead guys
		}
		
		++label; 			// count
		
		if ( label == m ) { 		// in turn now
		    if ( cur <= k ) break;	// good guy cannot die
		    ++nExecuted;
		    guys[cur] = 0;		// execute bay guy
		    label = 0;
		}
		if ( nExecuted == k ) break;	// all bad guys executed

		if ( cur > n ) cur = 0;		// loop
	    }
	}

	cout << m-1 << endl;
    }

    return 0;
}	

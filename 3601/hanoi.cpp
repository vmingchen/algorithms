/*
 * =====================================================================================
 *
 *       Filename:  hanoi.cpp
 *
 *    Description:  POJ problem 3601
 *
 *        Version:  1.0
 *        Created:  02/22/2009 11:41:11 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  BUAA.edu
 *
 *        Let $K_n$ be the number of optimal movement and $U_n$ be the number of optimal
 *        movement when ordering is not required to be preseved.
 *        	$U_n = 2U_{n-1} + a_n$
 *        if $a_n = 1$
 *        	$K_n = 2U_{n-1} + 1$,
 *        or else
 *		$K_n = K_{n-1} + 2U_{n-1} + 2a_n$
 *
 * =====================================================================================
 */
#include <iostream>

static const int MAX = 100;

using namespace std;

int solve ( int *a, int n, int m );

    int
main ( int argc, char *argv[] )
{
    int n, m;
    int a[MAX];

    while ( cin >> n >> m ) {
	for ( int i=0; i<n; i++ ) {
	    cin >> a[i];
	}

	cout << solve(a, n, m) << endl;
    } 

    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */


    int
solve ( int *a, int n, int m )
{
    int k, u;
    
    k = 2*a[0] - 1; u = a[0];
    for ( int i=1; i<n; i++ ) {
	if ( a[i] == 1 ) {
	    k = 2*u + 1;
	} else {
	    k = k + 2*u + 2*a[i];
	}
	u = 2*u + a[i];

	while ( k >= m ) k -= m;
	while ( u >= m ) u -= m;
    }

    return k;
}		/* -----  end of function solve  ----- */

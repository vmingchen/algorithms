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


#include	<stdio.h>
#define 	MAXN 	250

    int
main ( int argc, char *argv[] )
{
    unsigned char farm[MAXN][MAXN];
    unsigned char row_max[MAXN][MAXN];
    unsigned char row_min[MAXN][MAXN];
    int N, B, K;
    int i, j, k, l, x, y;

    if ( scanf("%d %d %d\n", &N, &B, &K) ) {
	for (i=0; i<N; ++i ) {
	    for (j=0; j<N; ++j ) {
		scanf("%d", &farm[i][j]);
	    }
	}
	for ( i=0; i<N; ++i ) {
	    for ( j=0; j<N-B+1; ++j ) {
		row_max[i][j] = 0;
		row_min[i][j] = 255;
		for ( l=0; l<B; ++l ) {
		    unsigned char cf = farm[i][j+l];
		    if ( cf > row_max[i][j] ) row_max[i][j] = cf;
		    if ( cf < row_min[i][j] ) row_min[i][j] = cf;
		}
	    }
	}

	for ( k=0; k<K; ++k ) {
	    scanf("%d %d", &x, &y);
	    --x; --y;
	    unsigned char max = 0, min = 255;
	    for ( i=x; i<x+B; ++i ) {
		if ( max < row_max[i][y] ) max = row_max[i][y];
		if ( min > row_min[i][y] ) min = row_min[i][y];
	    }
	    printf("%d\n", max-min);
	}
    }

    return 0;
}				/* ----------  end of function main  ---------- */

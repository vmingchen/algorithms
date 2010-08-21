/*
 * =====================================================================================
 *
 *       Filename:  board.cpp
 *
 *    Description:  POJ 1191 棋盘分割. DP. mss[xst][xend][yst][yend][n] is the minimum square sum of
 *    the board[xst..xend, yst..yend] when it is divided into n blocks.
 *
 *        Version:  1.0
 *        Created:  08/22/2009 01:33:10 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  BUAA.edu
 *
 * =====================================================================================
 */

#include	<iostream>
#include	<cstring>
#include	<cmath>
#include	<iomanip>

using namespace std;

const int MAXS = 8;
const int MAXN = 16;

int N, board[MAXS][MAXS], cumsum[MAXS][MAXS], mss[MAXS][MAXS][MAXS][MAXS][MAXN];

int square(int rst, int rend, int cst, int cend)
{
    int sq = 0;
    if ( rst == 0 ) {
	if ( cst == 0 ) {
	    sq = cumsum[rend][cend];
	} else {
	    sq = cumsum[rend][cend] - cumsum[rend][cst-1];
	}
    } else {
	if ( cst == 0 ) {
	    sq = cumsum[rend][cend] - cumsum[rst-1][cend];
	} else {
	    sq = cumsum[rend][cend] + cumsum[rst-1][cst-1] 
		    - cumsum[rst-1][cend] - cumsum[rend][cst-1];
	}
    }
    return sq*sq;
}

int main()
{
    cin >> N;

    for ( int i = 0; i < MAXS; ++i ) {
	int rowsum = 0;
	for ( int j = 0; j < MAXS; ++j ) {
	    cin >> board[i][j];
	    rowsum += board[i][j];
	    if ( i > 0 ) {
		cumsum[i][j] = cumsum[i-1][j] + rowsum;
	    } else {
		cumsum[i][j] = rowsum;
	    }
	}
    }

    for ( int xst = 0; xst < MAXS; ++xst ) {
	for ( int yst = 0; yst < MAXS; ++yst ) {
	    for ( int xend = xst; xend < MAXS; ++xend ) {
		for ( int yend = yst; yend < MAXS; ++yend ) {
		    mss[xst][xend][yst][yend][1] = square(xst, xend, yst, yend);
		}
	    }
	}
    }

    for ( int n = 2; n <= N; ++n ) {
	for ( int xst = 0; xst < MAXS; ++xst ) {
	    for ( int yst = 0; yst < MAXS; ++yst ) {
		for ( int xend = xst; xend < MAXS; ++xend ) {
		    for ( int yend = yst; yend < MAXS; ++yend ) {
			int cmss = square(0, MAXS-1, 0, MAXS-1);
			for ( int xmid = xst; xmid < xend; ++xmid ) {
			    int nmss = mss[xst][xmid][yst][yend][n-1] + square(xmid+1, xend, yst, yend);
			    if ( nmss < cmss ) cmss = nmss;
			    nmss = mss[xmid+1][xend][yst][yend][n-1] + square(xst, xmid, yst, yend);
			    if ( nmss < cmss ) cmss = nmss;
			}
			for ( int ymid = yst; ymid < yend; ++ymid) {
			    int nmss = mss[xst][xend][yst][ymid][n-1] + square(xst, xend, ymid+1, yend);
			    if ( nmss < cmss ) cmss = nmss;
			    nmss = mss[xst][xend][ymid+1][yend][n-1] + square(xst, xend, yst, ymid);
			    if ( nmss < cmss ) cmss = nmss;
			}
			mss[xst][xend][yst][yend][n] = cmss;
		    }
		}
	    }
	}
    }


    double mean = double(cumsum[MAXS-1][MAXS-1])/N;
    double var = sqrt( double(mss[0][MAXS-1][0][MAXS-1][N])/N - mean*mean);

    cout << setprecision(3) << fixed;
    cout << var << endl;

    return 0;
}

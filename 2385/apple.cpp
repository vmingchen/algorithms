/*
 * =====================================================================================
 *
 *       Filename:  apple.cpp
 *
 *    Description:  POJ 2385. Apple Catching. 
 *    DP: let f[t][w][s] be the answer when there are t seconds left, and the allowed movements
 *    is w and the Bessie is currently under tree (s+1). If we don't move when there are t seconds
 *    left, we have 
 *	    f[t][w][s] = f[t-1][w][s] + (hit(t, s) == s); 
 *    or else, we have
 *    	    f[t][w][s] = f[t-1][w-1][neg(s)] + (miss(t, s) == s).
 *    Moveover, it is possible to reduce memory usage using rolling array. However the availabe
 *    memory is suffice even without this optimization.
 *
 *        Version:  1.0
 *        Created:  08/09/2009 06:42:29 PM
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

const int MAXT = 1000;
const int MAXW = 30;

short f[MAXT+1][MAXW+1][2];
short apples[MAXT+1];

inline short neg(short a) { return a ? 0 : 1; }				// move
inline short hit(int t, short s) { return s == apples[t] ? s : neg(s); } // hit state
inline short miss(int t, short s) { return neg(hit(t, s)); }		// miss state
inline short min(short a, short b) { return a < b ? a : b; }
inline short max(short a, short b) { return a > b ? a : b; }

int main()
{
    int T, W, t, w, s;

    cin >> T >> W;
    for ( t = T; t > 0; --t ) {
	cin >> apples[t];
	--apples[t];
    }

    f[0][0][0] = 0;
    f[0][0][1] = 0;
    for ( t = 1; t <= T; ++t ) {
	for ( w = 0; w <= t && w <= W; ++w ) {
	    for ( s = 0; s <= 1; ++s ) {
		short h = hit(t, s), m = miss(t, s), mx = 0;
		if ( t > w ) {
		    mx = f[t-1][w][s] + (h == s);
		}
		if ( w > 0 ) {
		    mx = max( mx, f[t-1][w-1][neg(s)] + (m == s) );
		}
		f[t][w][s] = mx;
	    }
	}
    }

    cout << f[T][min(T, W)][0] << endl;

    return 0;
}

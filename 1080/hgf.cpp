/*
 * =====================================================================================
 *
 *       Filename:  hgf.cpp
 *
 *    Description:  POJ 1080. Human Gene Functions
 *
 *        Version:  1.0
 *        Created:  06/21/2009 02:45:26 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  BUAA.edu
 *
 * =====================================================================================
 */


#include	<iostream>
#include	<string>

using namespace std;

const int MAX_LEN = 101;

const int SIM[5][5] = {
    {5, -1, -2, -1, -3},
    {-1, 5, -3, -2, -4},
    {-2, -3, 5, -2, -2},
    {-1, -2, -2, 5, -1},
    {-3, -4, -2, -1, 0}
};

inline unsigned int code(const char c) 
{
    switch (c) {
	case 'A':
	    return 0;
	case 'C':
	    return 1;
	case 'G':
	    return 2;
	case 'T':
	    return 3;
	default:
	    return 4;
    }
}

inline int get_sim(const char a, const char b)
{
    return SIM[code(a)][code(b)];
}

inline int max(const int x, const int y, const int z)
{
    if ( x >= y && x >= z ) return x;
    else if ( y >= x && y >= z ) return y;
    else return z;
}


    int
main ( int argc, char *argv[] )
{
    int similarity[MAX_LEN][MAX_LEN];
    string a, b;
    unsigned int t, T, m, n, l, k;
    int sim1, sim2, sim3;

    cin >> T;
    for (t=0; t<T; ++t) {
	cin >> m >> a;
	cin >> n >> b;

	// initialize
	for (l=0; l<=m; ++l) 
	    for (k=0; k<=n; ++k)
		similarity[l][k] = 0;
	
	// DP
	for (l=0; l<=m; ++l) {
	    for (k=0; k<=n; ++k) {
		sim1 = sim2 = sim3 = -500;
		if ( k > 0 && l == 0 ) {
		    sim1 = similarity[l][k-1] + get_sim('-', b[k-1]);
		} else if ( k == 0 && l > 0 ) {
		    sim2 = similarity[l-1][k] + get_sim(a[l-1], '-');
		} else if ( k > 0 && l > 0 ) {
		    sim1 = similarity[l][k-1] + get_sim('-', b[k-1]);
		    sim2 = similarity[l-1][k] + get_sim(a[l-1], '-');
		    sim3 = similarity[l-1][k-1] + get_sim(a[l-1], b[k-1]);
		} else {
		    continue;
		}
		similarity[l][k] = max(sim1, sim2, sim3);
//		cout << similarity[l][k] << "\t";
	    }
//	    cout << endl;
	}

	cout << similarity[m][n] << endl;
    }

    return 0;
}				/* ----------  end of function main  ---------- */

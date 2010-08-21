/*
 * =====================================================================================
 *
 *       Filename:  post.cpp
 *
 *    Description:  POJ 1160 Post Office. DP
 *    mindis[i][j] (j < i) is the mininum distance of the first i villages (1 to i) when there is a
 *    post at i and j post offices can be built between 1 to i-1 [1...i-1].
 *
 *        Version:  1.0
 *        Created:  08/23/2009 10:48:08 PM
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

const int MAXV = 300;
const int MAXP = 30;
const int MAXX = 10000;
int V, P, 
    villages[MAXV+1], 
    cumsum[MAXV+1], 
    mindis[MAXV+1][MAXP+1];

int cdist(int v1, int v2)
{
    int m, lf, rf, midv = (villages[v1] + villages[v2])/2;

    for ( lf = 0, m = v1; villages[m] <= midv && m < v2; ++m )
	lf += villages[m] - villages[v1];
    for ( rf = 0; m <= v2; ++m )
	rf += villages[v2] - villages[m];
    return lf + rf;
}

int rdist(int v)
{
    return cumsum[V] - cumsum[v] - (V - v) * villages[v];
}

int main()
{

    cin >> V >> P;

    for ( int v = 1; v <= V; ++v ) cin >> villages[v];

    cumsum[0] = 0;
    for ( int v = 1; v <= V; ++v ) {
	cumsum[v] = cumsum[v-1] + villages[v];
	mindis[v][0] = v * villages[v] - cumsum[v];
    }

    for ( int v = 1; v <= V; ++v ) {
	for ( int p = 1; p < v && p < P; ++p ) {
	    int min = MAXX*MAXV;
	    for ( int t = p; t < v; ++t ) {
		int d = mindis[t][p-1] + cdist(t, v);
		if ( d < min ) min = d;
	    }
	    mindis[v][p] = min;
	}
    }

    int res = MAXX*MAXV;
    for ( int v = V; v >= P; --v ) {
	int d = mindis[v][P-1] + rdist(v);
	if ( d < res ) res = d;
    }

    cout << res << endl;
    
    return 0;
}

/*
 * =====================================================================================
 *
 *       Filename:  charm.cpp
 *
 *    Description:  POJ 3626. Charm Bracelet
 *
 *        Version:  1.0
 *        Created:  07/01/2009 11:38:59 PM
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

const int MAXN = 3403;
const int MAXM = 12881;

int main()
{
    int N, M, W[MAXN], D[MAXN];
    int fnm, fnn, fn[MAXM] = {0};

    if ( cin >> N >> M ) {
	for (int i=0; i<N; ++i) {
	    cin >> W[i] >> D[i];
	}
    }

    for (int i=0; i<N; ++i) {
	for (int j=M; j>=W[i]; --j) {
	    fnn = fn[j-W[i]] + D[i];
	    if ( fnn > fn[j] ) fn[j] = fnn;
	}
    }

    fnm = 0;
    for (int i=0; i<=M; ++i) {
	if ( fn[i] > fnm ) fnm = fn[i];
    }

    cout << fnm << endl;
    return 0;
}

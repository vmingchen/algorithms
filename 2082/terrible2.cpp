/*
 * =====================================================================================
 *
 *       Filename:  terrible.cpp
 *
 *    Description:  POJ 2082.Terrible Sets. Dynamic Programming 
 *
 *        Version:  1.0
 *        Created:  06/25/2009 10:34:28 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  BUAA.edu
 *
 * =====================================================================================
 */

#include	<iostream>
#include	<vector>
#include	<algorithm>
#include	<set>

using namespace std;

    int
main ( int argc, char *argv[] )
{
    int n, h, ph, max;

    while ( cin >> n && n != -1 ) {
	vector<int> ws(n), hs(n), fv(n);
	set<int> idx;
	set<int>::iterator it;

	// read input
	for (int i=0; i<n; ++i) {
	    cin >> ws[i] >> hs[i];
	    idx.insert(hs[i]);
	}

	// init with the first <wi, hi>, namely <w0, h0>
	for (it=idx.begin(), h=0; h<n; ++it, ++h) {
	    fv[h] = ws[0]*(*it);
	    if ( *it == hs[0] ) break;
	}
	max = fv[h];
	ph = h;
	while ( ++h < n ) fv[h] = 0;

	// for test
//	cout << "---------------------" << endl;
//	for (int j=0; j<n; ++j) cout << fv[j] << " ";
//	cout << endl;

	for (int i=1; i<n; ++i) {
	    // dynamic programming, f_k(h) = f_{k-1}(h) for all h<=hs[i]
	    for (it=idx.begin(), h=0; h < n; ++it, ++h) {
		fv[h] += ws[i]*(*it);
		if ( fv[h] > max ) max = fv[h];
		if ( *it == hs[i] ) break;
	    }
	    while ( ph > h ) fv[ph--] = 0;

	    // for test
//	    for (int j=0; j<n; ++j) cout << fv[j] << " ";
//	    cout << endl;
	}

	cout << max << endl;
    }

    return 0;
}	

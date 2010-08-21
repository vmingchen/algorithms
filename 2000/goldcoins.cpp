/*
 * =====================================================================================
 *
 *       Filename:  goldcoins.cpp
 *
 *    Description:  POJ problem 2000
 *
 *        Version:  1.0
 *        Created:  02/23/2009 07:53:52 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  BUAA.edu
 *
 * =====================================================================================
 */

#include	<iostream>
#include	<map>
#include	<algorithm>
#include	<iterator>
#include	<vector>

using namespace std;

const int MAX = 20;

    int
main ( int argc, char *argv[] )
{
    int key, ind, val, n;
    vector<int> results(MAX);
    vector<int> keys(MAX);
    map<int, int> cases;
    map<int, int>::const_iterator it;

    for ( n=0; cin >> key; n++ ) {
	if ( key==0 ) break;
	cases.insert(make_pair(key, n));
	keys[n] = key;
    }

    it = cases.begin();
    ind = val = 0;
    for ( int i=1; it!=cases.end(); i++ ) {
	while ( ind+i >= it->first && it!=cases.end() ) {
	    results[it->second] = val + (it->first - ind)*i;
	    ++it;
	}

	val += i*i;
	ind += i;
    }

    for ( int i=0; i<n; i++ ) {
	cout << keys[i] << " " << results[i] << endl;
    }

    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */


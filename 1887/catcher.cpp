/*
 * =====================================================================================
 *
 *       Filename:  catcher.cpp
 *
 *    Description:  POJ 1887. Testing the CATCHER.
 *
 *        Version:  1.0
 *        Created:  06/28/2009 04:02:19 PM
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

using namespace std;

    int
main ( int argc, char *argv[] )
{
    int nTest, fh, height, max;
    map<int, int> ml;
    map<int, int>::reverse_iterator it;

    for (nTest=1; cin >> fh && fh != -1; ++nTest) {
	ml.clear();
	ml.insert(make_pair(fh, 1));
	while ( cin >> height && height != -1 ) {
	    max = 0;
	    for ( it = ml.rbegin(); it != ml.rend() && it->first >= height; ++it ) {
		if ( it->second > max ) max = it->second;
	    }
	    ml[height] = max + 1;
	}
	max = 0;
	for ( it = ml.rbegin(); it != ml.rend(); ++it ) {
	    if ( it->second > max ) max = it->second;
	}
	cout << "Test #" << nTest <<":" << endl;
        cout << "  maximum possible interceptions: " << max << endl << endl;
    }

    return 0;
}	

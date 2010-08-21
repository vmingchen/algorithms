/*
 * =====================================================================================
 *
 *       Filename:  blue.cpp
 *
 *    Description:  POJ 3080. 
 *
 *        Version:  1.0
 *        Created:  07/04/2009 06:57:50 PM
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
#include	<vector>

using namespace std;

int main()
{
    int n, m, N, M;
    vector<string> strs(10);
    string lcs, str;

    cin >> N;
    for (n=0; n<N; ++n) {
	cin >> M;
	for (m=0; m<M; ++m) {
	    cin >> strs[m];
	}
	lcs = "";
	for (int k=strs[0].length(); k>=3 && lcs.empty(); --k) {
	    for (int j=0; j<=strs[0].length()-k; ++j) {
		str = strs[0].substr(j, k);
		for (m=1; m<M; ++m) {
		    if ( strs[m].find(str) == string::npos )
			break;
		}
		if ( m < M ) continue;
		if ( lcs.empty() || str.compare( lcs ) < 0 ) {
		    lcs = str;
		}
	    }
	}
	if ( lcs.empty() ) {
	    cout << "no significant commonalities" << endl;
	} else {
	    cout << lcs << endl;
	}
    }
    return 0;
}

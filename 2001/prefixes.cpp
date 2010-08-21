/*
 * =====================================================================================
 *
 *       Filename:  prefixes.cpp
 *
 *    Description:  POJ problem 2001
 *
 *        Version:  1.0
 *        Created:  02/23/2009 09:57:36 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  BUAA.edu
 *
 * =====================================================================================
 */

#include	<iostream>
#include	<algorithm>
#include	<map>
#include	<iterator>
#include	<vector>

using namespace std;

inline int commsub(const string &a, const string &b) 
{
    int i=0; 
    while ( i<a.length() && i<b.length() && a[i]==b[i] ) {
	++i;
    }
    return i;
}

    int
main ( int argc, char *argv[] )
{
    int n, si, pi, ni;
    string entry, last, prefix;
    vector<string> input, output;
    map<string, int> entries;
    map<string, int>::const_iterator pre, cur, next;

    for ( n=0; cin >> entry; ++n ) {
	entries.insert(make_pair(entry, n));
	input.push_back(entry);
	output.push_back(entry);
    }

    for ( cur=entries.begin(); cur!=entries.end(); ++cur ) {
	ni = pi = 0;
	next = pre = cur;
	if ( cur != entries.begin() ) {
	    --pre;
	    pi = commsub(pre->first, cur->first);
	}
	++next;
	if ( next != entries.end() ) {
	    ni = commsub(cur->first, next->first);
	}
	si = pi>ni ? pi : ni;
	if ( si != cur->first.length() ) si += 1;
	prefix = cur->first.substr(0,  si);
	output[cur->second] = prefix;
    }

    for ( int i=0; i<n; i++ ) {
	cout << input[i] << " " << output[i] << endl;
    }

    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

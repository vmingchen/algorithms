/*
 * =====================================================================================
 *
 *       Filename:  alphacode.cpp
 *
 *    Description:  POJ 2033. Alphacode
 *
 *        Version:  1.0
 *        Created:  06/25/2009 06:55:04 PM
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

inline bool is_valid(const char a, const char b)
{
    return  ((a - '0')*10 + b - '0') <= 26;
}

int count(string code) 
{
    int pf, cf, tmp, i, n = code.length();
    if ( n == 1 ) return 1;
    pf = cf = 1;
    for ( i=1; i<n; ++i ) {
	if ( code[i] == '0' ) {
	    cf = pf;
	    continue;
	}
	if ( code[i-1] != '0' && is_valid(code[i-1], code[i]) ) {
	    tmp = cf;
	    cf = pf + cf;
	    pf = tmp;
	} else {
	    pf = cf;
	}
    }
    return cf;
}

    int
main ( int argc, char *argv[] )
{
    string str;

    while ( cin >> str && str != "0" ) 
	cout << count(str) << endl;

    return 0;
}

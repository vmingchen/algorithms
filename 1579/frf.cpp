/*
 * =====================================================================================
 *
 *       Filename:  frf.cpp
 *
 *    Description:  POJ 1579. Function Run Fun
 *
 *        Version:  1.0
 *        Created:  08/24/2009 11:47:46 PM
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

const int MAXN = 20;

int w[MAXN+1][MAXN+1][MAXN+1];

void init()
{
    for ( int a = 0; a <= MAXN; ++a )
	for ( int b = 0; b <= MAXN; ++b )
	    for ( int c = 0; c <= MAXN; ++c )
		w[a][b][c] = 1;
    for ( int a = 1; a <= MAXN; ++a ) {
	for ( int b = 1; b <= MAXN; ++b ) {
	    for ( int c = 1; c <= MAXN; ++c ) {
		if ( a < b && b < c ) {
		    w[a][b][c] = w[a][b][c-1] + w[a][b-1][c-1] - w[a][b-1][c];
		} else {
		    w[a][b][c] = w[a-1][b][c] + w[a-1][b-1][c] + w[a-1][b][c-1] - w[a-1][b-1][c-1];
		}
	    }
	}
    }
}

int query(int a, int b, int c)
{
    if ( a <= 0 || b <= 0 || c <= 0 ) 
	return 1;
    else if ( a > 20 || b > 20 || c > 20 )
	return w[20][20][20];
    else
	return w[a][b][c];
}

int main()
{
    int a, b, c;
    init();

    while ( cin >> a >> b >> c ) {
	if ( a == -1 && b == -1 && c == -1 ) break;
	cout << "w(" 
	    << a << ", "
	    << b << ", "
	    << c << ") = "
	    << query(a, b, c)
	    << endl;
    }

    return 0;
}

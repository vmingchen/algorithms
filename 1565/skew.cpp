/*
 * =====================================================================================
 *
 *       Filename:  skew.cpp
 *
 *    Description:  POJ 1565. Skew Number.
 *
 *        Version:  1.0
 *        Created:  07/04/2009 09:22:02 AM
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

int main()
{
    char skewn[100];
    int dn, k, i;

    while ( cin.getline(skewn, 100) && skewn[0] != '0' ) {
	k = 2;
	dn = 0;
	for (i=0; skewn[i] != '\0'; ++i) ;
	for ( --i, k=2; i>=0; k=k<<1, --i ) {
	    dn += (skewn[i]-'0')*(k-1);
	}
	cout << dn << endl;
    }

    return 0;
}

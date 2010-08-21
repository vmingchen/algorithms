/*
 * =====================================================================================
 *
 *       Filename:  secretary.cpp
 *
 *    Description:  POJ 2217
 *
 *        Version:  1.0
 *        Created:  07/06/2009 03:05:37 PM
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

const int MAXN = 10001;

char stra[MAXN];
char strb[MAXN];

int main()
{
    int N, n, mlen, lena, lenb;
    int lens[MAXN];

    cin >> N;
    for (n = 0; n<N; ++n) {
	do {
	    cin.getline(stra, MAXN);
	} while ( stra[0] == '\0' );
	do {
	    cin.getline(strb, MAXN);
	} while ( strb[0] == '\0' );
	mlen = 0;

	for ( lena=0; stra[lena] != '\0'; ++lena ) ;
	for ( lenb=0; strb[lenb] != '\0'; ++lenb ) ;

	for ( int ia=0; ia<=lena; ++ia ) lens[ia] = 0;

	for ( int ib=1; ib<=lenb; ++ib ) {
	    for ( int ia=lena; ia>=1; --ia ) {
		if ( stra[ia-1] == strb[ib-1] ) {
		    lens[ia] = lens[ia-1] + 1;
		    if ( lens[ia] > mlen ) 
			mlen = lens[ia];
		} else {
		    lens[ia] = 0;
		}
	    }
	}

	cout << "Nejdelsi spolecny retezec ma delku " << mlen << "." << endl;
    }

    return 0;
}

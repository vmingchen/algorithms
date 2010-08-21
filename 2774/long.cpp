/*
 * =====================================================================================
 *
 *       Filename:  long.cpp
 *
 *    Description:  POJ 2774. Long Long Message
 *
 *        Version:  1.0
 *        Created:  07/12/2009 03:02:21 PM
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

const int MAXN = 100001;

int main()
{
    char stra[MAXN], strb[MAXN];
    int mlen, t, lena, lenb;
    short lens[MAXN] = {0};

    cin.getline(stra, MAXN);
    cin.getline(strb, MAXN);

    for (lena=0; stra[lena] != '\0'; ++lena) ;
    for (lenb=0; strb[lenb] != '\0'; ++lenb) ;

    mlen = 0;
    for (int i=1; i<=lena; ++i) {
	for (int j=lenb; j>0; --j) {
	    if ( stra[i-1] == strb[j-1] ) {
		t = lens[j-1] + 1;
		if ( t > mlen ) mlen = t;
	    } else {
		t = 0;
	    }
	    lens[j] = t;
	}
    }

    cout << mlen << endl;

    return 0;
}

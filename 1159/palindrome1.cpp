/*
 * =====================================================================================
 *
 *       Filename:  palindrome.cpp
 *
 *    Description:  POJ 1159. Palindrome
 *
 *        Version:  1.0
 *        Created:  06/19/2009 03:12:56 PM
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
#include	<iterator>

using namespace std;

typedef string::iterator Strit1;
typedef string::reverse_iterator Strit2;

const int MAX_LEN = 250;

inline int my_max(const int x, const int y, const int z)
{
    if ( x >= y && x >= z ) return x;
    else if ( y >= x && y >= z ) return y;
    else return z;
}

size_t lcs(Strit1 beg1, Strit1 end1, size_t m,
	Strit2 beg2, Strit2 end2, size_t n)
{
    size_t l, k, x, y, z;
    size_t cslens[MAX_LEN][MAX_LEN]; 

    for (l=0; l<=m; ++l) {
	for (k=0; k<=n; ++k) {
	    cslens[l][k] = 0;
	}
    }

    for (l=0; l<=m; ++l) {
	for (k=0; k<=n; ++k) {
	    x = y = z = 0;
	    if ( l==0 && k>0 ) {
		x = cslens[l][k-1];
	    } else if ( l>0 && k==0 ) {
		y = cslens[l-1][k];
	    } else if ( l>0 && k>0 ) {
		x = cslens[l][k-1];
		y = cslens[l-1][k];
		z = cslens[l-1][k-1] + (*(beg1+l-1) == *(beg2+k-1));
	    } else {
		continue;
	    }
	    cslens[l][k] = my_max(x, y, z);
	}
    }

    return cslens[m][n];
}

size_t padding_number(string &str, size_t cur, size_t N, size_t *plen)
{
    size_t llen = cur, rlen = str.length() - cur;
    size_t lcs1, lcs2;

    // palindrome like 'abcba'
    lcs1 = lcs(str.begin()+llen+1, str.end(), rlen-1,
	    str.rbegin()+rlen, str.rend(), llen);
    lcs1 = 2*lcs1 + 1;

    // palindrome like 'abba'
    lcs2 = lcs(str.begin()+llen+1, str.end(), rlen-1,
	    str.rbegin()+rlen-1, str.rend(), llen+1);
    lcs2 = 2*lcs2;

    if ( lcs1 > lcs2 ) {
	*plen = lcs1;
	if ( lcs1 >= N ) return 0;
	if ( llen > rlen-1 ) return N - llen + lcs1/2;
	else return N - rlen - 1 + lcs1/2;
    } else {
	*plen = lcs2;
	if ( lcs2 >= N ) return 0;
	if ( llen > rlen ) return N - llen + lcs2/2;
	else return N - rlen + lcs2/2;
    }
}

    int
main ( int argc, char *argv[] )
{
    unsigned int N, min_num, num, max_slen, slen, beg, end, mid, cur;
    string str;

    cin >> N >> str;
     
    beg = 0;
    end = str.length();
    mid = end/2;

//    slen = lcs(str.begin()+mid, str.end(), mid, 
//	    str.rbegin()+mid+1, str.rend(), end-mid-1);
//    cout << slen;


    max_slen = 0;
    min_num = 2500;
    for (cur = mid; cur >= beg; --cur) {
	num = padding_number(str, cur, N, &slen);
	if ( slen > max_slen ) max_slen = slen;
	if ( num < min_num ) min_num = num;
	if ( max_slen > cur ) {
	    cout << "max_slen  > cur: " 
		<< max_slen << " > " << cur << endl;
	    break;
	}
    }

    for (cur = mid; cur < end; ++cur) {
	num = padding_number(str, cur, N, &slen);
	if ( slen > max_slen ) max_slen = slen;
	if ( num < min_num ) min_num = num;
	if ( max_slen > end-cur ) {
	    cout << "max_slen  > end-cur: " 
		<< max_slen << " > " << end-cur << endl;
	    break;
	}
    }

    cout << min_num << endl;

    return 0;
}	

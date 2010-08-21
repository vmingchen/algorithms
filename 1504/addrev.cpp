/*
 * =====================================================================================
 *
 *       Filename:  addrev.cpp
 *
 *    Description:  POJ 1504
 *
 *        Version:  1.0
 *        Created:  07/23/2009 08:45:34 PM
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

const int MAXN = 1001;

int main()
{
    char stra[MAXN], strb[MAXN], result[MAXN];
    int N;
    cin >> N;
    for (int n=0; n < N; ++n) {
	cin >> stra >> strb;
	char *pa = stra, *pb = strb, *pr = result;
	int promote = 0;
	while ( *pa != '\0' && *pb != '\0' ) {
	    int sum = (*pa++ - '0') + (*pb++ - '0') + promote;
	    *pr++ = '0' + (sum % 10);
	    promote = sum / 10;
	}

	while ( *pa != '\0' ) {
	    int sum = (*pa++ - '0') + promote;
	    *pr++ = '0' + (sum % 10);
	    promote = sum / 10;
	}

	while ( *pb != '\0' ) {
	    int sum = (*pb++ - '0') + promote;
	    *pr++ = '0' + (sum % 10);
	    promote = sum / 10;
	}

	if ( promote ) *pr++ = '0' + promote;
	*pr = '\0';

	char *pst = result;
	while ( *pst != '\0'  && *pst == '0' ) pst++;

	if ( *pst == '\0' ) {
	    cout << '0' << endl;
	} else {
	    cout << pst << endl;
	}

    }
    return 0;
}

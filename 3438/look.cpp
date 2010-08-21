/*
 * =====================================================================================
 *
 *       Filename:  look.cpp
 *
 *    Description:  POJ 3438. Look and Say
 *
 *        Version:  1.0
 *        Created:  07/03/2009 09:44:00 PM
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
    int T, num, count;
    char line[MAXN];
    cin >> T;
    for (int t=0; t<T; ++t) {
	do {
	    cin.getline(line, MAXN);
	} while ( line[0] == '\0' );
	num = -1;
	count = 0;
	for (int i=0; line[i] != '\0'; ++i) {
	    if ( line[i]-'0' == num ) ++count;
	    else {
		if ( count > 0 ) cout << count << num;
		num = line[i]-'0';
		count = 1;
	    }
	}
	cout << count << num << endl;
    }

    return 0;
}

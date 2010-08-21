/*
 * =====================================================================================
 *
 *       Filename:  quicksum.cpp
 *
 *    Description:  POJ 3094. Quicksum
 *
 *        Version:  1.0
 *        Created:  07/03/2009 10:06:11 AM
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

const int MAXN = 10000;

int main()
{
    char str[MAXN];
    int i, sum, base = 'A'-1;

    while ( cin.getline(str, MAXN) ) {
	if ( str[0] == '#' ) break;
	sum = 0;
	for ( i=0; str[i]!='\0'; ++i) {
	    if ( str[i] == ' ' ) continue;
	    else sum += (str[i] - base)*(i+1);
	}
	cout << sum << endl;
    }
}

/*
 * =====================================================================================
 *
 *       Filename:  ugly.cpp
 *
 *    Description:  POJ 1138. Ugly Number
 *
 *        Version:  1.0
 *        Created:  07/13/2009 03:29:06 PM
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

const int MAXN = 1501;

int main()
{
    int nums[MAXN], n=0;

    for (int i=1; n < MAXN; ++i) {
	int j = i;
	while ( j % 2 == 0 ) j /= 2;
	while ( j % 3 == 0 ) j /= 3;
	while ( j % 5 == 0 ) j /= 5;
	if ( j == 1 ) nums[n++] = i;
    }

    int i;
    while ( cin >> i && i != 0 ) {
	cout << nums[i-1] << endl;
    }

    return 0;
}

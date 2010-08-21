/*
 * =====================================================================================
 *
 *       Filename:  box.cpp
 *
 *    Description:  POJ 1477. Box of Bricks
 *
 *        Version:  1.0
 *        Created:  07/13/2009 10:54:56 PM
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

const int MAXN = 51;

int main()
{
    int n, c=1;
    int hs[MAXN];
    while ( cin >> n && n != 0 ) {
	int sum = 0, avg = 0;
	for (int i=0; i<n; ++i) {
	    cin >> hs[i];
	    sum += hs[i];
	}
	avg = sum / n;
	sum = 0;
	for (int i=0; i<n; ++i) {
	    if ( hs[i] > avg ) sum += (hs[i] - avg);
	    else sum += (avg - hs[i]);
	}
	cout << "Set #" << c++ << endl;
	cout << "The minimum number of moves is " << sum/2 << "." << endl;
	cout << endl;
    }
    return 0;
}

/*
 * =====================================================================================
 *
 *       Filename:  max.cpp
 *
 *    Description:  POJ 1050. To The Max
 *
 *        Version:  1.0
 *        Created:  07/07/2009 06:59:19 PM
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

const int MAXN = 500;

int max_sub(int *nums, int len)
{
    int sum=0, max = 0;
    for (int i=0; i<len; ++i) {
	if ( sum > 0 ) {
	    sum += nums[i];
	} else {
	    sum = nums[i];
	}
	if ( sum > max ) max = sum;
    }
    return max;
}

int main()
{
    int N, sum, max=0;
    int grid[MAXN][MAXN], column[MAXN];

    cin >> N;
    for (int i=0; i<N; ++i) {
	for (int j=0; j<N; ++j) {
	    cin >> grid[i][j];
	}
    }

    for (int i1=0; i1<N; ++i1) {
	for (int j=0; j<N; ++j) {
	    column[j] = 0;
	}
	for (int i2=i1; i2<N; ++i2) {
	    for (int j=0; j<N; ++j) {
		column[j] += grid[i2][j];
	    }
	    sum = max_sub(column, N);
	    if ( sum > max ) 
		max = sum;
	}
    }

    cout << max << endl;
    return 0;
}

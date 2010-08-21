/*
 * =====================================================================================
 *
 *       Filename:  median.cpp
 *
 *    Description:  POJ 2388. Who's in the middle. Median-of-three Partition 
 *
 *        Version:  1.0
 *        Created:  04/03/2010 06:52:41 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  Beihang University
 *
 * =====================================================================================
 */

#include	<iostream>

using namespace std;

const int MAXN = 10000;
int N, outputs[MAXN];

int median_of_three( int a, int b, int c )
{
    if ( a > b ) {
        if ( b > c ) {
            return b;
        } else if ( a > c ) {
            return c;
        } else {
            return a;
        }
    } else {
        if ( b < c ) {
            return b;
        } else if ( a > c ) {
            return a;
        } else {
            return c;
        }
    }
}

int partition( int beg, int end, int pivot )
{
    int first = beg, last = end-1;
    while ( true ) {
        while ( outputs[first] <= pivot && first < end ) ++first;
        while ( outputs[last] > pivot ) --last;
        if ( first >= last ) break;
        int t = outputs[first];
        outputs[first++] = outputs[last];
        outputs[last--] = t;
    }
    return first;
}

    int
main ( int argc, char *argv[] )
{ 
    cin >> N;
    for ( int i = 0; i < N; ++i ) cin >> outputs[i];
    int head = 0, tail = N, nth = (N>>1) + 1;
    while ( tail - head >= 3 ) {
        int pivot = median_of_three(outputs[head], 
                outputs[(head+tail)>>1], 
                outputs[tail-1]);
        int pos = partition( head, tail, pivot );
        if ( pos == nth || pos == tail ) {
            cout << pivot << endl;
            return 0;
        } else if ( pos > nth ) {
            tail = pos;
        } else {
            nth -= (pos - head);
            head = pos;
        }
    }
    if ( nth == 1 ) {
        cout << (outputs[head]<outputs[head+1] ? outputs[head] : outputs[head+1]) << endl;
    } else {
        cout << (outputs[head]<outputs[head+1] ? outputs[head+1] : outputs[head]) << endl;
    }
    return 0;
}				/* ----------  end of function main  ---------- */

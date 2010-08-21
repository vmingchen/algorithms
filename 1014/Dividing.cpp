/*
 * =====================================================================================
 *
 *       Filename:  Dividing.cpp
 *
 *    Description:  POJ 1014. Dividing
 *
 *        Version:  1.0
 *        Created:  04/04/2010 09:26:49 PM
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

const int MAXN = 20000;
int marbles[7] = {0};

bool divisible()
{
    int sum = 0;
    for ( int i = 1; i <= 6; ++i ) {
        sum += marbles[i]*i;
    }
    int half = sum >> 1;

    bool hit[61000] = {false};
    int next[61000] = {0};
    int prev[61000] = {0};
    int head = 0, tail = 0;
    int total = 0; 

    hit[0] = true; 
    next[0] = -1;
    prev[0] = -1;
    for ( int i = 1; i <= 6; ++i ) {
        for ( int j = 0; j < marbles[i]; ++j ) {
            for ( int k = 0; k < i; ++k ) {
                if ( ++total <= half ) {
                    next[tail] = total;
                    prev[total] = tail;
                    tail = total;
                }
            }
            for ( int cur = tail; cur >= head && cur >= i; cur = prev[cur] ) {
                if ( hit[cur-i] ) {
                    hit[cur] = true;
                    if ( cur == half ) return true;
                    if ( cur == head ) { head = next[head]; continue; }
                    if ( cur == tail ) { tail = prev[tail]; continue; }
                    next[prev[cur]] = next[cur];
                    prev[next[cur]] = prev[cur];
                }
            }
        }
    }

    return false;
}

int main()
{
    for ( int i = 1; ; ++i ) {
        cin >> marbles[1] >> marbles[2] >> marbles[3]
            >> marbles[4] >> marbles[5] >> marbles[6];
        if ( marbles[1] == 0 && marbles[2] == 0 && marbles[3] == 0
                && marbles[4] == 0 && marbles[5] == 0 && marbles[6] == 0 ) {
            break;
        }
        cout << "Collection #" << i << ":" << endl;
        if ( ((marbles[1] + marbles[3] + marbles[5]) & 0x01) != 0 || !divisible() ) {
            cout << "Can't be divided." << endl << endl;
        } else {
            cout << "Can be divided." << endl << endl;
        }
    }
    return 0;
}

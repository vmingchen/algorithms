/*
 * =====================================================================================
 *
 *       Filename:  space.cpp
 *
 *    Description:  POJ 2392. Space Elevator
 *
 *        Version:  1.0
 *        Created:  04/05/2010 07:34:39 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  Beihang University
 *
 * =====================================================================================
 */

#include	<iostream>
#include	<algorithm>
#include	<cstring>

using namespace std;

const int MAXK = 400,
      MAXA = 40000;

class Block {
public:
    int atitude, height, quantity;
    bool operator< ( const Block &other ) const {
        if ( atitude < other.atitude ) {
            return true;
        } else if ( atitude == other.atitude ) {
            if ( height < other.height ) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
};

Block blocks[MAXK];
int K, altitudes[MAXA+1];


int main()
{
    cin >> K;
    for ( int k = 0; k < K; ++k ) {
        cin >> blocks[k].height >> blocks[k].atitude >> blocks[k].quantity;
    }
    sort( blocks, blocks + K );

    memset( altitudes, 0, MAXA );
    altitudes[0] = 1;
    for ( int k = 0; k < K; ++k ) {
        for ( int t = blocks[k].atitude; t >= blocks[k].height; --t ) {
            int h = t - blocks[k].height;
            for ( int c = 1; c <= blocks[k].quantity && h >= 0; ++c, h -= blocks[k].height ) {
                if ( altitudes[h] == 1 ) altitudes[t] = 1;
            }
        }
    }

    int result = blocks[K-1].atitude;
    while ( altitudes[result] == 0 ) --result;

    cout << result << endl;

    return 0;
}

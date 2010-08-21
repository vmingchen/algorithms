/*
 * =====================================================================================
 *
 *       Filename:  roads.cpp
 *
 *    Description:  POJ 1724. Roads
 *
 *        Version:  1.0
 *        Created:  04/05/2010 03:33:17 PM
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

using namespace std;
const int MAXN = 101, 
      MAXT = 10001,
      MAXK = 10000,
      MAXL = 1000000;

class Road {
public:
    int src, dest, toll, length;
    bool operator< (const Road &other) const {
        if ( toll < other.toll ) {
            return true;
        } else if ( toll == other.toll ) {
            if ( length < other.length ) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
};

Road roads[MAXN][2*MAXN];
int K, N, R, numRoad[MAXN];
bool visited[MAXN] = {false};

int curPath[MAXN], curToll, curLength, curPos;
int bestPath[MAXN], bestToll, bestLength = MAXL;


void search( int step )
{
    if ( curPos == N && curLength < bestLength && curToll <= K ) {
        bestLength = curLength;
        bestToll = curToll;
        for ( int i = 0; i <= step; ++i ) {
            bestPath[i] = curPath[i];
        }
        return ;
    }
    int oldPos = curPos;
    for ( int i = 1; i <= numRoad[curPos]; ++i ) {
        if ( visited[roads[curPos][i].dest] 
                || curToll + roads[curPos][i].toll > K
                || curLength + roads[curPos][i].length >= bestLength ) {
            continue;
        }
        curToll += roads[curPos][i].toll;
        curLength += roads[curPos][i].length;
        curPos = roads[curPos][i].dest;
        visited[curPos] = true;
        search( step+1 );
        visited[curPos] = false;
        curToll -= roads[oldPos][i].toll;
        curLength -= roads[oldPos][i].length;
        curPos = oldPos;
    }
}

int main()
{

    cin >> K >> N >> R;
    for ( int r = 0; r < R; ++r ) {
        Road road;
        cin >> road.src >> road.dest >> road.length >> road.toll;
        roads[road.src][++numRoad[road.src]] = road;
    }
    for ( int i = 1; i <= N; ++i ) {
        sort( roads[i] + 1, roads[i] + numRoad[i] + 1 );
    }

    curPath[0] = 1;
    visited[1] = true;
    curLength = 0;
    curToll = 0;
    curPos = 1;
    search( 0 );

    if ( bestLength > 0 ) {
        cout << bestLength << endl;
    } else {
        cout << "-1" << endl;
    }

    return 0;
}

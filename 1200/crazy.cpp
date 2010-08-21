/*
 * =====================================================================================
 *
 *       Filename:  crazy.cpp
 *
 *    Description:  POJ 1200. Crazy Search 
 *
 *        Version:  1.0
 *        Created:  07/02/2009 10:22:55 AM
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

const int MAXN = 2000000;
const int MAXC = 256;

unsigned char substrs[MAXN] = {0};

unsigned char masks[8] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};

inline void set(unsigned int key)
{
    substrs[key>>3] |= masks[key & 0x07];
}

inline int count(unsigned int idx)
{
    int c = 0;
    c += (substrs[idx] & masks[0]) ? 1 : 0;
    c += (substrs[idx] & masks[1]) ? 1 : 0;
    c += (substrs[idx] & masks[2]) ? 1 : 0;
    c += (substrs[idx] & masks[3]) ? 1 : 0;
    c += (substrs[idx] & masks[4]) ? 1 : 0;
    c += (substrs[idx] & masks[5]) ? 1 : 0;
    c += (substrs[idx] & masks[6]) ? 1 : 0;
    c += (substrs[idx] & masks[7]) ? 1 : 0;
    return c;
}

int main()
{
    unsigned char c;
    unsigned int key, N, num, nc, ncn, NC;
    int alphabeta[MAXC] = {-1};

    cin >> N >> NC;

    // init ncn
    ncn = 1;
    for (unsigned int i=0; i<N; ++i) 
	ncn *= NC;

    // init alphabeta
    for (int i=0; i<MAXC; ++i) {
	alphabeta[i] = -1;
    }

    // read the first substring
    key = nc = 0;
    for (unsigned int i=0; i<N; ++i) {
	cin >> c;
	if ( alphabeta[c] < 0 ) alphabeta[c] = nc++;
	key *= NC;
	key += alphabeta[c];
    }
    set(key);

    while ( cin >> c ) {
	if ( alphabeta[c] < 0 ) alphabeta[c] = nc++;
	key *= NC;
	key += alphabeta[c];
	key %= ncn;
	set(key);
    }

    num = 0;
    for (int i=0; i<MAXN; ++i) 
	num += count(i);
    cout << num << endl;
    return 0;
}

/*
 * =====================================================================================
 *
 *       Filename:  flip.cpp
 *
 *    Description:  POJ 1753. Flip Game
 *
 *        Version:  1.0
 *        Created:  06/29/2009 06:02:21 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  BUAA.edu
 *
 * =====================================================================================
 */


#include	<stdio.h>
#define 	MAXN 	65537

unsigned int masks[16] = {
    0x0001, 0x0002, 0x0004, 0x0008,
    0x0010, 0x0020, 0x0040, 0x0080,
    0x0100, 0x0200, 0x0400, 0x0800,
    0x1000, 0x2000, 0x4000, 0x8000
};
int positions[16][6] = {
    {0, 1, 4, -1, -1, -1},
    {1, 0, 2, 5, -1, -1},
    {2, 1, 3, 6, -1, -1},
    {3, 2, 7, -1, -1, -1},
    {4, 0, 5, 8, -1, -1},
    {5, 1, 4, 6, 9, -1},
    {6, 2, 5, 7, 10, -1},
    {7, 3, 6, 11, -1, -1},
    {8, 4, 9, 12, -1, -1},
    {9, 5, 8, 10, 13, -1},
    {10, 6, 9, 11, 14, -1},
    {11, 7, 10, 15, -1, -1},
    {12, 8, 13, -1, -1, -1},
    {13, 9, 12, 14, -1, -1},
    {14, 10, 13, 15, -1, -1},
    {15, 11, 14, -1, -1, -1}
};

unsigned int states[MAXN] = {0};
unsigned int lengths[MAXN] = {0};
size_t head=0, tail = 0;
bool visited[MAXN] = {false};

void enqueue(unsigned int st, unsigned int len) { 
    lengths[head] = len;
    states[head++] = st; 
}
unsigned int dequeue(unsigned int *plen) { 
    *plen = lengths[tail];
    return states[tail++]; 
}
bool empty() { return head == tail; }

unsigned int set(int val, int p, bool on) {
    if ( on ) val |= masks[p];
    else val &= ~masks[p];
    return val;
}

bool success(unsigned int board) {
    return board == 0x0000 || board == 0xFFFF;
}

unsigned int flip(unsigned int board, int i) {
    int j;
    if ( i >= 16 ) return board;
    for ( j=0; positions[i][j] >= 0; ++j ) {
	board ^= masks[positions[i][j]];
    }
    return board;
}

int search()
{
    unsigned int i, st, new_st, len;
    while ( !empty() ) {
	st = dequeue(&len);
	for (i=0; i<16; ++i) {
	    new_st = flip(st, i);
	    if ( success(new_st) ) return len+1;
	    if ( visited[new_st] ) continue;
	    enqueue(new_st, len+1);
	    visited[new_st] = true;
	}
    }

    return -1;
}

    int
main ( int argc, char *argv[] )
{
    char c;
    int i, result = -1;
    unsigned int init_state = 0;

    for (i=0; i<16; ++i) {
	while ( (c=getchar()) != 'b' && c != 'w' ) ;
	init_state = set(init_state, i, c == 'b');
    }

    if ( success(init_state) ) {
	result = 0;
    } else {
	enqueue(init_state, 0);
	result = search();
    }

    if ( result >= 0 ) 
	printf("%d\n", result);
    else
	printf("Impossible\n");

    return 0;
}	

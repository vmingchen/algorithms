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


#include	<iostream>
#include	<deque>

using namespace std;

const unsigned int masks[16] = {
    0x0001, 0x0002, 0x0004, 0x0008,
    0x0010, 0x0020, 0x0040, 0x0080,
    0x0100, 0x0200, 0x0400, 0x0800,
    0x1000, 0x2000, 0x4000, 0x8000
};
const int positions[16][6] = {
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

class State {
    public:
	unsigned int board;
	unsigned int len;
	State(unsigned int b, unsigned int l) : board(b), len(l) { };
	void flip(int i) {
	    if ( i >= 16 ) return ;
	    for ( int j=0; positions[i][j] >= 0; ++j ) {
		board ^= masks[positions[i][j]];
	    }
	};
	void set(int p, bool v) {
	    if ( v ) board |= masks[p];
	    else board &= ~masks[p];
	};
	bool equal(const State &other) const {
	    return board == other.board;
	};
	bool stable() const {
	    return board == 0x0000 || board == 0xFFFF;
	};
//	bool operator < (const State &other) const {
//	    return board < other.board;
//	};
};

deque<State> states;

bool visitied[65536] = {false};

int search()
{
    while ( !states.empty() ) {
	State st = *states.begin();
	if ( st.stable() ) return st.len;
	if ( st.len >= 16 ) return -1;
	for (int i=0; i<16; ++i) {
	    State new_st(st.board, st.len+1);
	    new_st.flip(i);
	    if ( visitied[new_st.board] ) continue;
	    states.push_back(new_st);
	}
	visitied[st.board] = true;
	states.pop_front();
    }

    return -1;
}

    int
main ( int argc, char *argv[] )
{
    char c;
    int result;

    State init_state(0, 0);
    for (int i=0; i<16; ++i) {
	while ( (cin >> c) && c != 'b' && c != 'w' ) ;
	init_state.set(i, c == 'b');
    }

    states.push_back(init_state);
    result = search();
    if ( result >= 0 ) 
	cout << result << endl;
    else
	cout << "Impossible" << endl;

    return 0;
}	

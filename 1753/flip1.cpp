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
#include	<vector>
#include	<deque>
#include	<string>

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
	State(unsigned int b) : board(b) { };
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
	void flips(string str) {
	    for (size_t i=0; i < str.length(); ++i) {
		flip(str[i]);
	    }
	}
	bool equal(const State &other) const {
	    return board == other.board;
	};
	bool stable() const {
	    return board == 0x0000 || board == 0xFFFF;
	};
};

deque<string> flip_queue;
State init_state(0);

bool process(string ops)
{
    State state = init_state;
    if ( ops.length() > 0 ) state.flips(ops);
    if ( state.stable() ) return true;
    if ( ops.length() < 16 ) {
	for ( char c=0; c<16; ++c ) {
	    string new_op = ops;
	    new_op.append(1, c);
	    flip_queue.push_back(new_op);
	}
    }
    return false;
}

int search()
{
    if ( init_state.stable() ) return 0;

    flip_queue.push_back("");
    while ( !flip_queue.empty() ) {
	string op = *flip_queue.begin();
	if ( process(op) ) return op.length();
	flip_queue.pop_front();
    }

    return -1;
}

    int
main ( int argc, char *argv[] )
{
    char c;
    int result;

    for (int i=0; i<16; ++i) {
	while ( (cin >> c) && c != 'b' && c != 'w' ) ;
	init_state.set(i, c == 'b');
    }

    result = search();
    if ( result >= 0 ) 
	cout << result << endl;
    else
	cout << "Impossible" << endl;

    return 0;
}	

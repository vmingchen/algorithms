/*
 * =====================================================================================
 *
 *       Filename:  puzzle.cpp
 *
 *    Description:  POJ 1204. Word puzzles
 *
 *        Version:  1.0
 *        Created:  07/02/2009 06:11:56 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  BUAA.edu
 *
 * =====================================================================================
 */


#include	<iostream>
#include	<string>

using namespace std;

const int MAXN = 1001;
char board[MAXN][MAXN];
string words[MAXN];
int word_pos[MAXN][3];
int L, C, W;

inline int search(int line, int col, int w)
{
    int i, l, c;
    int width = words[w].length(),
	up = line+1,
       	down = L-line,
	left = col+1,
	right = C-col;
    
    if ( up >= width ) {
	i = 1;
	l = line-1;
	c = col;
	while ( i<width && board[l--][c]==words[w][i] ) 
	    ++i;
	if ( i == width ) return 0;
    }

    if ( up >= width && right >= width ) {
	i = 1;
	l = line-1;
	c = col+1;
	while ( i<width && board[l--][c++]==words[w][i] )
	    ++i;
	if ( i == width ) return 1;
    }

    if ( right >= width ) {
	i = 1;
	l = line;
	c = col+1;
	while ( i<width && board[l][c++]==words[w][i] ) 
	    ++i;
	if ( i == width ) return 2;
    }

    if ( down >= width && right >= width ) {
	i = 1;
	l = line+1;
	c = col+1;
	while ( i<width && board[l++][c++]==words[w][i] ) 
	    ++i;
	if ( i == width ) return 3;
    }

    if ( down >= width ) {
	i = 1;
	l = line+1;
	c = col;
	while ( i<width && board[l++][c]==words[w][i] ) 
	    ++i;
	if ( i == width ) return 4;
    }

    if ( down >= width && left >= width ) {
	i = 1;
	l = line+1;
	c = col-1;
	while ( i<width && board[l++][c--]==words[w][i] ) 
	    ++i;
	if ( i == width ) return 5;
    }

    if ( left >= width ) {
	i = 1;
	l = line;
	c = col-1;
	while ( i<width && board[l][c--]==words[w][i] ) 
	    ++i;
	if ( i == width ) return 6;
    }

    if ( left >= width && up >= width ) {
	i = 1;
	l = line-1;
	c = col-1;
	while ( i<width && board[l--][c--]==words[w][i] ) 
	    ++i;
	if ( i == width ) return 7;
    }

    return -1;
}

int main()
{
    int r, num_found = 0;

    cin >> L >> C >> W;
    for (int l=0; l<L; ++l) {
	for (int c=0; c<C; ++c) {
	    cin >> board[l][c];
	}
    }
    for (int w=0; w<W; ++w) {
	cin >> words[w];
	word_pos[w][0] = -1;
    }

    for (int l=0; l<L; ++l) {
	for (int c=0; c<C; ++c) {
	    for (int w=0; w<W; ++w) {
		if ( word_pos[w][0] >= 0 ) continue;
		if ( board[l][c] != words[w][0] ) continue;
		if ( (r=search(l, c, w)) >= 0 ) {
		    word_pos[w][0] = l;
		    word_pos[w][1] = c;
		    word_pos[w][2] = r;
		    if ( ++num_found == W ) {
			for (int w=0; w<W; ++w) {
			    cout << word_pos[w][0] << " "
				<< word_pos[w][1] << " "
				<< (char)('A' + word_pos[w][2]) << endl;
			}
			return 0;
		    }
		}
	    }
	}
    }

    return 0;
}

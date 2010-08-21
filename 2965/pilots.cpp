/*
 * =====================================================================================
 *
 *       Filename:  pilots.cpp
 *
 *    Description:  POJ 2965. The Pilots Brothers' refrigerator
 *
 *        Version:  1.0
 *        Created:  04/04/2010 03:35:15 PM
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

const int MAXN = 1 << 16;
unsigned short MASKS[4][4] = {{0}};

class State {
public:
    unsigned short value,
          parent,
          posi,
          posj;
};

State states[MAXN];
int head, tail;
bool visited[MAXN] = {false};

inline unsigned short flip( unsigned short val, int r, int c )
{
    return (val & ~MASKS[r][c]) | (~val & MASKS[r][c]);
}

void init()
{
    unsigned short bit_masks[4][4] = {{0}};
    for ( int i = 0; i < 16; ++i ) {
        bit_masks[i/4][i%4] = 0x0001 << i;
    }

    for ( int r = 0; r < 4; ++r ) {
        for ( int c = 0; c < 4; ++c ) {
            MASKS[r][c] = 0;
            for ( int i = 0; i < 4; ++i ) {
                MASKS[r][c] |= bit_masks[r][i];
                MASKS[r][c] |= bit_masks[i][c];
            }
        }
    }

    head = 0;
    tail = 1;
    states[0].parent = 0;
    states[0].value = 0;
    char line[5];
    for ( int r = 0; r < 4; ++r ) {
        cin.getline( line, 5 );
        for ( int c = 0; c < 4; ++c ) {
            if ( line[c] == '-' ) {
                states[0].value |= (0x0001 << (r*4 + c));
            }
        }
    }

    visited[states[0].value] = true;
}

void write( int idx )
{
    char trace[MAXN][2] = {{0}};
    int count = 0;
    while ( idx != 0 ) {
        trace[count][0] = '1' + states[idx].posi;
        trace[count][1] = '1' + states[idx].posj;
        ++count;
        idx = states[idx].parent;
    }

    cout << count << endl;
    for ( int i = count-1; i >= 0; --i ) {
        cout << trace[i][0] << " " << trace[i][1] << endl;
    }
}

int main()
{
    init();

    unsigned short target = (unsigned short)(MAXN - 1);

    for ( int cur = head; cur < tail; ++cur ) {
        unsigned short cur_val = states[cur].value;
        int new_tail = tail;
        for ( int r = 0; r < 4; ++r ) {
            for ( int c = 0; c < 4; ++c ) {
                unsigned short new_val = flip( cur_val, r, c ); 
                if ( !visited[new_val] ) {
                    visited[new_val] = true;
                    states[new_tail].parent = cur;
                    states[new_tail].value = new_val;
                    states[new_tail].posi = r;
                    states[new_tail].posj = c;
                    if ( states[new_tail].value == target ) {
                        write( new_tail );
                        return 0;
                    } else {
                        ++new_tail;
                    }
                }
            }
        }
        ++head;
        tail = new_tail;
    }

    return 0;
}

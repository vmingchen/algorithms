/*
 * =====================================================================================
 *
 *       Filename:  edge.cpp
 *
 *    Description:  POJ 1009
 *
 *        Version:  1.0
 *        Created:  09/18/2010 03:54:14 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chenming), chenming@sohu-rd.com
 *        Company:  imeresearch@sogou
 *
 * =====================================================================================
 */

#include	<iostream>
#include	<algorithm>
#include	<stdlib.h>

using namespace std;

const int MAX_RLE = 1000;
const int MAX_VAL = 256;
const int MAX_OFFSET = 1000000000;

int rles[MAX_RLE][2], nrle = 0;
int height, width, total;
int checkpoints[9*MAX_RLE], numpoint = 0;
int neighbors[9];

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  find_neighbors
 *  Description:  
 * =====================================================================================
 */
    void
find_neighbors ( int pos )
{
    static int offsets[9][2] = {
        {-1, -1}, {0, -1}, {1, -1},
        {-1, 0}, {0, 0}, {1, 0},
        {-1, 1}, {0, 1}, {1, 1}
    };
    int yi = pos / width;
    int xi = pos % width;
    for (int i = 0; i < 9; ++i) {
        int nxi = xi + offsets[i][0];
        int nyi = yi + offsets[i][1];
        if ( nxi < 0 || nxi >= width || nyi < 0 || nyi >= height ) {
            neighbors[i] = -1;
        } else {
            neighbors[i] = nxi + nyi*width;
        }
    }
}		/* -----  end of function find_neighbors  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  add_checkpoints
 *  Description:  
 * =====================================================================================
 */
    void
add_checkpoints ( int pos )
{
    find_neighbors(pos);
    for ( int i = 0; i < 9; ++i ) { 
        if ( neighbors[i] == -1 ) continue;
        checkpoints[numpoint++] = neighbors[i];
    }
}		/* -----  end of function add_checkpoints  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  get_edge
 *  Description:  
 * =====================================================================================
 */
    int
get_edge ( int pos, int* pfrom_rle )
{
    int values[9], irle = *pfrom_rle;
    int new_from_rle = -1;                      // find a new start from pfrom_rle
    find_neighbors(pos);                        
    for ( int i = 0; i < 9; ++i ) {
        if ( neighbors[i] == -1 ) {
            values[i] = MAX_VAL;
            continue;
        }
        
        while ( rles[irle][1] <= neighbors[i] ) ++irle; // locate rle containing current neighbor
        values[i] = rles[irle][0];

        if ( new_from_rle == -1 ) {                     // set new from_rle if not set
            new_from_rle = *pfrom_rle;
            while ( neighbors[i] > (rles[new_from_rle][1] + width + 1) ) 
                ++new_from_rle; 
        }
    }
    *pfrom_rle = new_from_rle;

    int edge = 0;
    for ( int i = 0; i < 9; ++i ) {
        if ( values[i] == MAX_VAL ) continue;
        edge = max(edge, abs(values[i] - values[4]));
    }

    return edge;
}		/* -----  end of function get_edge  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
    int
main ( int argc, char *argv[] )
{ 
    while ( cin >> width && width != 0 ) {
        total = 0;
        int val, len;
        for ( nrle = 0; cin >> val >> len && (len != 0 || val != 0); ++nrle ) {
            total += len;
            rles[nrle][0] = val;
            rles[nrle][1] = total;
        }
        height = total / width;
        // add check points
        numpoint = 0;
        add_checkpoints(0);
        for ( int i = 0; i < nrle; ++i ) 
            add_checkpoints(rles[i][1]);
        sort(checkpoints, checkpoints+numpoint);
        numpoint = unique(checkpoints, checkpoints+numpoint) - checkpoints;

        cout << width << "\n";
        int edge_val, begin_pos = 0, from_rle = 0;
        edge_val = get_edge(begin_pos, &from_rle);
        for ( int i = 0; i < numpoint; ++i ) {
            int edge = get_edge(checkpoints[i], &from_rle);
            if ( edge != edge_val ) {
                cout << edge_val << " " << (checkpoints[i] - begin_pos) << "\n"; 
                edge_val = edge;
                begin_pos = checkpoints[i];
            }
        }
        if ( begin_pos < total ) {
            cout << edge_val << " " << (total - begin_pos) << "\n";
        }
        cout << "0 0\n";
    }
    cout << "0\n";

    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

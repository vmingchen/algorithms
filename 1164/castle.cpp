/*
 * =====================================================================================
 *
 *       Filename:  castle.cpp
 *
 *    Description:  POJ 1164. The Castle
 *
 *        Version:  1.0
 *        Created:  07/01/2009 10:08:28 PM
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

const int MAX = 51;

int M, N, castle[MAX][MAX], components[MAX][MAX], all_sizes[MAX*MAX];
int West = 0x01;
int North = 0x02;
int East = 0x04;
int South = 0x08;

int flood_fill(int component)
{
    int num_visited, size = 0;
    do {
	num_visited = 0;
	for (int i=1; i<=M; ++i) {
	    for (int j=1; j<=N; ++j) {
		if ( components[i][j] == -2 ) {
		    ++size;
		    ++num_visited;
		    components[i][j] = component;
		    if ( !(castle[i][j] & West) && j > 1 
			    && components[i][j-1] == -1 ) {
			components[i][j-1] = -2;
		    }
		    if ( !(castle[i][j] & North) && i > 1 
			    && components[i-1][j] == -1 ) {
			components[i-1][j] = -2;
		    }
		    if ( !(castle[i][j] & East) && j < N 
			    && components[i][j+1] == -1 ) {
			components[i][j+1] = -2;
		    }
		    if ( !(castle[i][j] & South) && i < M 
			    && components[i+1][j] == -1 ) {
			components[i+1][j] = -2;
		    }
		}
	    }
	}
    } while ( num_visited );
    return size;
}

    int
main ( int argc, char *argv[] )
{
    int second_largest, first_largest, merge_largest, size, num_component;
    int removed_row, removed_col;
    char removed_dir;
    
    if ( cin >> M >> N ) {
	for (int i=1; i<=M; ++i) {
	    for (int j=1; j<=N; ++j) {
		cin >> castle[i][j];
		components[i][j] = -1;
	    }
	}
    }

    num_component = 0;
    first_largest = second_largest = 0;
    for (int i=1; i<=M; ++i) {
	for (int j=1; j<=N; ++j) {
	    if ( components[i][j] == -1 ) {
		++num_component;
		components[i][j] = -2;
		size = flood_fill(num_component);
		all_sizes[num_component] = size;
		if ( size > first_largest ) {
		    first_largest = size;
		    second_largest = first_largest;
		}
	    }
	}
    }

    merge_largest = 0;
    for (int j=0; j<=N; ++j) {
	for (int i=M; i>=1; --i) {
	    if ( (castle[i][j] & West) && j > 1 
		    && components[i][j-1] != components[i][j] ) {
		size = all_sizes[components[i][j-1]] 
		    + all_sizes[components[i][j]];
		if ( size > merge_largest ) {
		    merge_largest = size;
		    removed_row = i;
		    removed_col = j;
		    removed_dir = 'W';
		}
	    }
	    if ( (castle[i][j] & North) && i > 1 
		    && components[i-1][j] != components[i][j] ) {
		size = all_sizes[components[i-1][j]] 
		    + all_sizes[components[i][j]];
		if ( size > merge_largest ) {
		    merge_largest = size;
		    removed_row = i;
		    removed_col = j;
		    removed_dir = 'N';
		}
	    }
	    if ( (castle[i][j] & East) && j < N 
		    && components[i][j+1] != components[i][j] ) {
		size = all_sizes[components[i][j+1]] 
		    + all_sizes[components[i][j]];
		if ( size > merge_largest ) {
		    merge_largest = size;
		    removed_row = i;
		    removed_col = j;
		    removed_dir = 'E';
		}
	    }
	    if ( (castle[i][j] & South) && i < M 
		    && components[i+1][j] != components[i][j] ) {
		size = all_sizes[components[i+1][j]] 
		    + all_sizes[components[i][j]];
		if ( size > merge_largest ) {
		    merge_largest = size;
		    removed_row = i;
		    removed_col = j;
		    removed_dir = 'S';
		}
	    }
	}
    }

    cout << num_component << endl;
    cout << first_largest << endl;

    return 0;
}	

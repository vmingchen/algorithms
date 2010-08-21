/*
 * =====================================================================================
 *
 *       Filename:  frames.cpp
 *
 *    Description:  Frame Stacking. POJ 1128
 *
 *        Version:  1.0
 *        Created:  2009-12-13 7:51:48 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  BUAA.edu
 *
 * =====================================================================================
 */


#include	<iostream>
#include	<cstring>

using namespace std;

const int MAXL = 31;

char board[MAXL][MAXL];
int w, h, n, positions[MAXL][4];
int graph[MAXL][MAXL] = {{0}};
int seq[MAXL] = {0}, depth = 0;
bool visited[MAXL] = {false};

void search(int depth)
{
  if ( depth == n ) {
    for (int t = 0; t < n; t++) 
      cout << (char)('A' + seq[t]);
    cout << endl;
  }
  for ( int k = 0; k < n; k++ ) {
    if ( visited[k] ) continue;
    int j = 0;
    while ( j < depth && graph[k][seq[j]] != 1 ) j++;
    if ( j != depth ) continue;
    visited[k] = true;
    seq[depth] = k;
    search(depth+1);
    visited[k] = false;
  }
}

int main()
{
  while ( cin >> h >> w ) {
    for (int i = 0; i < MAXL; i++) {
      positions[i][0] = w;
      positions[i][1] = h;
      positions[i][2] = -1;
      positions[i][3] = -1;
    }

    n = 0;
    for (int i = 0; i < h; i++) {
      cin >> board[i];
      for (int j = 0; j < w; j++) {
	if ( board[i][j] != '.' ) {
	  int idx = board[i][j] - 'A';
	  if ( j < positions[idx][0] ) positions[idx][0] = j;
	  if ( j > positions[idx][2] ) positions[idx][2] = j;
	  if ( i < positions[idx][1] ) positions[idx][1] = i;
	  if ( i > positions[idx][3] ) positions[idx][3] = i;
	  if ( idx >= n ) n = idx + 1;
	}
      }
    }

    memset( graph, 0, sizeof(int)*MAXL*MAXL );
    for (int k = 0; k < n; k++) {
      for (int j = positions[k][0]; j <= positions[k][2]; j++) {
	graph[k][board[positions[k][1]][j] - 'A'] = 1;
	graph[k][board[positions[k][3]][j] - 'A'] = 1;
      }

      for (int i = positions[k][1]; i <= positions[k][3]; i++) {
	graph[k][board[i][positions[k][0]] - 'A'] = 1;
	graph[k][board[i][positions[k][2]] - 'A'] = 1;
      }
    }

    for (int k = 0; k < n; k++) 
      for (int i = 0; i < n; i++) 
	for (int j = 0; j < n; j++) 
	  if ( graph[i][k] == 1 && graph[k][j] == 1 ) 
	    graph[i][j] = 1;

    search( 0 );
  }

  return 0;
}

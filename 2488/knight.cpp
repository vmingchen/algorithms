/*
 * =====================================================================================
 *
 *       Filename:  knight.cpp
 *
 *    Description:  POJ 2488. A Knight's Journey
 *
 *        Version:  1.0
 *        Created:  2009-12-14 6:16:39 PM
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

const int MAXS = 64, VISITED = 64*64;
const int moves[8][2] = {{-1, -2}, {1, -2}, {-2, -1}, {2, -1}, {-2, 1}, {2, 1}, {-1, 2}, {1, 2}};

int p, q, sz, states[MAXS][MAXS];

void print_path(int n) 
{
  int trace[MAXS*MAXS][2];
  for (int i = 0; i <= p; i++) {
    for (int j = 0; j <= q; j++) {
      trace[states[i][j]][0] = i;
      trace[states[i][j]][1] = j;
    }
  }
  cout << "Scenario #" << n << ":" << endl;
  for (int i = 1; i <= sz; i++) {
    cout << (char)(trace[i][1] + 'A') << (char)(trace[i][0] + '1');
  }
  cout << endl;
}

bool search(int i, int j)
{
  int idx = states[i][j];
  if ( idx == sz ) return true;

  for (int k = 0; k < 8; k++) {
    int ni = i + moves[k][0];
    int nj = j + moves[k][1];
    if ( ni < 0 || ni >= p || nj < 0 || nj >= q || states[ni][nj] != 0 ) 
      continue;
    states[ni][nj] = idx + 1;
    if ( search(ni, nj) ) return true;
    states[ni][nj] = 0;
  }

  return false;
}

int main()
{
  int numCases;
  
  cin >> numCases;
  for ( int n = 1; n <= numCases; n++ ) {
    cin >> p >> q;
    memset( states, 0, sizeof(int)*MAXS*MAXS );
    sz = p*q;
    states[0][0] = 1;
    if ( search(0, 0) ) {
      print_path(n);
    } else {
      cout << "Scenario #" << n << ":" << endl << "impossible" << endl;
    }
    cout << endl;
  }
  return 0;
}

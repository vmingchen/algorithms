/*
 * =====================================================================================
 *
 *       Filename:  grapevine.cpp
 *
 *    Description:  Stockbroker Grapevine POJ 1125
 *
 *        Version:  1.0
 *        Created:  2009-12-27 3:15:27 PM
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

const int MAXL = 100000;
const int MAXN = 101;

int main()
{
  int num;
  int neighbors[MAXN][MAXN];
  while ( cin >> num && num != 0 ) {
    for (int i = 1; i <= num; i++)
      for (int j = 1; j <= num; j++)
	neighbors[i][j] = MAXL;

    for (int i = 1; i <= num; i++) neighbors[i][i] = 0; 

    for (int i = 1; i <= num; i++) {
      int c, d, t;
      cin >> c;
      for (int j = 0; j < c; j++) {
	cin >> d >> t;
	neighbors[i][d] = t;
      }
    }
    for (int k = 1; k <= num; k++) {
      for (int i = 1; i <= num; i++) {
	for (int j = 1; j <= num; j++) {
	  if ( neighbors[i][k] + neighbors[k][j] < neighbors[i][j] ) {
	    neighbors[i][j] = neighbors[i][k] + neighbors[k][j];
	  }
	}
      }
    }

    int minn, mind = MAXL;
    bool disjoint = true;
    for (int i = 1; i <= num; i++) {
      bool failure = false;
      int maxd = 0;
      for (int j = 1; j <= num && !failure; j++) {
	if ( neighbors[i][j] == MAXL ){ failure = true; break; }
	if ( neighbors[i][j] > maxd ) maxd = neighbors[i][j];
      }
      if ( !failure && maxd < mind ) { minn = i; mind = maxd; disjoint = false;}
    }

    if ( disjoint ) cout << "disjoint" << endl;
    else { cout << minn << " " << mind << endl; }
  }
}

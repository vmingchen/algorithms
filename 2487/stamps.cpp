/*
 * =====================================================================================
 *
 *       Filename:  stamps.cpp
 *
 *    Description:  POJ 2487. Stamps
 *
 *        Version:  1.0
 *        Created:  2009-12-14 7:38:27 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  BUAA.edu
 *
 * =====================================================================================
 */


#include	<iostream>
#include	<algorithm>

using namespace std;

const int MAXF = 1000;

int main()
{
  int friends[MAXF], numCase;
  cin >> numCase;
  for (int i = 1; i <= numCase; i++) {
    int need, numFri;
    cin >> need >> numFri;
    for (int j = 0; j < numFri; j++)
      cin >> friends[j];
    sort( friends, friends + numFri );
    int sum = 0, k = numFri-1;
    while ( k >= 0 && need > sum ) {
      sum += friends[k];
      k--;
    }
    if ( need > sum ) {
      cout << "Scenario #" << i << ":" << endl;
      cout << "impossible" << endl << endl;
    } else {
      cout << "Scenario #" << i << ":" << endl;
      cout << numFri - k - 1 << endl << endl;
    }
  }
  return 0;
}

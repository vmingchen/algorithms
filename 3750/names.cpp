/*
 * =====================================================================================
 *
 *       Filename:  names.cpp
 *
 *    Description:  POJ 3750
 *
 *        Version:  1.0
 *        Created:  2010-1-4 4:31:20 PM
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

const int MAXN = 64, MAXL = 16;

int main()
{
  char names[MAXN][MAXL], dull;
  int N, W, S, next[MAXN] = {0};
  cin >> N;

  cin.getline( names[0], MAXL ); // strip newline
  for (int i = 0; i < N; i++) {
    cin.getline( names[i], MAXL );
    next[i] = 1;
  }
  next[N-1] = 1 - N;

  cin >> W >> dull >> S;
  int cur = W - 1;
  int prev = cur == 0 ? N-1 : cur-1;
  while ( next[cur] != 0 ) {
    for (int s = 1; s < S; s++) {
      prev = cur;
      cur += next[cur];
    }
    cout << names[cur] << endl;
    next[prev] += next[cur];
    cur += next[cur];
  }
  cout << names[cur] << endl;

  return 0;
}

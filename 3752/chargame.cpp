/*
 * =====================================================================================
 *
 *       Filename:  chargame.cpp
 *
 *    Description:  POJ 3752
 *
 *        Version:  1.0
 *        Created:  2010-1-4 9:02:07 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  BUAA.edu
 *
 * =====================================================================================
 */


#include	<cstdio>

const int MAXN = 100000;
int numPrev[MAXN] = {0}, Wi[MAXN], Hi[MAXN];
int H, W, N;

inline int index(int x, int y)
{
  int sa = y, 
      sb = W - 1 - x,
      sc = H - 1 - y,
      sd = x;
  if ( sa <= sb && sa <= sc && sa <= sd ) {
    int i = sa;
    return numPrev[i] + x - i;
  } else if ( sb <= sa && sb <= sc && sb <= sd ) {
    int i = sb;
    return numPrev[i] + Wi[i] - 1 + y - i;
  } else if ( sc <= sa && sc <= sb && sc <= sd ) {
    int i = sc;
    return numPrev[i] + Wi[i] - 1 + Hi[i] - 1 + W - 1 - i - x;
  } else {
    int i = sd;
    return numPrev[i] + Wi[i] - 1 + Hi[i] - 1 + Wi[i] - 1 + H - 1 - i - y;
  }
}

int main()
{
  scanf("%d %d", &H, &W);
  int N = H > W ? W : H;
  N = (N + 1)/2;
  numPrev[0] = 2*W + 2*H - 4;
  for (int i = 1; i < N; i++)
    numPrev[i] = numPrev[i-1] - 8;
  for (int i = 1; i < N; i++) 
    numPrev[i] += numPrev[i-1];
  for (int i = N-1; i > 0; i--)
    numPrev[i] = numPrev[i-1];
  numPrev[0] = 0;
  for (int i = 0; i < N; i++) {
    Wi[i] = W - i - i;
    Hi[i] = H - i - i;
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      printf("   %c", 'A' + (index(j, i) % 26));
    }
    printf("\n");
  }
  
  return 0;
}

/*
 * =====================================================================================
 *
 *       Filename:  bitop.cpp
 *
 *    Description:  POJ 3748
 *
 *        Version:  1.0
 *        Created:  2010-1-4 2:23:10 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  BUAA.edu
 *
 * =====================================================================================
 */


#include	<cstdio>

void setbit(int *p, int i)
{
  *p = *p | (0x01 << i);
}

void resetbit(int *p, int i)
{
  *p = *p & ~(0x01 << i);
}

int main()
{
  int operand, x, y;

  scanf("%x,%d,%d", &operand, &x, &y);
  
  resetbit( &operand, x );
  setbit( &operand, y );
  setbit( &operand, y - 1);
  resetbit( &operand, y - 2);

  printf("%x\n", operand);

  return 0;
}

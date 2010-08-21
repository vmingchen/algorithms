/*
 * =====================================================================================
 *
 *       Filename:  date.cpp
 *
 *    Description:  POJ 3751
 *
 *        Version:  1.0
 *        Created:  2010-1-4 5:37:42 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  BUAA.edu
 *
 * =====================================================================================
 */


#include	<cstdio>

int main()
{
  int N, year, month, day, hour, min, sec;
  scanf("%d\n", &N);
  while ( N-- > 0 ) {
    scanf("%d/%d/%d-%d:%d:%d", &year, &month, &day, &hour, &min, &sec);
    printf("%.2d/%.2d/%.4d-%.2d:%.2d:%.2d%cm\n", 
	month,
	day,
	year,
	(hour == 0 || hour == 12 || hour == 24) ? 12 : (hour % 12),
	min,
	sec,
	hour >= 12 ? 'p' : 'a'
      );
  }
  return 0;
}

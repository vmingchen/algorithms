/*
 * =====================================================================================
 *
 *       Filename:  phone2.c
 *
 *    Description:  POJ Problem 1002
 *
 *        Version:  1.0
 *        Created:  04/22/2009 02:39:49 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  BUAA.edu
 *
 * =====================================================================================
 */


#include	<stdio.h>

#define MAX_LEN 500
#define MAX_ADD 10000000


int keypad[26] = {2, 2, 2, 
  3, 3, 3,
  4, 4, 4,
  5, 5, 5,
  6, 6, 6,
  7, 0, 7, 7,
  8, 8, 8,
  9, 9, 9, 0};	// '0' for Q and Z

int add_book[MAX_ADD] = {0};

  int
main ( int argc, char *argv[] )
{
  char record[MAX_LEN];
  int i, j, n, add, hasduplicate;

  scanf("%d", &n);
  for ( i=0; i<n; ++i ) {
    scanf("%s", record);
    add = 0;
    for ( j=0; record[j]!='\0'; ++j ) {
      if ( record[j] == '-' ) continue;
      add *= 10;
      if ( record[j] >= 'A' && record[j] <= 'Z' ) {
	add += keypad[record[j]-'A'];
      } else {
	add += record[j]-'0';
      }
    }
    add_book[add] += 1;
  }

  hasduplicate = 0;
  for ( i=0; i<MAX_ADD; ++i ) {
    if ( add_book[i] > 1 ) {
      hasduplicate = 1;
      printf("%03d-%04d %d\n", i/10000, i%10000, add_book[i]);
    }
  }

  if ( !hasduplicate ) {
    printf("No duplicates.\n");
  }

  return 0;
}				/* ----------  end of function main  ---------- */

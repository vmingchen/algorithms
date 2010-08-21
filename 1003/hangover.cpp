/*
 * =====================================================================================
 *
 *       Filename:  hangover.cpp
 *
 *    Description:  POJ Problem 1003
 *
 *        Version:  1.0
 *        Created:  04/22/2009 06:42:52 PM
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

const int MAXN = 300;
const double MAX = 5.20;
const double MIN = 0.01;

  int
main ( int argc, char *argv[] )
{
  double steps[MAXN];
  double threshold, sum = 0.0;
  int n; 

  for ( int i=1; sum <= MAX; ++i ) {
    sum += 1.0/(i+1);
    steps[i] = sum;
  }

  while ( cin >> threshold ) {
    if ( threshold <= 0.0 ) break;
    for ( n=1; steps[n] < threshold; ++n ) ;
    cout << n << " card(s)" << endl;
  }

  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

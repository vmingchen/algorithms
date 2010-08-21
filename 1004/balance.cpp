/*
 * =====================================================================================
 *
 *       Filename:  balance.cpp
 *
 *    Description:  POJ Problem 1004
 *
 *        Version:  1.0
 *        Created:  04/22/2009 06:59:05 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  BUAA.edu
 *
 * =====================================================================================
 */


#include	<iostream>
#include	<iomanip>

using namespace std;

  int
main ( int argc, char *argv[] )
{
  double balance, sum;
  sum = 0.0;
  while ( cin >> balance ) {
    sum += balance;
  }
  cout << fixed << setprecision(2);
  cout << "$" << sum/12 << endl;
  
  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

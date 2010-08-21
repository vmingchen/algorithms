/*
 * =====================================================================================
 *
 *       Filename:  arthur.cpp
 *
 *    Description:  POJ problem 2386
 *
 *        Version:  1.0
 *        Created:  04/01/2009 02:59:17 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  BUAA.edu
 *
 *        Let $D_k$ be the expected number of days to flip $k$ heads, $M_k$ be the 
 *        expected amount of money. Then we have
 *        \[ D_k = p(1 + D_{k-1}) + (1-p)(1 + D_k) \]
 *        \[ M_k = p(1 + M_{k-1} + 2D_{k-1}) + (1-p)(1 + M_k + 2D_k) \]
 *        and $D_1 = 1/p$, $M_1 = 2/p^2 - 1/p$, so
 *        \[ D_k = k/p \]
 *        \[ M_k = (k^2 + k)/p^2 - k/p \]
 *
 *
 * =====================================================================================
 */


#include	<iostream>

using namespace std;


  int
main ( int argc, char *argv[] )
{
  int k;
  double p, dk, mk;

  cout.precision(3);
  cout.setf(ios::fixed,ios::floatfield); 
  while ( cin >> k ) {
    if ( k==0 ) return 0;
    cin >> p;
    dk = k/p;
    mk = (k*k+k)/p/p - dk;
    cout << dk << " " << mk << endl;
  }

  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

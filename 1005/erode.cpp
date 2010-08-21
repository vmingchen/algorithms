/*
 * =====================================================================================
 *
 *       Filename:  erode.cpp
 *
 *    Description:  POJ 1005
 *
 *        Version:  1.0
 *        Created:  04/22/2009 07:17:28 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  BUAA.edu
 *
 * =====================================================================================
 */


#include	<iostream>
#include 	<cmath> 

using namespace std;

const double PI = 4.0*atan(1.0);


  int
main ( int argc, char *argv[] )
{
  int n;
  double x, y, k;

  cin >> n;
  for ( int i=1; i<=n; ++i ) {
    cin >> x >> y;
    k = (x*x + y*y)*PI/100;
    cout << "Property " << i << ": This property will begin eroding in year " << (int)k + 1 << "." << endl;
  }
  cout << "END OF OUTPUT." << endl;
  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

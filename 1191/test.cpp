/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/22/2009 03:18:16 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  BUAA.edu
 *
 * =====================================================================================
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main () {
  double f =3.14159;
  cout << setprecision (5) << f << endl;
  cout << setprecision (9) << f << endl;
  cout << fixed;
  cout << setprecision (4) << f << endl;
  cout << setprecision (9) << f << endl;
  return 0;
}

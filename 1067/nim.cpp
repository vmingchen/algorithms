/*
 * =====================================================================================
 *
 *       Filename:  nim.cpp
 *
 *    Description:  Nim. POJ 1067
 *    http://hi.baidu.com/autogerk/blog/item/ba10dc08d0db5fc63ac7637b.html
 *
 *        Version:  1.0
 *        Created:  2009-12-12 10:28:45 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  BUAA.edu
 *
 * =====================================================================================
 */


#include	<iostream>
#include	<cmath>

using namespace std;

int main()
{
  double db = (1.0 + sqrt(5.0)) / 2.0;
  int a, b;
  while ( cin >> a >> b ) {
    if ( a > b ) {
      int t = a;
      a = b;
      b = t;
    }
    int k = b - a;
    int ak = (int)floor( db * k );
    cout << ((ak == a) ? 0 : 1 ) << endl;
  }
  return 0;
}

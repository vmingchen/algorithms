/*
 * =====================================================================================
 *
 *       Filename:  octal.cpp
 *
 *    Description:  Octal Fraction Poj 1131
 *
 *        Version:  1.0
 *        Created:  2009-12-26 8:39:56 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  BUAA.edu
 *
 * =====================================================================================
 */


#include	<iostream>
#include	<string>

using namespace std;

const int MAXL = 10000;
int MUL125[3] = {5, 2, 1};

int main()
{
  string str;
  while ( cin >> str ) {
    int res[MAXL] = {0}, rlen = 0;
    for (int i = str.length()-1; i >= 2; i--) {
      res[rlen++] = str[i] - '0';
      int buf[MAXL] = {0};
      int sum = 0;
      for (int k = 0; k < 3; k++) {
	int mul = 0;
	for (int j = 0; j < rlen; j++) {
	  mul += res[j]*MUL125[k];
	  sum += (mul % 10) + buf[k+j];
	  buf[k+j] = sum % 10;
	  mul /= 10;
	  sum /= 10;
	}

	do {
	  sum += mul + buf[k+rlen];
	  buf[k+rlen] = sum % 10;
	  mul /= 10;
	  sum /= 10;
	} while (sum > 0);
      }
      rlen += 2;

      for (int j = 0; j < rlen; j++) res[j] = buf[j];
    }

    cout << str << " [8] = 0.";
    int i = 0; 
    while ( res[i] == 0 ) ++i;
    for (int j = rlen-1; j >= i; j--) cout << res[j];
    cout << " [10]" << endl;
  }
  return 0;
}

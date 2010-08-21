/*
 * =====================================================================================
 *
 *       Filename:  decipher.cpp
 *
 *    Description:  POJ 3749
 *
 *        Version:  1.0
 *        Created:  2010-1-4 4:18:54 PM
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

const int MAXN = 201;
const char table[27] = "VWXYZABCDEFGHIJKLMNOPQRSTU";

int main()
{
  char line[MAXN] = {0};

  while ( cin.getline( line, MAXN ) ) {
    if ( line[0] == 'E' ) break;
    cin.getline( line, MAXN );
    for (int i = 0; line[i] != '\0'; i++) {
      if ( line[i] >= 'A' && line[i] <= 'Z' ) 
	line[i] = table[line[i]-'A'];
    }
    cout << line << endl;
    cin.getline( line, MAXN ); // strip END
  }

  return 0;
}

/*
 * =====================================================================================
 *
 *       Filename:  phone.cpp
 *
 *    Description:  POJ Problem 1002
 *
 *        Version:  1.0
 *        Created:  04/22/2009 09:27:34 AM
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
#include	<map>

using namespace std;

const char keypad[26] = {'2', '2', '2', 
  '3', '3', '3',
  '4', '4', '4',
  '5', '5', '5',
  '6', '6', '6',
  '7', '0', '7', '7',
  '8', '8', '8',
  '9', '9', '9', '0'};	// '0' for Q and Z

inline  string
standardise ( string no )
{
  string sno(7, '0');
  for ( unsigned int i=0,j=0; i<no.length(); ++i ) {
    if ( no[i] == '-' ) continue;
    if ( no[i] >= 'A' && no[i] <= 'Z' ) 
      sno[j++] = keypad[no[i]-'A'];
    else
      sno[j++] = no[i];
  }
  return sno;
}		/* -----  end of function standardise  ----- */

  int
main ( int argc, char *argv[] )
{
  int n;
  map<string, int> adds;
  map<string, int>::iterator it;

  cin >> n;
  
  for ( int i=0; i<n; ++i ) {
    string no;
    cin >> no;
    no = standardise(no);
    adds[no] += 1;
  }

  bool flag = false;
  for ( it=adds.begin(); it!=adds.end(); ++it ) {
    if ( it->second > 1 ) {
      cout << it->first.substr(0,3) << "-" << it->first.substr(3);
      cout << " " << it->second << endl;
      flag = true;
    }
  }
  
  if ( !flag ) cout << "No duplicates." << endl;

  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

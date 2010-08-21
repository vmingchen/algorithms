/*
 * =====================================================================================
 *
 *       Filename:  lamp.cpp
 *
 *    Description:  POJ Problem 1176. Brutal Search!
 *
 *        Version:  1.0
 *        Created:  04/19/2009 06:22:14 PM
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
#include	<vector>
#include	<algorithm>

using namespace std;

const unsigned int NUM_STATES = 16;	// 2^4 = 16
const unsigned int NUM_SWITCHES = 4;
const unsigned int SWITCHES[NUM_SWITCHES] = {0x0001, 0x0002, 0x0004, 0x0008};

unsigned int least_presses(int state) 
{
  unsigned int p = 0;
  for ( unsigned int sw=0; sw<NUM_SWITCHES; ++sw ) 
    if ( state & SWITCHES[sw] ) ++p;
  return p;
}

  int
main ( int argc, char *argv[] )
{
  unsigned int N, C;
  unsigned int st, l;
  int i, os=0;
  vector<unsigned int> lamps_on, lamps_off;
  vector<unsigned int>::iterator it;
  string configs[NUM_STATES], config, outputs[NUM_STATES];

  cin >> N >> C;
  while ( cin >> i ) {
    if ( i != -1 )
      lamps_on.push_back(i);
    else
      break;
  }
  while ( cin >> i ) {
    if ( i != -1 )
      lamps_off.push_back(i);
    else
      break;
  }

  string init(N, '1');
//  cout << init << endl;
  for ( st=0; st<NUM_STATES; ++st ) {
    configs[st] = init;
    if ( st & SWITCHES[0] ) 
	for ( l=0; l<N; ++l ) configs[st][l] = configs[st][l]=='0' ? '1' : '0';
    if ( st & SWITCHES[1] ) 
	for ( l=0; l<N; l+=2 ) configs[st][l] = configs[st][l]=='0' ? '1' : '0';
    if ( st & SWITCHES[2] ) 
	for ( l=1; l<N; l+=2 ) configs[st][l] = configs[st][l]=='0' ? '1' : '0';
    if ( st & SWITCHES[3] )
	for ( l=0; l<N; l+=3 ) configs[st][l] = configs[st][l]=='0' ? '1' : '0';
  }

  for ( st=0; st<NUM_STATES; ++st ) {
    config = configs[st];
    for ( it=lamps_on.begin(); it!=lamps_on.end(); ++it ) {
      if ( config[*it-1] == '0' ) break;
    }
    if ( it!=lamps_on.end() ) continue;

    for ( it=lamps_off.begin(); it!=lamps_off.end(); ++it ) {
      if ( config[*it-1] == '1' ) break;
    }
    if ( it!=lamps_off.end() ) continue;

    unsigned int p = least_presses(st);
    if ( C>=p && (C-p)%2==0 ) outputs[os++] = config;
  }

  sort(outputs, outputs+os);
  for ( i=0; i<os; ++i ) 
    cout << outputs[i] << endl;

  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

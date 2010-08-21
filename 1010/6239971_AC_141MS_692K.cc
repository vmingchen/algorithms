#include	<iostream>
#include	<cstring>
#include	<algorithm>

using namespace std;

const int MAXS = 65;
int stamps[MAXS], snum;
int visited_num[MAXS];
int rnum, rhs, rcount, results[5], trace[5];
bool btie, succeed;

void search( int val, int from, int pnum, int pcount ) 
{
  if ( pnum > 4 ) return ;
  if ( val == 0 ) {
    if ( pcount < rcount || (pcount == rcount && pnum > rnum) ) 
      return ;
    int hs = stamps[trace[pnum-1]];
//    int j = 0;
//    for ( j = from; visited_num[j] != 1 && j >= 0; j-- )
//      ;
//    int hs = (j >= 0 ? stamps[j] : 0);
    bool update = true;
    if ( pcount == rcount && pnum == rnum ) {
      if ( hs == rhs ) { btie = true; update = false; }
      else if ( hs > rhs ) update = true;
      else update = false;
    } 
    if ( update ) {
      rcount = pcount;
      rnum = pnum;
      rhs = hs;
      for (int i = 0; i < rnum; i++) 
	results[i] = trace[i];
      btie = false;
      succeed = true;
    }
    return ;
  }
  for ( int i = from; i < snum; ++i ) {
    if ( val < stamps[i] ) return ;
    trace[pnum] = i;
    visited_num[i]++;
    int new_count = (visited_num[i] == 1 ? 1 : 0 );
    search( val - stamps[i], i, pnum + 1, pcount + new_count );
    visited_num[i]--;
  }
}

int main()
{
  int d, mx, mn;
  while ( cin >> d && d != 0 ) {
    snum = 0;
    mx = mn = stamps[snum++] = d; 
    while ( cin >> d && d != 0 ) {
      stamps[snum++] = d;
      if ( d > mx ) mx = d;
      if ( d < mn ) mn = d;
    }
    sort( stamps, stamps + snum );
    while ( cin >> d && d != 0 ) {
      if ( d < mn || d > mx*4 ) {
	cout << d << " ---- none" << endl;
	continue;
      }
      memset( visited_num, 0, sizeof(visited_num) );
      btie = succeed = false;
      rcount = rhs = rnum = 0;
      search( d, 0, 0, 0 );
      if ( btie ) {
	cout << d << " (" << rcount << "): tie" << endl;
	continue;
      }
      if ( !succeed ) {
	cout << d << " ---- none" << endl;
	continue;
      }
      cout << d << " (" << rcount << "): " << stamps[results[0]];
      for ( int i = 1; i < rnum; i++ )
	cout << " " << stamps[results[i]];
      cout << endl;
    }
  }
  return 0;
}

/*
 * =====================================================================================
 *
 *       Filename:  exp.cpp
 *
 *    Description:  POJ 1001
 *
 *        Version:  1.0
 *        Created:  04/19/2009 08:09:18 PM
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
#include	<algorithm>

using namespace std;

string mul(string a, string b) 
{
  int lena = a.length(), lenb = b.length();
  int t, p, ai, bi;
  string ans(lena+lenb, 0);
  for ( bi=0; bi<lenb; ++bi ) {
    t = p = 0;
    for  ( ai=0; ai<lena; ++ai ) {
       t = ans[ai+bi] + b[bi]*a[ai] + p;
       ans[ai+bi] = t%10;
       p = t/10;
    }
    while ( p>0 ) {
      t = ans[ai+bi] + p;
      ans[ai+bi] = t%10;
      p = t/10;
      ++ai;
    }
  }
  if ( ans[lena+lenb-1] == 0 ) {
    return ans.substr(0,lena+lenb-1);
  } else {
    return ans;
  }
}

string& char2int(string& a)
{
  for (unsigned int i=0; i<a.length(); ++i) 
    a[i] -= '0';
  return a;
}

string& int2char(string& a)
{
  for (unsigned int i=0; i<a.length(); ++i) 
    a[i] += '0';
  return a;
}

  int
main ( int argc, char *argv[] )
{
  string t, r, ans;
  int n;

  while ( cin >> r >> n ) {
    if ( n== 0 ) {
      cout << "1" << endl;
      continue;
    }
    // seek heading extra '0' 
    unsigned int beg, end;
    for ( beg=0; beg<r.length() && (r[beg]=='0' || r[beg]=='.'); ++beg ) ;

    // find dot
    bool hasdot = false;
    unsigned int doti = 0;
    for ( unsigned int i=0; i < r.length(); ++i ) {
      if ( r[i] == '.' ) {
	hasdot = true;
	doti = i;
	break;
      }
    }

    // seek tailing extra '0'
    if ( hasdot ) {
      for ( end=r.length()-1; end>doti && r[end]=='0'; --end ) ;
    }

    // trim extra '0' in both sides, and remove dot
    if ( hasdot && doti > beg )
      t = r.substr(beg, doti-beg) + r.substr(doti+1, end-doti);
    else
      t = r.substr(beg, end-beg+1);

    // format data
    reverse(t.begin(), t.end());

    char2int(t);
    ans = t;
    for ( int i=1; i < n; ++i ) {
      ans = mul(ans, t);
    }
    int2char(ans);

    // add dot if it exists
    if ( hasdot ) {
      doti = (end-doti)*n;
      if ( doti > ans.length() ) {
	string newans(doti+1, '0');
	for ( unsigned int i=0; i<ans.length(); ++i ) {
	  newans[i] = ans[i];
	}
	newans[doti] = '.';
	ans = newans;
      } else {
	string newans = ans.substr(0, doti) + "." + ans.substr(doti);
	ans = newans;
      }
    }

    // output
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
  }


  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

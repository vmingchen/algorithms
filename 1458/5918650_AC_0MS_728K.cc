#include	<iostream>
#include	<string>

const int MAXL = 10000;

using namespace std;

int main()
{
    string a, b;
    while ( cin >> a >> b ) {
	int lcs[2][MAXL] = {{0}}, pre = 0, cur = 1,
	    la = a.length(), lb = b.length();
	for ( int i = 0; i < la; ++i ) {
	    for ( int j = 0; j < lb; ++j ) {
		int len = max(lcs[pre][j+1], lcs[cur][j] );
		if ( a[i] == b[j] ) len = max( len, lcs[pre][j] + 1 );
		lcs[cur][j+1] = len;
	    }
	    pre = (pre+1) % 2;
	    cur = (cur+1) % 2;
	}
	int mlen = 0;
	for ( int i = 1; i <= lb; ++i ) 
	    if ( lcs[pre][i] > mlen ) 
		mlen = lcs[pre][i];
	cout << mlen << endl;
    }

    return 0;
}

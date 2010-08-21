#include	<iostream>

using namespace std;

int main()
{
	int res[24][29][34];
	for ( int i = 23*28*33; i > 0; i-- ) {
		int a = i % 23;
		int b = i % 28;
		int c = i % 33;
		res[a][b][c] = i;
	}

	int p, e, i, d;
	for ( int j = 1; cin >> p >> e >> i >> d && p >= 0; j++ ) {
		p = p % 23;
		e = e % 28;
		i = i % 33;
		cout << "Case " << j << ": the next triple peak occurs in " << res[p][e][i] - d << " days." << endl;
	}
	return 0;
}

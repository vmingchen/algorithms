#include	<iostream>

using namespace std;

const int CIRCLE = 23*28*33;

int main()
{
	int res[24][29][34];
	for ( int i = CIRCLE; i > 0; i-- ) {
		int a = i % 23;
		int b = i % 28;
		int c = i % 33;
		res[a][b][c] = i;
	}

	int p, e, i, d, r;
	for ( int j = 1; cin >> p >> e >> i >> d && p >= 0; j++ ) {
		p = p % 23;
		e = e % 28;
		i = i % 33;
		d = d % CIRCLE;
		r = res[p][e][i] - d;
		if ( r < 0 ) r += CIRCLE;
		cout << "Case " << j << ": the next triple peak occurs in " << r << " days." << endl;
	}
	return 0;
}

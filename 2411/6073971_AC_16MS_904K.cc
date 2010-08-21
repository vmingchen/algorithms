#include	<iostream>
#include	<vector>

using namespace std;

const int MAXN = 12;

long long count(int h, int w)
{
    int nos = 1<<w;
    vector< vector<long long> > ways(w+1, vector<long long>(nos, 0));
    ways[0][0] = 1;
    for (int row = 0; row < h; row++) {
	for (int col = 0; col < w; col++) {
	    int cur = 1 << col;
	    int nxt = cur << 1;
	    for (int s = 0; s < nos; s++) {
		if ( ways[col][s] == 0 ) continue;	// no effect
		if ( cur & s ) {			// already occupied
		    ways[col+1][s^cur] += ways[col][s];
		    continue;
		}
		if ( row+1 < h ) {			// vertical domino
		    ways[col+1][(s|cur)] += ways[col][s];
		}
		if ( col+1 < w && (s & nxt)==0 ) {	// horizontal domino
		    ways[col+2][s] += ways[col][s];
		}
	    }
	}
	for (int s = 0; s < nos; s++) 
	    ways[0][s] = ways[w][s];
	for (int col = 1; col <= w; col++) 
	    for (int s = 0; s < nos; s++) 
		ways[col][s] = 0;
    }
    return ways[0][0];
}

int main()
{
    int h, w;

    while ( cin >> h >> w && h != 0 ) {
	if ( (h & 0x01) && (w & 0x01) ) 
	    cout << 0 << endl;
	else
	    cout << count(h, w) << endl;
    }

    return 0;
}

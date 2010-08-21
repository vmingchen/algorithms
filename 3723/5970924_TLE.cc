#include	<iostream>
#include	<algorithm>

using namespace std;

const int MAXR = 50001,
      MAXN = 10001,
      MAXM = 10001;

class Relation {
public:
    int x, y, d;
};

bool operator<(const Relation &ra, const Relation &rb)
{
    return ra.d > rb.d;
}

int T, N, M, R;
Relation relations[MAXR];
int root[MAXN+MAXM], cost[MAXN+MAXM];
bool mask[MAXN+MAXM];

int find_set( int i )
{
    if ( root[i] == i ) return i;
    int r = i;
    while ( root[r] != r ) r = root[r];
    while ( root[i] != r ) {
	int t = root[i];
	root[i] = r;
	i = t;
    }
    return r;
}

void union_set( int x, int y, int d )
{
    root[x] = y;
    cost[y] += (cost[x] - d);
}

int main()
{
    cin >> T;
    for (int t = 1; t <= T; ++t) {
	cin >> N >> M >> R;
	for (int i = 0; i < N+M; ++i) {
	    root[i] = i;
	    cost[i] = 10000;
	    mask[i] = false;
	}
	for (int r = 0; r < R; ++r) {
	    cin >> relations[r].x >> relations[r].y >> relations[r].d;
	    relations[r].y += N;
	}

	sort( relations, relations + R );
	for (int r = 0; r < R; ++r) {
	    int rx = find_set( relations[r].x );
	    int ry = find_set( relations[r].y );
	    if ( rx == ry ) continue;
	    union_set( rx, ry, relations[r].d );
	}

	int total = 0;
	for (int i = 0; i < N+M; ++i) {
	    int ri = find_set( i );
	    if ( !mask[ri] ) {
		total += cost[ri];
		mask[ri] = true;
	    }
	}
	cout << total << endl;
    }
    return 0;
}

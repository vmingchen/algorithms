#include	<iostream>

using namespace std;

const int MAXN = 100001;

int T, N, M, rank[MAXN], root[MAXN], dist[MAXN];

int find_set( int x ) 
{
    if ( root[x] == x ) return root[x];
    int old_root = root[x];
    int new_root = find_set( root[x] );
    dist[x] += dist[old_root];
    root[x] = new_root;
    return new_root;
}

void union_set( int a, int b )
{
    int x = find_set(a);
    int y = find_set(b);
    if ( x == y ) return ;
    if ( rank[x] > rank[y] ) {
	root[y] = x;
	dist[y] = dist[a] + 1;
    } else if ( rank[x] < rank[y] ) {
	root[x] = y;
	dist[x] = dist[b] + 1;
    } else {
	root[x] = y;
	dist[x] = dist[b] + 1;
	rank[y]++;
    }
}

int main()
{
    cin >> T;
    for ( int t = 0; t < T; ++t ) {
	cin >> N >> M;
	for ( int n = 1; n <= N; ++n ) {
	    rank[n] = dist[n] = 0;
	    root[n] = n;
	}
	char op;
	int a, b;
	for ( int m = 1; m <= M; ++m ) {
	    cin >> op >> a >> b;
	    if ( op == 'A' ) {
		int x = find_set(a),
		    y = find_set(b);
		if ( x != y ) {
		    cout << "Not sure yet." << endl;
		} else {
		    if ( (dist[a] - dist[b]) % 2 == 0 ) {
			cout << "In the same gang." << endl;
		    } else {
			cout << "In different gangs." << endl;
		    }
		}
	    } else {
		union_set( a, b );
	    }
	}
    }
    return 0;
}

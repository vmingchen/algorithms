#include	<iostream>

using namespace std;

const int MAXN = 1002;

int points[MAXN][2] = {{0}}, 
    root[MAXN] = {0}, 
    rank[MAXN] = {0}, 
    state[MAXN] = {0};

bool connected[MAXN][MAXN] = {{false}};

int set_find( int x ) 
{
    if ( root[x] == x ) return x;
    int r = set_find( root[x] );
    root[x] = r;
    return r;
}

void set_union( int x, int y ) 
{
    int rx = set_find(x);
    int ry = set_find(y);
    if ( rank[rx] < rank[ry] ) {
	root[rx] = ry;
    } else if ( rank[rx] > rank[ry] ) {
	root[ry] = rx;
    } else {
	root[ry] = rx;
	rank[rx] += 1;
    }
}

int main()
{
    int N, D, D2;
    cin >> N >> D;	
    D2 = D*D;
    for ( int n = 1; n <= N; ++n ) {
	cin >> points[n][0] >> points[n][1];
	connected[n][n] = true;
	for ( int i = 1; i < n; ++i ) {
	    int dx = (points[n][0] - points[i][0]);
	    int dy = (points[n][1] - points[i][1]);
	    if ( dx*dx + dy*dy <= D2 ) {
		connected[i][n] = true;
		connected[n][i] = true;
	    }
	}
    }

    char op;
    int x, y;

    while ( cin >> op ) {
	if ( op == 'O' ) {
	    cin >> x;
	    state[x] = 1;
	    root[x] = x;
	    for ( int n = 1; n <= N; ++n ) {
		if ( state[n] == 1 && connected[n][x] && n != x ) 
		    set_union( x, n );
	    }
	} else {
	    cin >> x >> y;
	    int rx = set_find(x), ry = set_find(y);
	    if ( rx == ry ) 
		cout << "SUCCESS" << endl;
	    else
		cout << "FAIL" << endl;
	}
    }

    return 0;
}

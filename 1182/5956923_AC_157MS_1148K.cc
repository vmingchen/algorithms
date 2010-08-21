#include	<stdio.h>

const int MAXN = 50001;

using namespace std;

int N, K, root[MAXN], rank[MAXN], dist[MAXN];

int find_set( int a ) 
{
    if ( root[a] == a ) return a;
    int old_root = root[a];
    int new_root = find_set(root[a]);
    dist[a] += dist[old_root];
    root[a] = new_root;
    return new_root;
}

void union_set( int a, int b, int op )
{
    int x = find_set(a);
    int y = find_set(b);
    if ( x == y ) return;
    if ( rank[x] < rank[y] ) {
	root[x] = y;
	dist[x] = dist[b] - (dist[a] + op - 1);
    } else if ( rank[x] > rank[y] ) {
	root[y] = x;
	dist[y] = (dist[a] + op - 1) - dist[b];
    } else {
	root[y] = x;
	rank[x]++;
	dist[y] = (dist[a] + op - 1) - dist[b];
    }
}

int main()
{
    scanf("%d %d", &N, &K);
    for ( int i = 1; i <= N; ++i ) {
	root[i] = i;
	dist[i] = rank[i] = 0;
    }

    int res = 0;
    for ( int k = 1; k <= K; ++k ) {
	int D, X, Y;
	scanf("%d %d %d", &D, &X, &Y);
	if ( X > N || Y > N || (D == 2 && X == Y) ) {
	    ++res;
	    continue;
	}
	int rx = find_set(X),
	    ry = find_set(Y);
	if ( rx == ry ) {
	    int d = (dist[X] - dist[Y]) % 3;
	    if ( d < 0 ) d += 3;
	    if ( D == 1 && d != 0 ) ++res;
	    if ( D == 2 && d != 2 ) ++res;
	} else {
	    union_set( X, Y, D );
	}
    }

    printf("%d\n", res);
    
    return 0;
}

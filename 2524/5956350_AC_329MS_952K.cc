#include	<stdio.h>
#include	<string.h>

const int MAXN = 50001;

int root[MAXN], rank[MAXN], res;

int find_set( int a )
{
    if ( root[a] == a ) return a;
    int nr = find_set( root[a] );
    root[a] = nr;
    return nr;
}

void union_set( int a, int b ) 
{
    int x = find_set(a);
    int y = find_set(b);
    if ( x == y ) return ;
    if ( rank[x] > rank[y] ) {
	root[y] = x;
    } else if ( rank[y] > rank[x] ) {
	root[x] = y;
    } else {
	root[x] = y;
	rank[y]++;
    }
    --res;
}


int main()
{
    int c, n, m;
    for ( c = 1; scanf("%d %d", &n, &m) && n != 0 && m != 0; ++c ) {
	for ( int i = 1; i <= n; ++i ) {
	    root[i] = i;
	    rank[i] = 0;
	}
	res  = n;
	for ( int i = 0; i < m; ++i ) {
	    int a, b;
	    scanf("%d %d", &a, &b);
	    union_set( a, b );
	}
	printf("Case %d: %d\n", c, res);
    }
    return 0;
}

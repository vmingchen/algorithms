#include	<iostream>

using namespace std;

const int MAXN = 100001;

class Node {
public:
    int left, right, add, num;
    long long sum;
};

Node nodes[5*MAXN];
int N, Q, integers[MAXN];

void build( int pn, int a, int b ) 
{
    nodes[pn].left = a;
    nodes[pn].right = b;
    nodes[pn].num = (b-a+1);
    nodes[pn].add = 0;
    if ( a == b ) {
	nodes[pn].sum = integers[a];
    } else {
	int mid = (a + b) >> 1;
	int plc = pn << 1;
	int prc = plc + 1;
	build( plc, a, mid );
	build( prc, mid+1, b );
	nodes[pn].sum = nodes[plc].sum + nodes[prc].sum;
    }
}

void insert( int pn, int a, int b, int c )
{
    if ( a > b ) return ;
    int plc = pn << 1;
    int prc = plc + 1;
    if ( nodes[pn].left == a && nodes[pn].right == b ) {
	nodes[pn].add += c;
	return ;
    }
    int mid = (nodes[pn].left + nodes[pn].right) >> 1;
    nodes[plc].add += nodes[pn].add;
    nodes[prc].add += nodes[pn].add;
    insert( plc, a, min(b, mid), c );
    insert( prc, max(mid+1, a), b, c );
    nodes[pn].sum = (nodes[plc].sum + nodes[plc].add * nodes[plc].num)
	    + (nodes[prc].sum + nodes[prc].add * nodes[prc].num);
    nodes[pn].add = 0;
}

void query( int pn, int a, int b, long long *pc ) 
{
    if ( a > b ) return ;
    if ( nodes[pn].left == a && nodes[pn].right == b ) {
	*pc += (nodes[pn].sum + nodes[pn].add * nodes[pn].num);
	return ;
    }
    int mid = (nodes[pn].left + nodes[pn].right) >> 1;
    int plc = pn << 1;
    int prc = plc + 1;
    nodes[plc].add += nodes[pn].add;
    nodes[prc].add += nodes[pn].add;
    nodes[pn].add = 0;
    query( plc, a, min(b, mid), pc );
    query( prc, max(mid+1, a), b, pc );
    nodes[pn].sum = (nodes[plc].sum + nodes[plc].add * nodes[plc].num)
	    + (nodes[prc].sum + nodes[prc].add * nodes[prc].num);
}

int main()
{
    cin >> N >> Q;
    for ( int n = 1; n <= N; ++n ) cin >> integers[n];
    char op;
    int a, b, c, root = 1;
    build( root, 1, N );
    while ( cin >> op ) {
	if ( op == 'C' ) {
	    cin >> a >> b >> c;
	    insert( root, a, b, c );
	} else {
	    cin >> a >> b;
	    long long res = 0;
	    query( root, a, b, &res );
	    cout << res << endl;
	}
    }
    return 0;
}

#include	<iostream>
#include	<algorithm>

using namespace std;

const int MAXN = 10001;

class Node {
public:
    int left, right, value;
};

class Tick {
public:
    int value, index;
};

Node nodes[10*MAXN+2];

bool operator<(const Tick& ta, const Tick& tb) { return ta.value < tb.value; }

void build(int pno, int left, int right)
{
    nodes[pno].left = left;
    nodes[pno].right = right;
    nodes[pno].value = 0;
    if ( left == right ) { return ; }
    int mid = (left + right)/2;
    int plc = pno << 1;
    int prc = plc + 1;
    build( plc, left, mid );
    build( prc, mid+1, right );
}

void insert(int pno, int left, int right, int value)
{
    if ( left > right ) return ;
    if ( nodes[pno].left == left && nodes[pno].right == right ) {
	nodes[pno].value = value;
	return ;
    }
    int mid = (nodes[pno].left + nodes[pno].right)/2;
    int plc = pno << 1;
    int prc = plc + 1;
    if ( nodes[pno].value > 0 ) {
	nodes[plc].value = nodes[pno].value;
	nodes[prc].value = nodes[pno].value;
	nodes[pno].value = 0;
    }
    insert( plc, left, min(mid, right), value );
    insert( prc, max(mid+1, left), right, value );

}

void count(int pno, int *pmasks)
{
    if ( nodes[pno].value > 0 ) {
	pmasks[nodes[pno].value] = 1;
	return ;
    }
    if ( nodes[pno].left == nodes[pno].right ) { return ; }
    int plc = pno << 1;
    int prc = plc + 1;
    count( plc, pmasks );
    count( prc, pmasks );
}

int main()
{
    int T;
    cin >> T;
    for ( int t = 0; t < T; ++t ) {
	int N, left, right, masks[MAXN+1] = {0}, positions[MAXN][2];
	Tick ticks[2*MAXN+1];
	ticks[0].value = 0;
	int tlen = 1;
	cin >> N;
	for ( int n = 0; n < N; ++n ) {
	    cin >> left >> right;
	    ticks[tlen].value = left;
	    ticks[tlen++].index = (n<<1);
	    ticks[tlen].value = right;
	    ticks[tlen++].index = (n<<1) + 1;
	}
	sort( ticks, ticks + tlen );
	int nlen = 0;
	for ( int i = 1; i < tlen; ++i ) {
	    int no = ticks[i].index >> 1;
	    int lr = ticks[i].index - (no<<1);
	    if ( ticks[i].value == ticks[nlen].value ) {
		positions[no][lr] = nlen;
	    } else {
		positions[no][lr] = ++nlen;
		ticks[nlen].value = ticks[i].value;
	    }
	}
//	for ( int i = 0; i < N; ++i ) 
//	    cout << positions[i][0] << ", " << positions[i][1] << endl;
	int root = 1;
	build( root, 1, nlen );
	for ( int n = 0; n < N; ++n ) 
	    insert( root, positions[n][0], positions[n][1], n+1 );
	count( root, masks );

	int nvisible = 0;
	for ( int n = 1; n <= N; ++n ) 
	    nvisible += masks[n];

	cout << nvisible << endl;
    }
    return 0;
}

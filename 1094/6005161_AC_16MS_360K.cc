#include	<cstdio>
#include	<algorithm>

using namespace std;

const int MAXN = 27, MAXE = 26*25;

class Edge {
public:
    int node, next;
};

int adjacent[MAXN];
int id[MAXN], od[MAXN], tid[MAXN], tod[MAXN];
int n, m;

Edge edges[MAXE];
int ep = 1;

int new_edge() { edges[ep].next = 0; return ep++; }
void reset_edge() { ep = 1; }
int add_edge( int from, int to ) 
{
    int ne = new_edge();
    edges[ne].node = to;
    edges[ne].next = adjacent[from];
    adjacent[from] = ne;
    return ne;
}

int stack[MAXN], sp;

void reset_stack() { sp = 0; }
void push(int i) { stack[sp++] = i; }
int pop() { return stack[sp--]; }
int length() { return sp; }

int topo_sort( ) 
{
    bool unknown = false;
    int tid[26];
    reset_stack();
    copy( id, id + n, tid );
    for ( int i = 0; i < n; ++i ) {
	int nz = count( tid, tid + n, 0 );
	if ( nz == 0 ) return -1;
	if ( nz > 1 ) unknown = true;
	int pos = distance( tid, find(tid, tid + n, 0));
	for (  int pn = adjacent[pos]; pn != 0; pn = edges[pn].next ) {
	    --tid[edges[pn].node];
	}
	tid[pos] = -1;
	push( pos );
    }
    return unknown ? 0 : 1;
}

int main()
{
    while ( scanf("%d %d", &n, &m) && (n != 0 || m != 0) ) {
	for ( int i = 0; i < n; i++ ) {
	    od[i] = 0;
	    id[i] = 0;
	    adjacent[i] = 0;
	}
	reset_edge();
	reset_stack();
	char a, b;
	int res = 0; 	// 0 for unknown, 1 for sorted, -1 for inconsistency
	int pos = 0;
	for ( int i = 0; i < m; i++ ) {
	    scanf("\n%c<%c", &a, &b);
	    int from = a - 'A';
	    int to = b - 'A';
	    add_edge( from, to );
	    id[to]++;

	    if ( res == 0 ) {
		res = topo_sort();
		pos = i + 1;
	    }
	}
	if ( res == 1 ) {
	    printf("Sorted sequence determined after %d relations: ", pos);
	    for ( int j = 0; j < n;  ++j ) 
		printf("%c", stack[j] + 'A');
	    printf(".\n");
	} else if ( res == -1 ) {
	    printf("Inconsistency found after %d relations.\n", pos);
	} else {
	    printf("Sorted sequence cannot be determined.\n");
	}
    }
    return 0;
}

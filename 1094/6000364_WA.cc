#include	<cstdio>

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

int new_edge() { return ep++; }
void reset_edge() { ep = 1; }
int add_edge( int to, int from ) 
{
    int ne = new_edge();
    edges[ne].node = from;
    edges[ne].next = adjacent[to];
    adjacent[to] = ne;
    return ne;
}

int stack[MAXN], sp;

void reset_stack() { sp = 0; }
void push(int i) { stack[sp++] = i; }
int pop() { return stack[sp--]; }
int length() { return sp; }


int search( int start )
{
    push( start );
    if ( length() == n ) return 1;			// ordered
    int next = -1;
    for ( int pn = adjacent[start]; pn != 0; pn = edges[pn].next ) {
	if ( tod[edges[pn].node] == 0 ) 
	    return -1;	// inconsistency
	if ( --tod[edges[pn].node] == 0 ) 
	    next = edges[pn].node;
    }	
    if ( next < 0 ) return 0;				// unknown
    return search( next );
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
	    add_edge( to, from );
	    od[from]++;
	    id[to]++;
	    if ( res == 0 ) {
		reset_stack();
		for ( int j = 0; j < n; ++j ) {
		    tid[j] = id[j];
		    tod[j] = od[j];
		}
		tod[to] = 0;
		res = search( to );
		pos = i + 1;
	    }
	}
	if ( res == 1 ) {
	    printf("Sorted sequence determined after %d relations: ", pos);
	    for ( int j = n-1; j >=0;  --j ) 
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

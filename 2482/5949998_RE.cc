#include	<iostream>
#include	<algorithm>

const int MAXN = 10001;

using namespace std;

class Star {
public:
    int x, y, c, xls, xle, yls, yle;
};

class Node {
public:
    int left, right, count;
    Node *plc, *prc;
};

class Label {
public:
    int value, index;
};

Star stars[MAXN]; 
Label xlabels[2*MAXN], ylabels[2*MAXN];
Node nodes[2*MAXN];
int num = 0;

Node* new_node(int left, int right)
{
    nodes[num].left = left;
    nodes[num].right = right;
    nodes[num].count = 0;
    nodes[num].plc = NULL;
    nodes[num].prc = NULL;
    return nodes + (num++);
}

void reset_node() { num = 0; }

bool operator<(const Star &sa, const Star &sb) 
{ 
    return (sa.x != sb.x) ? (sa.x < sb.x) : (sa.y < sb.y);
}

bool operator<(const Label &la, const Label &lb) {
    return (la.value != lb.value) ? (la.value < lb.value) : (la.index < lb.index);
}

Node* build(int left, int right) 
{
    if ( left > right ) return NULL;
    if ( left == right ) {
	return new_node(left, right);
    }
    Node *pnode = new_node(left, right);
    int mid = (left + right)/2;
    pnode->plc = build(left, mid);
    pnode->prc = build(mid+1, right);
    return pnode;
}

void insert(Node *pnode, int left, int right, int count)
{
    if ( pnode == NULL || left > right ) return ;
    if ( pnode->left == left && pnode->right == right ) { 
	pnode->count += count;
	return ;
    }
    int mid = (pnode->left + pnode->right)/2;
    insert( pnode->plc, left, min(mid, right), count );
    insert( pnode->prc, max(mid+1, left), right, count );
}

void query(Node *pnode, int *pmost, int descent)
{
    if ( pnode == NULL ) return ;
    int nc = pnode->count + descent;
    if ( pnode->left == pnode->right ) {
	if ( nc > *pmost ) *pmost = nc;
	return ;
    }
    query( pnode->plc, pmost, nc );
    query( pnode->prc, pmost, nc );
}

int main()
{
    int n, W, H;

    while ( cin >> n >> W >> H ) {
	int xn = -1, yn = -1;
	for ( int i = 0; i < n; ++i ) {
	    cin >> stars[i].x >> stars[i].y >> stars[i].c;
	    xlabels[++xn].value = max(0, stars[i].x - W ); 
	    xlabels[xn].index = xn;
	    xlabels[++xn].value = stars[i].x;	
	    xlabels[xn].index = xn;

	    ylabels[++yn].value = max(0, stars[i].y - H );
	    ylabels[yn].index = yn;
	    ylabels[++yn].value = stars[i].y;
	    ylabels[yn].index = yn;
	}
	++xn; ++yn;
	sort( xlabels, xlabels + xn );
	sort( ylabels, ylabels + yn );
	for ( int i = 0; i < 2*n; ++i ) {
	    int xi = xlabels[i].index;
	    if ( xi & 0x01 ) stars[xi>>1].xle = i;
	    else stars[xi>>1].xls = i;
	    int yi = ylabels[i].index;
	    if ( yi & 0x01 ) stars[yi>>1].yle = i;
	    else stars[yi>>1].yls = i;
	}

	int most = 0;
	Node *proot = build(0, n*2-1);
	for ( int i = 0; i < n*2; ++i ) {
	    int si = xlabels[i].index >> 1;
	    if ( xlabels[i].value == stars[si].x ) {
		insert( proot, stars[si].yls, stars[si].yle, -1*stars[si].c );
	    } else {
		insert( proot, stars[si].yls, stars[si].yle, stars[si].c );
		query( proot, &most, 0 );
	    }
	}
	cout << most << endl;
	reset_node();
    }
    return 0;
}

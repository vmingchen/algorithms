#include	<iostream>
#include	<algorithm>

const double OFFSET = 0.01;
const int MAXN = 100000;

using namespace std;

class Star {
public:
    int x, y, c, xls, xle, yls, yle;
};

class Node {
public:
    int left, right, count, most;
    Node *plc, *prc;
};

class Label {
public:
    double value;
    int index;
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
    nodes[num].most = 0;
    nodes[num].plc = NULL;
    nodes[num].prc = NULL;
    return nodes + (num++);
}

void reset_node() { num = 0; }

bool operator<(const Star &sa, const Star &sb) { 
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
    int mid = (left + right) >> 1;
    pnode->plc = build(left, mid);
    pnode->prc = build(mid+1, right);
    return pnode;
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

void insert(Node *pnode, int left, int right, int count)
{
    if ( pnode == NULL || left > right ) return ;
    if ( pnode->left == left && pnode->right == right ) { 
	pnode->count += count;
	int most = pnode->count;
	if ( pnode->plc != NULL && pnode->plc->most + pnode->count > most )
	    most = (pnode->plc->most + pnode->count);
	if ( pnode->prc != NULL && pnode->prc->most + pnode->count > most )
	    most = (pnode->prc->most + pnode->count);
	pnode->most = most;
	return ;
    }
    int mid = (pnode->left + pnode->right) >> 1;
    insert( pnode->plc, left, min(mid, right), count );
    insert( pnode->prc, max(mid+1, left), right, count );
    int most = 0;
    if ( pnode->plc != NULL && pnode->plc->most + pnode->count > most )
	most = (pnode->plc->most + pnode->count);
    if ( pnode->prc != NULL && pnode->prc->most + pnode->count > most )
	most = (pnode->prc->most + pnode->count);
    pnode->most = most;
}

int main()
{
    int n, W, H;

    while ( cin >> n >> W >> H ) {
	int xn = -1, yn = -1;
	for ( int i = 0; i < n; ++i ) {
	    cin >> stars[i].x >> stars[i].y >> stars[i].c;
	    xlabels[++xn].value = max(0.0, stars[i].x - W + OFFSET ); 
	    xlabels[xn].index = xn;
	    xlabels[++xn].value = stars[i].x;	
	    xlabels[xn].index = xn;

	    ylabels[++yn].value = max(0.0, stars[i].y - H + OFFSET );
	    ylabels[yn].index = yn;
	    ylabels[++yn].value = stars[i].y;
	    ylabels[yn].index = yn;
	}
	++xn; ++yn;
	sort( xlabels, xlabels + xn );
	sort( ylabels, ylabels + yn );
	for ( int i = 0; i < xn; ++i ) {
//	    int xi = xlabels[i].index;
//	    if ( xi & 0x01 ) stars[xi>>1].xle = i;
//	    else stars[xi>>1].xls = i;
	    int yi = ylabels[i].index;
	    if ( yi & 0x01 ) stars[yi>>1].yle = i;
	    else stars[yi>>1].yls = i;
	}

	int most = 0;
	Node *proot = build(0, yn-1);
	for ( int i = 0; i < xn; ++i ) {
	    int si = xlabels[i].index >> 1;
	    if ( xlabels[i].value == stars[si].x ) {
		insert( proot, stars[si].yls, stars[si].yle, -1*stars[si].c);
	    } else {
		insert( proot, stars[si].yls, stars[si].yle, stars[si].c);
		if ( proot->most > most ) most = proot->most;
	    }
	}
	cout << most << endl;
	reset_node();
    }
    return 0;
}

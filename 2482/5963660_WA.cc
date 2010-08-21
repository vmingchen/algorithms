#include	<iostream>
#include	<algorithm>

const int MAXN = 100000;

using namespace std;

class Star {
public:
    int x, y, c, yls, yle;
};

class Node {
public:
    int left, right, count, most;
};

class Label {
public:
    int value;
    int index;
};

Star stars[MAXN]; 
Label xlabels[2*MAXN], ylabels[2*MAXN];
Node nodes[2*MAXN];
int num = 0;

int new_node(int left, int right)
{
    nodes[num].left = left;
    nodes[num].right = right;
    nodes[num].count = 0;
    nodes[num].most = 0;
    return num++;
}

void reset_node() { num = 0; }

bool operator<(const Star &sa, const Star &sb) { 
    return (sa.x != sb.x) ? (sa.x < sb.x) : (sa.y < sb.y);
}

bool operator<(const Label &la, const Label &lb) {
    return (la.value != lb.value) ? (la.value < lb.value) : (la.index < lb.index);
}

void build(int pnode, int left, int right) 
{
    if ( left > right ) return ;
    nodes[pnode].left = left;
    nodes[pnode].right = right;
    nodes[pnode].count = 0;
    nodes[pnode].most = 0;
    if ( left != right ) {
	int mid = (left + right) >> 1;
	int plc = pnode << 1;
	int prc = plc + 1;
	build( plc, left, mid );
	build( prc, mid+1, right );
    }
}

void insert(int pnode, int left, int right, int count)
{
    if ( left > right ) return ;
    if ( nodes[pnode].left == left && nodes[pnode].right == right ) { 
	nodes[pnode].count += count;
	nodes[pnode].most += count;
	return ;
    }
    int mid = (nodes[pnode].left + nodes[pnode].right) >> 1;
    int plc = pnode << 1;
    int prc = plc + 1;
    nodes[plc].count += nodes[pnode].count;
    nodes[plc].most += nodes[pnode].count;
    nodes[prc].count += nodes[pnode].count;
    nodes[prc].most += nodes[pnode].count;
    nodes[pnode].count = 0;
    insert( plc, left, min(mid, right), count );
    insert( prc, max(mid+1, left), right, count );
    nodes[pnode].most = max( nodes[plc].most, nodes[prc].most );
}

int main()
{
    int n, W, H;

    while ( cin >> n >> W >> H ) {
	int xn = 0, yn = 0;
	for ( int i = 0; i < n; ++i ) {
	    cin >> stars[i].x >> stars[i].y >> stars[i].c;
	    xlabels[xn].value = max(0, stars[i].x - W ); 
	    xlabels[xn].index = xn;
	    xn++;
	    xlabels[xn].value = stars[i].x;	
	    xlabels[xn].index = xn;
	    xn++;

	    ylabels[yn].value = max(0, stars[i].y - H );
	    ylabels[yn].index = yn;
	    yn++;
	    ylabels[yn].value = stars[i].y;
	    ylabels[yn].index = yn;
	    yn++;
	}
	sort( xlabels, xlabels + xn );
	sort( ylabels, ylabels + yn );
	for ( int i = 0; i < xn; ++i ) {
	    int yi = ylabels[i].index;
	    if ( yi & 0x01 ) stars[yi>>1].yle = i;
	    else stars[yi>>1].yls = i;
	}

	int most = 0, proot = 1;
	reset_node();
	build( proot, 0, yn-1 );
	for ( int i = 0; i < xn; ++i ) {
	    int si = xlabels[i].index >> 1;
	    if ( xlabels[i].value == stars[si].x ) {
		insert( proot, stars[si].yls, stars[si].yle, -1*stars[si].c);
	    } else {
		insert( proot, stars[si].yls, stars[si].yle, stars[si].c);
		if ( nodes[proot].most > most ) most = nodes[proot].most;
	    }
	}
	cout << most << endl;
    }
    return 0;
}

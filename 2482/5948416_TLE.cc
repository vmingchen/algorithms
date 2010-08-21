#include	<iostream>
#include	<algorithm>

const int MAXN = 10001;

using namespace std;

class Node {
public:
    int dlx, dly, urx, ury, count;
    Node *pdl, *pul, *pdr, *pur;
    Node(int x1, int y1, int x2, int y2) 
	    : dlx(x1), dly(y1), urx(x2), ury(y2), count(0) {
	pdl = pul = pdr = pur = NULL;
    }
    ~Node() {
	if ( pdl ) { delete pdl; pdl = NULL; }
	if ( pul ) { delete pul; pul = NULL; }
	if ( pdr ) { delete pdr; pdr = NULL; }
	if ( pur ) { delete pur; pur = NULL; }
    }
};

int stars[MAXN][3];
int xlabels[2*MAXN], ylabels[2*MAXN], xn, yn;

Node* build(int dlx, int dly, int urx, int ury) 
{
    if ( dlx > urx || dly > ury ) return NULL;
    if ( dlx == urx && dly == ury ) {
	return new Node(dlx, dly, urx, ury);
    }
    Node *pnode = new Node(dlx, dly, urx, ury);
    int midx = (dlx + urx)/2;
    int midy = (dly + ury)/2;
    pnode->pdl = build(dlx, dly, midx, midy);
    pnode->pul = build(dlx, midy+1, midx, ury);
    pnode->pdr = build(midx+1, dly, urx, midy);
    pnode->pur = build(midx+1, midy+1, urx, ury);
    return pnode;
}

void insert(Node *pnode, int dlx, int dly, int urx, int ury, int count)
{
    if ( pnode == NULL || dlx > urx || dly > ury ) return ;
    if ( pnode->dlx == dlx && pnode->dly == dly 
	    && pnode->urx == urx && pnode->ury == ury ) {
	pnode->count += count;
	return ;
    }
    int midx = (pnode->dlx + pnode->urx)/2;
    int midy = (pnode->dly + pnode->ury)/2;
    insert( pnode->pdl, dlx, dly, min(midx, urx), min(midy, ury), count );
    insert( pnode->pul, dlx, max(midy+1, dly), min(midx, urx), ury, count );
    insert( pnode->pdr, max(midx+1, dlx), dly, urx, min(midy, ury), count ); 
    insert( pnode->pur, max(midx+1, dlx), max(midy+1, dly), urx, ury, count );
}

void descent(Node *pnode)
{
    if ( pnode == NULL ) return ;
    if ( pnode->dlx == pnode->urx && pnode->dly == pnode->ury ) 
	return ;
    if ( pnode->pdl ) pnode->pdl->count += pnode->count; descent(pnode->pdl);
    if ( pnode->pul ) pnode->pul->count += pnode->count; descent(pnode->pul);
    if ( pnode->pdr ) pnode->pdr->count += pnode->count; descent(pnode->pdr);
    if ( pnode->pur ) pnode->pur->count += pnode->count; descent(pnode->pur);
}

void query(Node *pnode, int *pmost)
{
    if ( pnode == NULL ) return ;
    if ( pnode->dlx == pnode->urx && pnode->dly == pnode->ury ) {
	if ( pnode->count > *pmost ) *pmost = pnode->count;
	return ;
    }
    query( pnode->pdl, pmost );
    query( pnode->pul, pmost );
    query( pnode->pdr, pmost );
    query( pnode->pur, pmost );
}

int main()
{
    int n, W, H;

    while ( cin >> n >> W >> H ) {
	xn = yn = 0;
	for ( int i = 0; i < n; ++i ) {
	    int x, y, c;
	    cin >> x >> y >> c;
	    xlabels[xn++] = x;
	    xlabels[xn++] = max(0, x - W + 1);
	    ylabels[yn++] = y;
	    ylabels[yn++] = max(0, y - H + 1);
	    stars[i][0] = x;
	    stars[i][1] = y;
	    stars[i][2] = c;
	}
	sort( xlabels, xlabels + xn );
	sort( ylabels, ylabels + yn );
	Node *proot = build(0, 0, xn-1, yn-1);
	for ( int i = 0; i < n; ++i ) {
	    int dlx = find( xlabels, xlabels + xn, max(stars[i][0] - W + 1, 0) ) - xlabels;
	    while ( dlx > 0 && xlabels[dlx] == xlabels[dlx-1] ) --dlx;
	    int urx = find( xlabels, xlabels + xn, stars[i][0] ) - xlabels;
	    while ( urx < xn-1 && xlabels[urx] == xlabels[urx+1] ) ++urx;
	    int dly = find( ylabels, ylabels + yn, max(stars[i][1] - H + 1, 0) ) - ylabels;
	    while ( dly > 0 && ylabels[dly] == ylabels[dly-1] ) --dly;
	    int ury = find( ylabels, ylabels + yn, stars[i][1] ) - ylabels;
	    while ( ury < yn-1 && ylabels[ury] == ylabels[ury+1] ) ++ury;
	    insert( proot, dlx, dly, urx, ury, stars[i][2] );
	}
	int most = 0;
	descent( proot );
	query ( proot, &most );
	cout << most << endl;
	delete proot;
    }
    return 0;
}

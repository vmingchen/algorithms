#include	<iostream>
#include	<algorithm>
#include	<iomanip>

const int MAXN = 100;

using namespace std;

class Node {
public:
    int tlxi, tlyi, brxi, bryi, count;
    Node *ptt, *ptm, *pmt, *pmm;
    Node (int x1, int y1, int x2, int y2) 
	    : tlxi(x1), tlyi(y1), brxi(x2), bryi(y2), count(0),
	    ptt(NULL), ptm(NULL), pmt(NULL), pmm(NULL) {};
    ~Node () {
	if ( ptt != NULL ) { delete ptt; ptt = NULL; }
	if ( ptm != NULL ) { delete ptm; ptm = NULL; }
	if ( pmt != NULL ) { delete pmt; pmt = NULL; }
	if ( pmm != NULL ) { delete pmm; pmm = NULL; }
    }
};

void build(Node *parent) 
{
    if ( parent->tlxi >= parent->brxi - 1 
	    && parent->tlyi >= parent->bryi - 1 ) return ;
    int midx = (parent->tlxi + parent->brxi)/2;
    int midy = (parent->tlyi + parent->bryi)/2;
    parent->ptt = new Node( parent->tlxi, parent->tlyi, midx, midy );
    parent->ptm = new Node( midx, parent->tlyi, parent->brxi, midy );
    parent->pmt = new Node( parent->tlxi, midy, midx, parent->bryi );
    parent->pmm = new Node( midx, midy, parent->brxi, parent->bryi );

    build( parent->ptt );
    build( parent->ptm );
    build( parent->pmt );
    build( parent->pmm );
}

void insert(Node *pnode, int tlx, int tly, int brx, int bry)
{
    if ( tlx >= brx || tly >= bry || pnode == NULL || pnode->count == 1 ) return ;
    if ( pnode->tlxi == tlx && pnode->tlyi == tly 
	    && pnode->brxi == brx && pnode->bryi == bry ) {
	pnode->count = 1;
	return ;
    }
    if ( pnode->brxi <= pnode->tlxi + 1 && pnode->bryi <= pnode->tlyi + 1 )
	return;
    int midx = (pnode->tlxi + pnode->brxi)/2;
    int midy = (pnode->tlyi + pnode->bryi)/2;
    insert( pnode->ptt, tlx, tly, min(midx, brx), min(midy, bry) );
    insert( pnode->ptm, max(midx, tlx), tly, brx, min(midy, bry) );
    insert( pnode->pmt, tlx, max(midy, tly), min(midx, brx), bry );
    insert( pnode->pmm, max(midx, tlx), max(midy, tly), brx, bry );
}

double calc(Node *pnode, double *mapx, double *mapy ) 
{
    if ( pnode == NULL ) return 0;
    if ( pnode->count == 1 ) {
	return (mapx[pnode->brxi] - mapx[pnode->tlxi]) 
	    * (mapy[pnode->bryi] - mapy[pnode->tlyi]);
    } else {
	return calc( pnode->ptt, mapx, mapy ) 
	    + calc( pnode->ptm, mapx, mapy )
	    + calc( pnode->pmt, mapx, mapy )
	    + calc( pnode->pmm, mapx, mapy );
    }	
}

int main()
{
    int n;

    cout << setprecision(2) << fixed;
    for ( int caseno = 1; cin >> n && n != 0; caseno++ ) {
	double tlxs[MAXN], tlys[MAXN], brxs[MAXN], brys[MAXN], 
	       mapx[2*MAXN], mapy[2*MAXN];
	int xi = 0, yi = 0;

	for ( int i = 0; i < n; ++i ) {
	    cin >> tlxs[i] >> tlys[i] >> brxs[i] >> brys[i];
	    mapx[xi++] = tlxs[i];
	    mapx[xi++] = brxs[i];
	    mapy[yi++] = tlys[i];
	    mapy[yi++] = brys[i];
	}

	sort( mapx, mapx + xi );
	double *pnx = unique( mapx, mapx + xi );
	int nx = pnx - mapx;

	sort( mapy, mapy + yi );
	double *pny = unique( mapy, mapy + yi );
	int ny = pny - mapy;

	Node * root = new Node(0, 0, nx-1, ny-1);
	build( root );
	for ( int i = 0; i < n; ++i ) {
	    double *ptlx = find( mapx, pnx, tlxs[i] );
	    double *ptly = find( mapy, pny, tlys[i] );
	    double *pbrx = find( mapx, pnx, brxs[i] );
	    double *pbry = find( mapy, pny, brys[i] );
	    insert( root, ptlx - mapx, ptly - mapy, pbrx - mapx, pbry - mapy );
	}

	double res = calc( root, mapx, mapy );
	cout << "Test case #" << caseno << endl;
	cout << "Total explored area: " << res << endl;

	delete root;
    }
    return 0;
}

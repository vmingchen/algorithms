#include	<iostream>
#include	<algorithm>

using namespace std;

const int MAXN = 26;

class Lake {
public:
    int index, fish, decrease;
};

bool operator< (const Lake &a, const Lake &b)
{
    if ( a.fish == b.fish ) return a.index > b.index;
    else	return a.fish < b.fish;
}

void insert(Lake *pLakes, Lake newlake, int i)
{
    pLakes[i] = newlake;
    int ci = i;
    while ( ci != 1 ) {
	int pi = ci/2;
	if ( pLakes[ci] < pLakes[pi] ) break;
	swap( pLakes[ci], pLakes[pi] );
	ci = pi;
    }
}

Lake update(Lake *pLakes, int n)
{
    Lake lake = pLakes[1];
    pLakes[1].fish = max( pLakes[1].fish - pLakes[1].decrease, 0 );
    int pi = 1;
    while ( pi < n ) {
	int li = pi*2, ri = pi*2+1, di = pi;
	if ( li <= n && pLakes[di] < pLakes[li] ) di = li;
	if ( ri <= n && pLakes[di] < pLakes[ri] ) di = ri;
	if ( pi == di ) break;
	swap( pLakes[pi], pLakes[di] );
	pi = di;
    }
    return lake;
}

int main()
{
    int n;

    while ( cin >> n && n != 0 ) {
	Lake lakes[MAXN];
	int h, ts[MAXN], maxfish, maxspent[MAXN] = {0};
	cin >> h;
	for ( int i = 0; i < n; ++i ) lakes[i].index = i;
	for ( int i = 0; i < n; ++i ) cin >> lakes[i].fish;
	for ( int i = 0; i < n; ++i ) cin >> lakes[i].decrease;
	ts[0] = 0;
	for ( int i = 1; i < n; ++i) {
	    cin >> ts[i];
	    ts[i] += ts[i-1];
	}

	maxfish = 0;
	for ( int k = 0; k < n; ++k ) {
	    Lake lheap[MAXN]; 
	    int fish = 0, spent[MAXN] = {0};

	    for ( int i = 0; i <= k; ++i ) {
		insert( lheap, lakes[i], i+1 );
	    }

	    for ( int remain = h*60/5 - ts[k]; remain > 0; --remain ) {
		Lake l = update(lheap, k+1);
		spent[l.index]++;
		fish += l.fish;
	    }

	    if ( fish > maxfish ) {
		maxfish = fish;
		for ( int j = 0; j <=k; ++j ) {
		    maxspent[j] = spent[j];
		}
	    }
	}

	cout << maxspent[0]*5;
	for ( int i = 1; i < n; ++i ) 
	    cout << ", " << maxspent[i]*5;
	cout << endl << "Number of fish expected: " << maxfish << endl;
	cout << endl;
    }
    return 0;
}

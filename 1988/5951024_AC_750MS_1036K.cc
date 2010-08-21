#include	<iostream>

using namespace std;

const int MAXN = 30001;

class DSet {
public:
    int root, length, distance;
    DSet() : root(0), length(1), distance(0) {}
};

DSet trees[MAXN];

int set_find( int x )
{
    if ( trees[x].root == 0 ) return x;
    int old_root = trees[x].root;
    int new_root = set_find( trees[x].root );
    trees[x].distance += trees[old_root].distance;
    trees[x].root = new_root;
    return new_root;
}

void set_union( int i, int j ) 
{
    int x = set_find(i);
    int y = set_find(j);
    trees[y].root = x;
    trees[y].distance = trees[x].length;
    trees[x].length += trees[y].length;
}

int main()
{
    int P, X, Y;
    char op;

    cin >> P;
    for ( int p = 0; p < P; ++p ) {
	cin >> op;
	if ( op == 'M' ) {
	    cin >> X >> Y;
	    set_union( X, Y );
	} else {
	    cin >> X;
	    cout << trees[set_find(X)].length - trees[X].distance - 1 << endl;
	}
    }
    return 0;
}

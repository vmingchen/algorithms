#include	<iostream>
#include	<algorithm>

using namespace std;

const int MAXP = 100000;

class Post {
public:
    int x, y;
};

Post posts[MAXP];
int sorted_x[MAXP], sorted_y[MAXP];

bool cmp_x(const int &a, const int &b)
{
    return (posts[a].x != posts[b].x) 
	? (posts[a].x < posts[b].x)
       	: (posts[a].y < posts[b].y);
}

bool cmp_y(const int &a, const int &b)
{
    return (posts[a].y != posts[b].y)
	? (posts[a].y < posts[b].y)
	: (posts[a].x < posts[b].x);
}

int main()
{
    int n, l;

    while ( cin >> n && n != 0 ) {
	for ( int i = 0; i < n; ++i ) {
	    cin >> posts[i].x >> posts[i].y;
	    sorted_x[i] = sorted_y[i] = i;
	}

	sort( sorted_x, sorted_x+n, cmp_x );
	sort( sorted_y, sorted_y+n, cmp_y );

	l = 0;
	for ( int i = 0; i < n-1; i+=2 ) {
	    l += posts[sorted_x[i+1]].y - posts[sorted_x[i]].y;
	    l += posts[sorted_y[i+1]].x - posts[sorted_y[i]].x;
	}
	cout << "The length of the fence will be " << l << " units." << endl;
    }
    return 0;
}

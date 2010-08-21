#include	<iostream>
#include	<algorithm>

using namespace std;

const int MAXS = 100;

class Point {
public:
    int x, y, h;
};

bool cmp_ptr ( const Point & p1, const Point &p2 )
{
    return p1.h < p2.h;
}

int main()
{
    int R, C, field[MAXS][MAXS], dist[MAXS][MAXS], np = 0;
    Point points[MAXS*MAXS];

    cin >> R >> C;
    for ( int i = 0; i < R; ++i ) {
	for ( int j = 0; j < C; ++j ) {
	    cin >> field[i][j];
	    points[np].x = i;
	    points[np].y = j;
	    points[np++].h = field[i][j];
	    dist[i][j] = 1;
	}
    }	

    sort( points, points + np, cmp_ptr );

    for ( int n = 0; n < np; ++n ) {
	int x = points[n].x, y = points[n].y, h = points[n].h;
	if ( x > 0 && h > field[x-1][y] ) 
	    dist[x][y] = max( dist[x-1][y] + 1, dist[x][y] );
	if ( x < R-1 && h > field[x+1][y] ) 
	    dist[x][y] = max( dist[x+1][y] + 1, dist[x][y] );
	if ( y > 0 && h > field[x][y-1] ) 
	    dist[x][y] = max( dist[x][y-1] + 1, dist[x][y] );
	if ( y < C-1 && h > field[x][y+1] )
	    dist[x][y] = max( dist[x][y+1] + 1, dist[x][y] );
    }

    int mdist = 0;
    for ( int i = 0; i < R; ++i ) {
	for ( int j = 0; j < C; ++j ) {
	    if ( dist[i][j] > mdist ) mdist = dist[i][j];
	}
    }

    cout << mdist << endl;

    return 0;
}

#include	<iostream>
#include	<algorithm>

using namespace std;

const int MAXN = 100001, MAXV = 1000000001;

int label[2*MAXN];

class Point {
public:
    int x, y, index;
};

class Segment {
public:
    int beg, end, loc;
    Segment() : beg(0), end(0), loc(0) {};
    Segment(int b, int e, int l) : beg(b), end(e), loc(l) {};
};

bool operator< (const Segment &sa, const Segment &sb) 
{
    return sa.loc < sb.loc;
}

Point points[MAXN];
Segment xsegments[MAXN], ysegments[MAXN];
int xp = 0, yp = 0;

bool cmp_px( const Point &pa, const Point &pb ) 
{
    return (pa.x == pb.x) ? pa.y < pb.y : pa.x < pb.x;
}

bool cmp_py( const Point &pa, const Point &pb )
{
    return (pa.y == pb.y) ? pa.x < pb.x : pa.y < pb.y;
}

int main()
{
    int n, count;
    
    cin >> n;
    for ( int i = 0; i < n; ++i ) {
	cin >> points[i].x >> points[i].y;
	points[i].index = i;
    }

    // sort by x
    sort( points, points + n, cmp_px );
    int beg = -1, end = -1;
    for ( int i = 0; i < n; ++i ) {
	if ( beg < 0 ) {
	    beg = i;
	    continue;
	} 
	if ( end < 0 ) {
	    if ( points[i].x == points[beg].x ) {
		end = i;
	    } else {
		beg = i;
	    }
	} else {
	    if ( points[i].x == points[beg].x ) {
		end = i;
	    } else {
		xsegments[xp++] = Segment(points[beg].y, points[end].y, points[beg].x);
		beg = i;
		end = -1;
	    }
	}
    }
    if ( beg > 0 && end > 0 ) {
	xsegments[xp++] = Segment(points[beg].y, points[end].y, points[beg].x);
    }

    // sort by y
    sort( points, points + n, cmp_py );
    beg = end = -1;
    for ( int i = 0; i < n; ++i ) {
	if ( beg < 0 ) {
	    beg = i;
	    continue;
	}
	if ( end < 0 ) {
	    if ( points[i].y == points[beg].y ) {
		end = i;
	    } else {
		beg = i;
	    }
	} else {
	    if ( points[i].y == points[beg].y ) {
		end = i;
	    } else {
		ysegments[yp++] = Segment(points[beg].x, points[end].x, points[beg].y);
		beg = i;
		end = -1;
	    }
	}
    }
    if ( beg > 0 && end > 0 ) {
	ysegments[yp++] = Segment(points[beg].x, points[end].x, points[beg].y);
    }

    sort ( xsegments, xsegments + xp );
    sort ( ysegments, ysegments + yp );

    count = n;
    for ( int i = 0; i < xp; ++i ) {
	int ybeg = xsegments[i].beg;
	int yend = xsegments[i].end;
	Segment *plower = lower_bound( ysegments, ysegments + yp, Segment(0, 0, ybeg) );
	Segment *pupper = upper_bound( ysegments, ysegments + yp, Segment(0, 0, yend) );
	for (Segment *pcur = plower; pcur < pupper; ++pcur ) {
	    if ( pcur->beg < xsegments[i].loc && pcur->end > xsegments[i].loc 
		    && pcur->loc != xsegments[i].beg && pcur->loc != xsegments[i].end ) {
		count ++;
	    }
	}
    }

    cout << count << endl;

    return 0;
}

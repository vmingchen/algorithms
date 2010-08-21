/*
 * =====================================================================================
 *
 *       Filename:  squares.cpp
 *
 *    Description:  POJ problem 2002
 *
 *        Version:  1.0
 *        Created:  02/25/2009 04:57:37 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  BUAA.edu
 *
 *        Scan points from left to right and bottom to top. Use a unsigned long to 
 *        represent a point, where "x" coordinate occupies more signficant bits. 
 *        Deonte a square as (a,b,c,d), where a, b, c, and d are the four corners 
 *        clock-wise, and a is the on the left (with least x value). Then edge a--b
 *        must lie in the first quadrant. We only consider a--b to avoid duplicate
 *        counting.
 *
 * =====================================================================================
 */

#include	<iostream>
#include	<map>
#include	<iterator>

using namespace std;

typedef unsigned long point;

inline point make_pt(int x, int y) {
    point px = x + 20000;
    point py = y + 20000;
    point pt= 0;
    pt = (px << 16) | py;
    return pt;
}

inline int get_x(point pt) {
    return ((pt>>16) & 0x0000ffff) - 20000;
}

inline int get_y(point pt) {
    return (pt & 0x0000ffff) - 20000;
}

inline void find_cd(point a, point b, point &c, point &d) {
    int ax, ay, bx, by, cx, cy, dx, dy;
    ax = get_x(a); ay = get_y(a);
    bx = get_x(b); by = get_y(b);
    
    cx = bx + by - ay; 
    cy = by + ax - bx;
    c = make_pt(cx, cy);
    
    dx = ax + by - ay;
    dy = ay + ax - bx;
    d = make_pt(dx, dy);
}

inline bool is_ab(point a, point b) {
    return get_y(b) > get_y(a);
}

    int
main ( int argc, char *argv[] )
{
    int n, t, x, y;
    point a, b, c, d;
    map<point, int> points;
    map<point, int>::const_iterator ita, itb;

    while ( cin >> n ) {
	if ( n==0 ) break;
	points.clear();
	t = 0;
	for ( int i=0; i<n; i++ ) {
	    cin >> x >> y;
	    points.insert(make_pair(make_pt(x,y), i));
	}

	for ( ita=points.begin(); ita!=points.end(); ++ita ) {
	    a = ita->first;
	    for ( itb=ita, ++itb; itb!=points.end(); ++itb ) {
		b = itb->first;
		if ( is_ab(a,b) ) {
		    find_cd(a, b, c, d);
		    if ( points.find(c)!=points.end() 
			    && points.find(d)!=points.end() ) {
			++t;
		    }
		}
	    }
	}

	cout << t << endl;
    }

    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

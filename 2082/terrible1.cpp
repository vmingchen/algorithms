/*
 * =====================================================================================
 *
 *       Filename:  terrible.cpp
 *
 *    Description:  POJ 2082.Terrible Sets. Using a stack to record rectangles. If 
 *    		current rect is higher than the height of the rect atop the stack,
 *		push it into stack. Or else pop the stack until the stack is empty or
 *		the height of the rect atop the stack is lower than current rect; 
 *		accumulate the width of the popped rect to current rect and then push
 *		it into the stack.
 *
 *        Version:  1.0
 *        Created:  06/25/2009 10:34:28 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  BUAA.edu
 *
 * =====================================================================================
 */

#include	<iostream>
#include	<stack>

using namespace std;

class Rect {
public:
    int width, height;
    Rect(int w, int h) : width(w), height(h) {};
};

    int
main ( int argc, char *argv[] )
{
    int n, wh, w, h, nw, max;

    while ( cin >> n && n != -1 ) {
	stack<Rect> rects;
	max = 0;

	// read input
	for (int i=1; i<=n; ++i) {
	    cin >> w >> h;
	    
	    nw = 0;
	    while ( !rects.empty() && h < rects.top().height ) {
		nw += rects.top().width;
		wh = nw * rects.top().height;
		if ( wh > max ) max = wh;
		rects.pop();
	    } 
	    rects.push(Rect(nw+w, h));
	}

	nw = 0;
	while ( !rects.empty() ) {
	    nw += rects.top().width;
	    wh = nw * rects.top().height;
	    if ( wh > max ) max = wh;
	    rects.pop();
	}

	cout << max << endl;
    }

    return 0;
}	

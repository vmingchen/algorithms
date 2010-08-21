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


#include	<stdio.h>
#define 	MAXN	50000

int stack_w[MAXN];
int stack_h[MAXN];
int top = -1;

bool empty() { return top == -1; }
void clear() { top = -1; }
int top_w() { return stack_w[top]; }
int top_h() { return stack_h[top]; }
void pop() { if ( top >= 0 ) --top; }
void push(int w, int h) {
    stack_w[++top] = w;
    stack_h[top] =h;
}

    int
main ( int argc, char *argv[] )
{
    int n, wh, w, h, nw, max;

    while ( scanf("%d", &n) && n != -1 ) {
	max = 0;
	clear();

	while ( n-- > 0 ) {
	    scanf("%d %d", &w, &h);
	    nw = 0;
	    while ( !empty() && h < top_h() ) {
		nw += top_w();
		wh = nw * top_h();
		if ( wh > max ) max = wh;
		pop();
	    } 
	    push(w+nw, h);
	}

	nw = 0;
	while ( !empty() ) {
	    nw += top_w();
	    wh = nw * top_h();
	    if ( wh > max ) max = wh;
	    pop();
	}

	printf("%d\n", max);
    }

    return 0;
}	

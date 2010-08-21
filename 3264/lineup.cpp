/*
 * =====================================================================================
 *
 *       Filename:  lineup.cpp
 *
 *    Description:  POJ 3264 Segment tree
 *
 *        Version:  1.0
 *        Created:  07/31/2009 10:25:11 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  BUAA.edu
 *
 * =====================================================================================
 */


#include	<iostream>

using namespace std;

const int MAXN = 50000;
const int MAXQ = 200000;
const int MAXH = 1000000;

typedef struct {
    int left, right, max, min;
} Node;

Node tree[MAXN*10+1];
int heights[MAXN+1];
int N, Q;

void build(int pos, int left, int right)
{
    tree[pos].left = left;
    tree[pos].right = right;
    if ( left != right ) {
	int mid = ((right - left) >> 1) + left;
	build(pos<<1, left, mid);
	build((pos<<1)+1, mid+1, right);
    }
}

void calculate(int pos, int *pmax, int *pmin)
{
    if ( tree[pos].left == tree[pos].right ) {
	tree[pos].max = tree[pos].min = heights[tree[pos].left];
    } else {
	int lmax, lmin, rmax, rmin;
	calculate(pos<<1, &lmax, &lmin);
	calculate((pos<<1)+1, &rmax, &rmin);
	tree[pos].max = rmax > lmax ? rmax : lmax;
	tree[pos].min = rmin < lmin ? rmin : lmin;
    }
    *pmax = tree[pos].max;
    *pmin = tree[pos].min;
}

void query(int pos, int left, int right, int *pmax, int *pmin)
{
    if ( tree[pos].left == left && tree[pos].right == right ) {
	*pmax = tree[pos].max;
	*pmin = tree[pos].min;
    } else {
	int mid = ((tree[pos].right - tree[pos].left) >> 1) + tree[pos].left;
	if ( mid >= right ) {
	    query(pos<<1, left, right, pmax, pmin);
	} else if ( mid+1 <= left ) {
	    query((pos<<1)+1, left, right, pmax, pmin);
	} else {
	    int lmax, lmin, rmax, rmin;
	    query(pos<<1, left, mid, &lmax, &lmin);
	    query((pos<<1)+1, mid+1, right, &rmax, &rmin);
	    *pmax = lmax > rmax ? lmax : rmax;
	    *pmin = lmin < rmin ? lmin : rmin;
	}
    }
}

int main()
{
    cin >> N >> Q;
    for ( int n = 1; n <= N; ++n ) cin >> heights[n];
    build(1, 1, N);
    int max, min;
    calculate(1, &max, &min);
    for ( int q = 0; q < Q; ++q ) {
	int l, r;
	cin >> l >> r;
	query(1, l, r, &max, &min);
	cout << (max - min) << endl;
    }
    return 0;
}

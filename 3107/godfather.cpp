/*
 * =====================================================================================
 *
 *       Filename:  godfather.cpp
 *
 *    Description:  POJ 3107
 *
 *        Version:  1.0
 *        Created:  10/14/2010 05:44:07 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chenming), chenming@sohu-rd.com
 *        Company:  imeresearch@sogou
 *
 * =====================================================================================
 */


#include	<cstdio>
#include	<algorithm>

using namespace std;

const int MAXN = 50000;

struct Edge {
    int a, b;
};

int n;
int len[MAXN], cur[MAXN], beg[MAXN], targets[2*MAXN], weights[2*MAXN], topos[2*MAXN];
Edge edges[MAXN];

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
    int
main ( int argc, char *argv[] )
{ 
    scanf("%d", &n);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        edges[i].a = --a;
        edges[i].b = --b;
        ++len[a];
        ++len[b];
    }

    for (int i = 1; i < n; ++i) cur[i] = beg[i] = len[i-1] + beg[i-1];
    for (int i = 0; i < n-1; ++i) {
        int posa = cur[edges[i].a]++;
        int posb = cur[edges[i].b]++;
        targets[posa] = edges[i].b;
        targets[posb] = edges[i].a;
        topos[posa] = posb;
        topos[posb] = posa;
    }

    int stack[MAXN], count[MAXN], pos[MAXN], trace[MAXN], sp = 0;

    stack[sp] = 0;
    pos[sp] = 0;
    count[0] = 1;

    // depth-first visit traversal, stack operations
    while ( sp >= 0 ) {
        int src = stack[sp];
        int parent = sp > 0 ? stack[sp-1] : -1;
        if ( pos[sp] < len[src] && targets[beg[src]+pos[sp]] == parent ) ++pos[sp];
        if ( pos[sp] < len[src] ) {
            stack[sp+1] = targets[beg[src]+pos[sp]];
            trace[sp+1] = beg[src] + pos[sp];
            pos[sp+1] = 0;
            count[stack[sp+1]] = 1;
            ++pos[sp++];
        } else {
            if ( sp > 0 ) { 
                count[parent] += count[src];
                weights[trace[sp]] = count[src];
                weights[topos[trace[sp]]] = n - count[src];
            }
            --sp;
        }
    }

    int result[MAXN], numres = 0;
    int minsub = n;
    for (int i = 0; i < n; ++i) {
        int max = 0;
        for (int j = 0; j < len[i]; ++j) {
            if ( weights[beg[i]+j] > max ) 
                max = weights[beg[i]+j];
        }
        if ( max < minsub ) {
            numres = 0;
            minsub = max;
            result[numres++] = i;
        } else if ( max == minsub ) {
            result[numres++] = i;
        } 
    }

    sort(result, result+numres);
    printf("%d", result[0]+1);
    for (int i = 1; i < numres; ++i) 
        printf(" %d", result[i]+1);
    printf("\n");

    return 0;
}				/* ----------  end of function main  ---------- */

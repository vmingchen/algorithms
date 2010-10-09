/*
 * =====================================================================================
 *
 *       Filename:  area.cpp
 *
 *    Description:  POJ 2791. ACM ICPC 2005–2006, Northeastern European Regional Contest
 *
 *        Version:  1.0
 *        Created:  09/19/2010 09:56:21 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chenming), chenming@sohu-rd.com
 *        Company:  imeresearch@sogou
 *
 * =====================================================================================
 */


#include	<stdlib.h>
#include	<math.h>
#include	<cstdio>
#include	<assert.h>
#include	<algorithm>

using namespace std;

const int MAXM = 101;

class Chimeny{
public:
    char shape;
    int x, y; 
}; 

Chimeny chimneys[MAXM];
double viewpoint;
double intersections[MAXM][MAXM];
// further[i][j] is true when chimneys[i] is further away than chimneys[j] from their
// intersections[i][j] with x-axis
bool further[MAXM][MAXM];       


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  toleft
 *  Description:  check if chimneys[i] is to the left of chimneys[j] from current viewpoint
 * =====================================================================================
 */
    bool
toleft ( int i, int j )
{
    if ( i == j ) return false;
    if ( chimneys[i].y == chimneys[j].y ) return chimneys[i].x < chimneys[j].x;
    return (viewpoint < intersections[i][j]) ? further[i][j] : further[j][i]; 
}		/* -----  end of function toleft  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  intersect
 *  Description:  work out the intersection of the line from chimneys[i] to chimneys[j] 
 *  with the x-axis. 
 * =====================================================================================
 */
    double
intersect ( int i, int j )
{
    assert ( chimneys[i].y != chimneys[j].y ); 
    double xi = chimneys[i].x,
           yi = chimneys[i].y,
           xj = chimneys[j].x,
           yj = chimneys[j].y;
    return (yi*xj - yj*xi)/(yi - yj);
}		/* -----  end of function intersect  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  distance
 *  Description:  
 * =====================================================================================
 */
    inline double
distance ( double dx, double dy )
{
    return dx*dx + dy*dy;
}		/* -----  end of function distance  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  output
 *  Description:  
 * =====================================================================================
 */
    void
output ( double x )
{
    char result[128];
    sprintf(result, "%.6f", x); 
    int len = 0;
    while (result[len] != '\0') ++len;
    while (len > 0 && (result[len-1] == '0' || result[len-1] == '.')) { 
        --len;
        if ( result[len] == '.' ) break; 
    }
    if ( len == 0 ) {
        printf("0"); 
    } else {
        result[len] = '\0';
        printf("%s", result); 
    }
}		/* -----  end of function output  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
    int
main ( int argc, char *argv[] )
{ 
    int m;                              // number of chimneys 
    char target[MAXM];                  // the order of chimneys acclaimed by Nick
    int perspective[MAXM];              // order of chimneys from current viewpoint
    double areapoint[MAXM*MAXM+1];      // segment points of areas
    int numareapoint = 0;               // number of segment points 

    scanf("%d\n%s\n", &m ,target); 
    for (int i = 0; i < m; ++i) {
        scanf("\n%c %d %d", &(chimneys[i].shape), &(chimneys[i].x), &(chimneys[i].y)); 
        perspective[i] = i;
    }

    areapoint[numareapoint++] = 0.0;    // placeholder for left infinity
    for (int i = 0; i < m; ++i) {
        for (int j = i+1; j < m; ++j) {
            if ( chimneys[i].y == chimneys[j].y ) continue;
            double x0 = intersect(i, j);
            double di = distance(chimneys[i].x - x0, chimneys[i].y);
            double dj = distance(chimneys[j].x - x0, chimneys[j].y);
            intersections[i][j] = intersections[j][i] = x0;
            further[i][j] = (di > dj); 
            further[j][i] = (dj > di); 
            areapoint[numareapoint++] = x0; 
        }
    }

    sort( areapoint+1, areapoint + numareapoint );
    numareapoint = unique( areapoint+1, areapoint + numareapoint ) - areapoint; 

    int validareas[MAXM*MAXM+1], numvalid = 0;
    for (int i = 0; i < numareapoint; ++i) {
        if ( i == numareapoint - 1 ) viewpoint = areapoint[numareapoint-1] + 1.0;
        else if ( i == 0 ) viewpoint = areapoint[1] - 1.0;
        else viewpoint = (areapoint[i] + areapoint[i+1]) / 2; 

        sort( perspective, perspective + m, toleft );

        int j = 0;
        for ( ; j < m; ++j) {
            if ( chimneys[perspective[j]].shape != target[j] ) 
                break;
        }
        if ( j == m ) {
            validareas[numvalid++] = i;
        }
    }

    printf("%d\n", numvalid); 
    bool isfirst = true; 
    for (int i = 0; i < numvalid; ++i) {
        if ( !isfirst ) {
            printf(" "); 
        } else {
            isfirst = false; 
        }
        if ( validareas[i] == 0 && validareas[i] == numareapoint - 1 ) {
            printf("* *"); 
        } else if ( validareas[i] == 0 ) {
            printf("* "); output(areapoint[validareas[i]+1]); 
        } else if ( validareas[i] == numareapoint - 1 ) {
            output(areapoint[validareas[i]]); printf(" *"); 
        } else {
            output(areapoint[validareas[i]]); printf(" "); output(areapoint[validareas[i]+1]); 
        }
    }
    if ( !isfirst ) printf("\n"); 

    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

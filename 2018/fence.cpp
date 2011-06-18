/*
 * =====================================================================================
 *
 *       Filename:  fence.cpp
 *
 *    Description:  POJ 2018
 *
 *        Version:  1.0
 *        Created:  06/14/2009 09:21:14 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  BUAA.edu
 *
 * =====================================================================================
 */

#include	<stdio.h>
#include	<stdlib.h>

const int MAXN = 100001;

    int
main ( int argc, char *argv[] )
{
    int N, F, t, sum[MAXN] = {0};
    
    if ( scanf("%d %d", &N, &F) != EOF ) {
        for ( int i=1; i<=N; ++i ) {
            scanf("%d", &t);
            sum[i] = sum[i-1] + t;
        }
        if (N < 3) { 
            if (N == 1) {
                printf("%d\n", 1000*sum[1]);
            } else {
                if (F == 1) {
                    int a = sum[1], b = sum[2] - sum[1];
                    printf("%d\n", 1000*(a > b ? a : b));
                } else {
                    printf("%d\n", 1000*sum[2]/2);
                }
            }
            return 0;
        }

        double bestavg = sum[F]/((double)F);
        int bestbeg = 0, bestend = F;

        // maintain a down-convex hull of check points
        int chl = 0;                    // left boundary of the hull to check
        for(int i=F+1; i<=N; ++i) {
            int chr = i-F;              // right boundary of the hull to check
            double avg_r = (sum[i]-sum[chr])/(double)(i-chr);
            double avg_l = (sum[i]-sum[chl])/(double)(i-chl);
            if (avg_r > avg_l) {
                // chr will no longer be a check point for the best answer
                // then the hull to check shrink to a point
                chl = chr;      
                if (avg_r > bestavg) {
                    bestavg = avg_r;
                    bestbeg = chr;
                    bestend = i;
                }
            } else {
                // chr is an inner point of the hull, just ignore it
                if (avg_l > bestavg) {
                    bestavg = avg_l;
                    bestbeg = chl;
                    bestend = i;
                }
            }
        }
        printf("%d\n", 1000*(sum[bestend] - sum[bestbeg])/(bestend - bestbeg));
    }

    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

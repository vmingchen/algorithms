/*
 * =====================================================================================
 *
 *       Filename:  pyramids.cpp
 *
 *    Description:  POJ 2795. pre-order visit of tree. Dynamic Programming. 
 *
 *        Version:  1.0
 *        Created:  09/22/2010 08:56:37 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chenming), chenming@sohu-rd.com
 *        Company:  imeresearch@sogou
 *
 * =====================================================================================
 */

#include	<stdio.h>
#include	<string.h>

using namespace std;

const int MAXL = 301;
const int BASE = 1000000000; 

char sequence[MAXL];            // output of robot
int counts[MAXL][MAXL];         // counts[i][j] is the number of possibility for subsequence [i,j]

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
    int
main ( int argc, char *argv[] )
{ 
    while ( scanf("%s\n", sequence) != EOF ) {
        memset(counts, 0, MAXL*MAXL*sizeof(int)); 
        int len = strlen(sequence);
        if ( len % 2 == 0 || sequence[0] != sequence[len-1] ) { 
            printf("0\n"); 
            continue;
        }
        for (int i = 0; i < len; ++i) counts[i][i] = 1; 
        for (int l = 3; l <= len; l += 2) {
            for (int i = 0; i+l <= len; ++i) {
                int j = i+l-1; 
                if ( sequence[i] == sequence[j] ) {
                    for (int m = 3; m < l; m += 2) {            // children >= 2 
                        if ( sequence[i] == sequence[i+m-1] ) { 
                            counts[i][j] = (counts[i][j] + ((long long)counts[i+1][i+m-2])*counts[i+m-1][j]) % BASE;
                        }
                    }                                   
                    counts[i][j] = (counts[i][j] + ((long long)counts[i+1][j-1])) % BASE; // children == 1
                }
            }
        }
        printf("%d\n", counts[0][len-1]); 
    }
    return 0;
}				/* ----------  end of function main  ---------- */

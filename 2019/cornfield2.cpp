/*
 * =====================================================================================
 *
 *       Filename:  cornfield2.cpp
 *
 *    Description:  POJ 2019
 *
 *        Version:  1.0
 *        Created:  06/15/2009 05:53:33 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  BUAA.edu
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;
#define NIL 250

int main()
{
        //freopen("test.txt","r",stdin);
        int map[260][260];
        int max[260][260];
        int min[260][260];
        int dif[260][260];
        int n, b, i, j, k, K, max1, min1;

        while( scanf("%d %d %d", &n, &b, &K) != EOF )
        {
                for(i=1; i<=n; i++)
                        for(j=1; j<=n; j++)
                                scanf("%d", &map[i][j]);

                for(i=1; i<=n; i++)
                {
                        for(j=1; j<=n; j++)
                        {
                                max1 = -NIL;
                                min1 = NIL;
                                for(k=i; k<i+b; k++)
                                {
                                        if(map[k][j] > max1)max1 = map[k][j];
                                        if(map[k][j] < min1)min1 = map[k][j];
                                }
                                max[i][j] = max1;
                                min[i][j] = min1;
                        }
                }

                for(i=1; i<=n; i++)
                {
                        for(j=1; j<=n; j++)
                        {
                                max1 = -NIL;
                                min1 = NIL;
                                for(k=j; k<j+b; k++)
                                {
                                        if(max[i][k] > max1)max1 = max[i][k];
                                        if(min[i][k] < min1)min1 = min[i][k];
                                }
                                dif[i][j] = max1 - min1;
                        }
                }

                while ( K-- )
                {
                        scanf("%d %d", &i, &j);
                        printf("%d\n", dif[i][j]);
                }
        }
        return 0;
}


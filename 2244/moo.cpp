/*
 * =====================================================================================
 *
 *       Filename:  moo.cpp
 *
 *    Description:  POJ 2244. Josephus Problem
 *
 *        Version:  1.0
 *        Created:  09/25/2010 11:27:28 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chenming), chenming@sohu-rd.com
 *        Company:  imeresearch@sogou
 *
 * =====================================================================================
 */

#include	<vector>
#include	<iostream>

using namespace std;

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
    int
main ( int argc, char *argv[] )
{ 
    int results[150];
    for (int i = 3; i < 150; ++i) {
        int m = 2;
        while (true) {
            int idx = 0;
            vector<int> cities(i);
            for (int j = 0; j < i; ++j) cities[j] = j+1;
            while (cities.size() > 1) {
                if ( cities[idx] == 2 ) break;
                cities.erase(cities.begin() + idx);
                idx = (idx + m - 1) % cities.size();
            }
            if ( cities.size() == 1 && cities[0] == 2 ) break;
            ++m;
        }
        results[i] = m;
    }

    int c;
    while ( cin >> c && c != 0 ) 
        cout << results[c] << endl;
    return 0;
}				/* ----------  end of function main  ---------- */

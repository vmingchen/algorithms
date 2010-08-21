/*
 * =====================================================================================
 *
 *       Filename:  grade.cpp
 *
 *    Description:  POJ 3666. Making the Grade. Dynamic Programming.
 *
 *        Version:  1.0
 *        Created:  06/26/2009 03:39:59 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  BUAA.edu
 *
 * =====================================================================================
 */


#include	<iostream>
#include	<set>
#include	<vector>

using namespace std;

inline int cost(int a, int b) 
{
    return a>b ? a-b : b-a;
}

    int
main ( int argc, char *argv[] )
{
    set<int> as;
    set<int>::reverse_iterator rit;
    set<int>::iterator it, it2;
    int n, min, k;

    if ( cin >> n ) {
	vector<int> av(n, 0), fv(n, 0), fv2(n, 0);
	for (int i=0; i<n; ++i) {
	    cin >> av[i];
	    as.insert(av[i]);
	}
	for (int i=0; i<n; ++i) {
	    min = 1000000000;
	    for (it=as.begin(), k=0; it != as.end(); ++it, ++k) {
		if ( fv[k] < min ) min = fv[k];
		fv2[k] = min + cost(av[i], *it);
	    }
	    for (it=as.begin(), k=0; it != as.end(); ++it, ++k) 
		fv[k] = fv2[k];
	}
	min = 1000000000;
	for (it=as.begin(),k=0; it != as.end(); ++it, ++k) {
	    if ( fv[k] < min ) min = fv[k];
	}
	cout << min << endl;
    }

    return 0;
}	

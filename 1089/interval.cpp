/*
 * =====================================================================================
 *
 *       Filename:  interval.cpp
 *
 *    Description:  POJ 1089. Intervals
 *
 *        Version:  1.0
 *        Created:  06/25/2009 06:17:14 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  BUAA.edu
 *
 * =====================================================================================
 */


#include	<iostream>
#include	<algorithm>
#include	<vector>

using namespace std;

class Interval {
public:
    int beg, end;
    Interval(int b, int e) : beg(b), end(e) {};
    bool operator< (const Interval &other) const {
	if ( beg == other.beg ) return end < other.end;
	else return beg < other.beg;
    };
};

    int
main ( int argc, char *argv[] )
{
    int n, N, b, e;
    vector<Interval> intervals;
    vector<Interval>::iterator it;

    if ( cin >> N ) {
	for (n=0; n<N; ++n) {
	    cin >> b >> e;
	    intervals.push_back(Interval(b, e));
	}
    }

    sort(intervals.begin(), intervals.end());

    for ( it=intervals.begin(), b=it->beg, e=it->end; 
	    it!=intervals.end(); ++it ) {
//	cout << it->beg << " " << it->end << endl;
	if ( it->beg > e ) {
	    cout << b << " " << e << endl;
	    b = it->beg;
	    e = it->end;
	    continue;
	}
	if ( it->end > e )
	    e = it->end;
    }
    cout << b << " " << e << endl;

    return 0;
}				/* ----------  end of function main  ---------- */

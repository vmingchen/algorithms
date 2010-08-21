/*
 * =====================================================================================
 *
 *       Filename:  tryouts.cpp
 *
 *    Description:  POJ problem 2008
 *
 *        Version:  1.0
 *        Created:  02/25/2009 11:34:53 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  BUAA.edu
 *
 * =====================================================================================
 */

#include	<iostream>
#include	<vector>
#include	<algorithm>


using namespace std;

class Calve {
public:
    int height;
    int weight;
    Calve(int h=0, int w=0) : height(h), weight(w) {};
};

bool compare_calve(const Calve &c1, const Calve &c2) {
    return c1.height < c2.weight;
}

    int
main ( int argc, char *argv[] )
{
    int n, a, b, c, h, w, t, max=0;
    vector<Calve> calves;
    vector<Calve>::const_iterator ith, itw, it;

    cin >> n >> a >> b >> c;
    for ( int i=0; i<n; i++ ) {
	cin >> h >> w;
	calves.push_back(Calve(h,w));
    }

    sort(calves.begin(), calves.end(), compare_calve);

    for ( ith=calves.begin(); ith!=calves.end(); ++ith ) {
	if ( calves.end()-ith < max ) break;
	h = ith->height; 
	for ( itw=ith; itw!=calves.end(); ++itw ) {
	    if ( itw->weight > ith->weight ) continue;
	    if ( (itw->height - h)*a > c ) continue;
	    w = itw->weight;
	    if ( (ith->weight - w)*b > c ) continue;
	    t = 0;
	    for ( it=ith; it!=calves.end(); ++it ) {
		if ( it->weight < w ) continue;
		int l1 = (it->height - h) * a;
		if ( l1 > c ) break;
		int l2 = (it->weight - w) * b;
		if ( l1 + l2 <= c ) ++t;
	    }
	    if ( t > max ) max = t;
	}
    }

    cout << max << endl;

    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

/*
 * =====================================================================================
 *
 *       Filename:  dna.cpp
 *
 *    Description:  POJ 1007
 *      
 *        Version:  1.0
 *        Created:  04/24/2009 07:17:28 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  BUAA.edu
 *
 * =====================================================================================
 */

#include	<iostream>
#include	<string>
#include	<algorithm>

using namespace std;

const int MAXM = 101;

class DNA {
public:
    string str;
    int disorder;
};

bool operator< (const DNA &d1, const DNA &d2)
{
    return d1.disorder < d2.disorder 
	    || (d1.disorder == d2.disorder && d1.str < d2.str);
}

int main()
{
    int cmap[26] = {-1};
    cmap['A'-'A'] = 0;
    cmap['C'-'A'] = 1;
    cmap['G'-'A'] = 2;
    cmap['T'-'A'] = 3;

    int n, m;
    cin >> n >> m;

    DNA dna[MAXM];
    for ( int i = 0; i < m; ++i ) {
	cin >> dna[i].str;
	dna[i].disorder = 0;
	int count[4] = {0};
	for ( int j = 0; j < n; ++j ) {
	    int idx = cmap[dna[i].str[j]-'A'];
	    count[idx]++;
	    for ( int k = idx+1; k < 4; ++k )
		dna[i].disorder += count[k];
	}
    }

    sort( dna, dna + m );

    for ( int i = 0; i < m; ++i ) 
	cout << dna[i].str << endl;

    return 0;
}

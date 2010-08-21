#include	<iostream>

using namespace std;

const double DISTANCE = 4.5, LONGEST = 100000000;

int main()
{
    int N, Vi, Ti;
    while ( cin >> N && N != 0 ) {
	double time = LONGEST;
	for ( int n = 0; n < N; ++n ) {
	    cin >> Vi >> Ti;
	    if ( Ti < 0 ) continue;
	    double tm = 3600*DISTANCE/Vi + Ti;
	    int itm = (int)tm;
	    if ( itm < tm ) itm++;
	    if ( itm < time ) time = itm;
	}
	cout << time << endl;
    }
    return 0;
}

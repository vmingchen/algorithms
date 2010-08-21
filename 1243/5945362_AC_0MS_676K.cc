#include	<iostream>

using namespace std;

const int MAXG = 31, MAXL = 31;

int main()
{
    int G, L, N[MAXG][MAXL] = {{0}};
    for ( int g = 1; g < MAXG; ++g ) N[g][0] = g;
    for ( int l = 0; l < MAXL; ++l ) N[1][l] = 1;
    for ( int g = 2; g < MAXG; ++g ) {
	for ( int l = 1; l < MAXL; ++l ) {
	    N[g][l] = N[g-1][l-1] + 1 + N[g-1][l];
	}
    }
    for ( int i = 1; cin >> G >> L && (G != 0 || L != 0); ++i ) {
	cout << "Case " << i << ": " << N[G][L] << endl;
    }
    return 0;
}

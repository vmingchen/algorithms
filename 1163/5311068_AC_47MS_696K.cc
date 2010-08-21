#include	<iostream>

using namespace std;

const int MAX_N = 350;

    int
main ( int argc, char *argv[] )
{
    int n, balls[MAX_N], highest[MAX_N], final=0;

    for (int i=0; i<MAX_N; ++i) highest[i] = balls[i] = 0;
    
    cin >> n;
    for (int i=0; i<n; ++i) {
	for (int j=0; j<=i; ++j) cin >> balls[j];
	if ( i >= 1 ) highest[i] = highest[i-1] + balls[i];
	for (int j=i-1; j>0; --j) {
	    int a = highest[j-1] + balls[j];
	    int b = highest[j] + balls[j];
	    highest[j] = a > b ? a : b;
	}
	highest[0] = highest[0] + balls[0];
    }

    for (int i=0; i<n; ++i) {
	if ( highest[i] > final ) 
	    final = highest[i];
    }

    cout << final << endl;

    return 0;
}			

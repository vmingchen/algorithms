#include	<iostream>

using namespace std;

const int MAXN = 45;

int main()
{
    int results[MAXN+1], num, val;
    results[0] = 1;
    results[1] = 2;
    for ( int i = 2; i <= MAXN; ++i ) {
	results[i] = results[i-1] + results[i-2];
    }

    cin >> num; 
    for ( int i = 1; i <= num; ++ i ) {
	cin >> val;
	if ( i != 1 ) cout << endl;
	cout << "Scenario #" << i << ":" << endl;
	cout << results[val] << endl;
    }
    return 0;
}

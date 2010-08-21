#include	<iostream>

using namespace std;

const int MAXN = 100003;

int N, emotions[MAXN], 
    pre[MAXN], 		// position of the closest smaller number on the left
    pos[MAXN];		// position of the closest smaller number on the right

int main()
{
    cin >> N;
    for ( int n = 1; n <= N; ++n ) 
	cin >> emotions[n];
    emotions[0] = emotions[N+1] = -1;

    for ( int n = 1; n <= N; ++n ) {
	int l = n-1;
	while ( emotions[l] >= emotions[n] ) l = pre[l];
	pre[n] = l;
    }

    for ( int n = N; n >= 1; --n ) {
	int r = n+1;
	while ( emotions[r] >= emotions[n] ) r = pos[r];
	pos[n] = r;
    }

    long long cumsum[MAXN] = {0};
    for ( int n = 1; n <= N; ++n ) 
	cumsum[n] = cumsum[n-1] + emotions[n];

    int lb, rb;
    long long ans = 0;
    for ( int n = 1; n <= N; ++n ) {
	long long tmp = emotions[n] * (cumsum[pos[n]-1] - cumsum[pre[n]]);
	if ( tmp > ans ) {
	    ans = tmp;
	    lb = pre[n]+1;
	    rb = pos[n]-1;
	}
    }

    cout << ans << endl;
    cout << lb << " " << rb << endl;

    return 0;
}

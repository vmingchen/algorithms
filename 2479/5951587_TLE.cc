#include	<stdio.h>

const int MAXN = 50001;

int cumsum[MAXN], N, T;

int maxsum(int b, int e)
{
    int res = -10001;
    for ( int i = b; i < e; ++i ) 
	if ( cumsum[i] > res )
	    res = cumsum[i];
    return res - cumsum[b-1];
}

int main()
{
    scanf("%d", &T);
    for ( int t = 0; t < T; ++t ) {
	int an, res = 0;
	scanf("%d", &N);
	cumsum[0] = 0;
	for ( int n = 1; n <= N; ++n ) {
	    scanf("%d", &an);
	    cumsum[n] = cumsum[n-1] + an;
	}

	for ( int n = 2; n <= N; ++n ) {
	    int nres = maxsum( 1, n ) + maxsum( n, N+1 );
	    if ( nres > res ) res = nres;
	}

	printf("%d\n", res);
    }
    return 0;
}

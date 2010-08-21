#include	<stdio.h>

const int MAXN = 50001;

int elem[MAXN], maxsum[MAXN], N, T;

int main()
{
    scanf("%d", &T); maxsum[0] = 0;
    for ( int t = 0; t < T; ++t ) {
	int res = -10001;
	scanf("%d", &N);
	for ( int n = 1; n <= N; ++n ) {
	    scanf("%d", elem+n);
	}

	// scan from left to right
	int maxendhere = -10001, maxsofar = -10001; 
	for ( int n = 1; n <= N; ++n ) {
	    maxendhere =  maxendhere > 0 ? maxendhere + elem[n] : elem[n];
	    if ( maxendhere > maxsofar ) maxsofar = maxendhere;
	    maxsum[n] = maxsofar;
	}

	// scan from right to left
	maxendhere = -10001, maxsofar = -10001; 
	for ( int n = N; n >= 1; --n ) {
	    maxendhere =  maxendhere > 0 ? maxendhere + elem[n] : elem[n];
	    if ( maxendhere > maxsofar ) maxsofar = maxendhere;
	    if ( maxsofar + maxsum[n-1] > res ) res = maxsofar + maxsum[n-1];
	}

	printf("%d\n", res);
    }
    return 0;
}

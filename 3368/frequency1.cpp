/*
 * =====================================================================================
 *
 *       Filename:  frequency.cpp
 *
 *    Description:  POJ 3368 RMQ
 *
 *        Version:  1.0
 *        Created:  08/01/2009 07:44:16 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  BUAA.edu
 *
 * =====================================================================================
 */


#include	<iostream>
#include	<math.h>

using namespace std;

const int MAXN = 100000;
const int PINF = 100001;
const int NINF = -100001;

int N, Q, U;		// U for number of unique numbers
int sequence[MAXN+1],	// the original sequence of integer
    values[MAXN+1], 	// the values of unique integers
    frequency[MAXN+1], 	// frequency[i] of the unique integer values[i]
    cumsum[MAXN+1], 	// cummulative sum of frequency[i]
    mf[MAXN][15];	// mf[i][t] is the answer for query between i and i+2^t

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

int key(int index) 
{
    int st = 1, end = U;
    while ( st != end ) {
	int mid = ((end-st)>>1) + st;
	if ( values[mid] == sequence[index] ) {
	    return mid;
	} 
	if ( cumsum[mid] < index ) { 
	    st = mid + 1;
	} else {
	    end = mid;
	}
    }
    return st;
}

int fmf(int index) 
{
    int k = key(index); 
    return index - cumsum[k-1];
}

int bmf(int index)
{
    int k = key(index);
    return cumsum[k] - index + 1;
}

int mmf(int st, int end, int mid)
{
    if ( sequence[mid] != sequence[mid+1] ) 
	return 0;
    int mf1 = fmf(mid);
    int mf2 = bmf(mid+1);
    int len = 0;
    len += min(fmf(mid), mid - st + 1);
    len += min(bmf(mid+1), end - mid);
    return len;
}

void rmq_init()
{
    for (int i=1; i <= N; ++i) mf[i][0] = 1;
    int m = floor(log_2((double)N));
    for (int j=1; j <= m; ++j) {
	for (int i=N; i > 0; --i) {
	    mf[i][j] = mf[i][j-1];
	    int mid = i + (1<<(j-1)) - 1;
	    if ( mid < N ) {
		int mx = max(mf[i][j-1], mf[mid+1][j-1]);
		mf[i][j] = max(mx, mmf(i, mid, i+(1<<j)-1));
	    }
	}
    }
}

int rmq_query(int st, int end)
{
    int m = floor(log_2((double)N));
}

int main()
{

    while ( cin >> N && N != 0 ) {
	cin >> Q;
	frequency[0] = cumsum[0] = U = 0;
	sequence[0] = NINF;
	for (int n=1; n <= N; ++n) {
	    cin >> sequence[n];
	    if ( sequence[n] != sequence[n-1] ) {
		cumsum[U] = cumsum[U-1] + frequency[U];
		values[++U] = sequence[n];
		frequency[U] = 1;
	    } else {
		++frequency[U];
	    }
	}

	for (int q=1; q <= Q; ++q) {
	    int st, end;
	    cin >> st >> end;
	    cout << rmq_query(st, end) << endl;
	}
    }
    
    return 0;
}

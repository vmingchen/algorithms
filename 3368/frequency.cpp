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
const int INF = 100001;

int N, Q, U;		// U for number of unique numbers
int sequence[MAXN+1],	// the original sequence of integer
    values[MAXN+1], 	// the values of unique integers
    frequency[MAXN+1], 	// frequency[i] of the unique integer values[i]
    cumsum[MAXN+1], 	// cummulative sum of frequency[i]
    mf[MAXN][17];	// mf[i][t] is the answer for query between i and i+2^t

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

void rmq_init()
{
    for (int i=1; i <= U; ++i) mf[i][0] = frequency[i];
    int m = floor(log((double)U)/log(2));
    for (int j=1; j <= m; ++j) {
	for (int i=1; (i + (1<<(j-1))) <= U; ++i) {
	    mf[i][j] = max(mf[i][j-1], mf[i+(1<<(j-1))][j-1]);
	}
    }
}

int rmq_query(int st, int end)
{
    int a = key(st);
    int b = key(end);
    int an = a + 1;
    int bp = b - 1;
    int res = 0;
    if ( bp >= an ) {
	int m = floor(log((double)(bp-an+1))/log(2));
	res = max(mf[an][m], mf[bp-(1<<m)+1][m]);
    }
    if ( a == b ) {
	return (end-st+1);
    } else {
	res = max(res, cumsum[a]-st+1);
	res = max(res, end-cumsum[bp]);
    }
    return res;
}

int main()
{

    while ( cin >> N && N != 0 ) {
	cin >> Q;
	frequency[0] = cumsum[0] = U = 0;
	sequence[0] = INF;
	int sum = 0;
	for (int n=1; n <= N; ++n) {
	    cin >> sequence[n];
	    if ( sequence[n] != sequence[n-1] ) {
		sum += frequency[U];
		cumsum[U] = sum;
		values[++U] = sequence[n];
		frequency[U] = 1;
	    } else {
		++frequency[U];
	    }
	}

	rmq_init();

	for (int q=1; q <= Q; ++q) {
	    int st, end;
	    cin >> st >> end;
	    cout << rmq_query(st, end) << endl;
	}
    }
    
    return 0;
}

#include	<iostream>

using namespace std;

const int MAXV = 2000000001, MAXM = 30000;

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

bool myless(int a, int b) { return a < b; }
bool mylarger(int a, int b) { return a > b; }

class Heap {
    public:
	int data[MAXM+1], ptr;
	bool (*func)(int, int);
	Heap(bool (*f)(int, int)) : func(f), ptr(1) { }
	int top() { return data[1]; }
	void add(int val) {
	    data[ptr] = val;
	    int child = ptr, parent = ptr/2;
	    while ( parent > 0 && func( data[child], data[parent] ) ) {
		swap( data[parent], data[child] );
		child = parent;
		parent /= 2;
	    }
	    ptr++;
	}
	int update(int newVal) {
	    int oldVal = data[1];
	    data[1] = newVal;
	    for ( int i = 1; i < ptr; ) {
		int pm = i, lc = i*2, rc = i*2 + 1;
		if ( lc < ptr && func(data[lc], data[pm]) ) pm = lc;
		if ( rc < ptr && func(data[rc], data[pm]) ) pm = rc;
		if ( pm == i ) break;
		swap( data[pm], data[i] );
		i = pm;
	    }
	    return oldVal;
	}
	int size() { return ptr - 1; }
};

int main()
{
    Heap mxHeap(mylarger), mnHeap(myless);
    int M, N, A[MAXM+1], Ai, ui;

    cin >> M >> N;
    for ( int m = 1; m <= M; ++m ) cin >> A[m];

    Ai = 1;
    for ( int i = 1; i <= N; ++i ) {
	cin >> ui;
	while ( Ai <= ui ) {
	    if ( mxHeap.size() > 0 && A[Ai] < mxHeap.top() ) {
		mnHeap.add( mxHeap.update( A[Ai] ) );
	    } else {
		mnHeap.add( A[Ai] );
	    }
	    Ai++;
	}
	int r = mnHeap.update( MAXV );
	mxHeap.add( r );
	cout << r << endl;
    }

    return 0;
}

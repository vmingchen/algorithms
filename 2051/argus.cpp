/*
 * =====================================================================================
 *
 *       Filename:  argus.cpp
 *
 *    Description:  POJ 2051
 *
 *        Version:  1.0
 *        Created:  07/12/2009 11:22:56 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  BUAA.edu
 *
 * =====================================================================================
 */


#include	<stdio.h>

using namespace std;

const int MAXL = 11;
const int MAXI = 1002;
const int MAXK = 10001;

class Instruction {
    public:
	int qnum;
	int period, time;
	const bool operator< (const Instruction & other) const {
	    if ( time != other.time ) 
		return time < other.time;
	    else
		return qnum < other.qnum;
	};
};

inline void swap(Instruction &ins1, Instruction &ins2) 
{
    Instruction inst;
    inst.qnum = ins1.qnum;
    inst.period = ins1.period;
    inst.time = ins1.time;
    ins1.qnum = ins2.qnum;
    ins1.period = ins2.period;
    ins1.time = ins2.time;
    ins2.qnum = inst.qnum;
    ins2.period = inst.period;
    ins2.time = inst.time;
}

int main()
{
    char str[MAXL];
    Instruction ins_heap[MAXI];
    int N, K, k;

    N = 0;
    while ( scanf("%s", str) && str[0] != '#' ) {
	if ( str[0] == 'R' ) {
	    int q;
	    int p;
	    scanf("%d %d", &q, &p);
	    ins_heap[++N].qnum = q;
	    ins_heap[N].period = p;
	    ins_heap[N].time = p;
	    while ( true ) {
		int pi = N >> 1;
		if ( pi < 1 || ins_heap[pi] < ins_heap[N] ) 
		    break;
		swap(ins_heap[pi], ins_heap[N]);
	    }
	}
    }
    ins_heap[N+1].qnum = 30001;
    ins_heap[N+1].period = 30000001;
    ins_heap[N+1].time = 30000001;
    scanf("%d", &K);

    k = 0;
    while ( true ) {
	if ( ++k > K ) break;
//	cout << ins_heap[1].qnum << endl;
	printf("%d\n", ins_heap[1].qnum);
	ins_heap[1].time += ins_heap[1].period;
	for (int pi=1; (pi<<1) <= N; ) {
	    int ci1 = pi << 1;
	    int ci2 = ci1 + 1;
	    if ( ins_heap[pi] < ins_heap[ci1] 
		    && ins_heap[pi] < ins_heap[ci2] ) 
		break;
	    if ( ins_heap[ci1] < ins_heap[ci2] ) {
		swap(ins_heap[ci1], ins_heap[pi]);
		pi = ci1;
	    } else {
		swap(ins_heap[ci2], ins_heap[pi]);
		pi = ci2;
	    }
	}
    }

    return 0;
}

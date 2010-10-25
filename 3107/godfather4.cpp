/*
 * =====================================================================================
 *
 *       Filename:  godfather.cpp
 *
 *    Description:  POJ 3107
 *
 *        Version:  1.0
 *        Created:  10/14/2010 05:44:07 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chenming), chenming@sohu-rd.com
 *        Company:  imeresearch@sogou
 *
 * =====================================================================================
 */


#include	<vector>
#include	<iostream>

using namespace std;

const int MAXN = 50000;

class Edge {
public:
    int target, weight, pos;
    Edge(int t, int w, int p) : target(t), weight(w), pos(p) {};
};

int n;
vector<Edge> comm[MAXN];


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  countsort
 *  Description:  
 * =====================================================================================
 */
    vector<int>
countsort ( const vector<int> &weights )
{
    vector<int> order(weights.size(), 0);
    vector<int> counter(n, 0);
    for (size_t i = 0; i < weights.size(); ++i) if ( weights[i] < n-1 ) ++counter[1+weights[i]];
    for (int i = 1; i < n; ++i) counter[i] += counter[i-1];
    for (size_t i = 0; i < weights.size(); ++i) order[counter[weights[i]]++] = i;
    return order;
}		/* -----  end of function countsort  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
    int
main ( int argc, char *argv[] )
{ 
    cin >> n;
    for (int i = 0; i < n-1; ++i) {
        int a, b, pa, pb;
        cin >> a >> b;
        --a; --b;
        pa = comm[a].size();
        pb = comm[b].size();
        comm[a].push_back(Edge(b, 0, pb));
        comm[b].push_back(Edge(a, 0, pa));
    }

    int stack[MAXN], weight[MAXN], sp = 0;
    size_t pos[MAXN], childpos[MAXN];

    stack[sp] = 0;
    pos[sp] = 0;
    weight[0] = 1;

    // depth-first visit traversal, stack operations
    while ( sp >= 0 ) {
        int id = stack[sp];
        if ( pos[sp] < comm[id].size() && sp > 0 && comm[id][pos[sp]].target == stack[sp-1] ) ++pos[sp];
        if ( pos[sp] < comm[id].size() ) {
            childpos[sp+1] = pos[sp];
            stack[sp+1] = comm[id][pos[sp]].target;
            if ( comm[id][pos[sp]].weight != 0 ) {
                pos[sp+1] = comm[stack[sp+1]].size();
                weight[stack[sp+1]] = comm[id][pos[sp]].weight;
            } else { 
                pos[sp+1] = 0;
                weight[stack[sp+1]] = 1;
            }
            ++pos[sp++];
        } else {
            if ( sp > 0 ) { 
                int source = stack[sp-1];
                weight[source] += weight[id];
                comm[source][childpos[sp]].weight = weight[id];
                int relpos = comm[source][childpos[sp]].pos;
                comm[id][relpos].weight = n - weight[id];
            }
            --sp;
        }
    }

    vector<int> result;
    int minsub = n;
    for (int i = 0; i < n; ++i) {
        int max = 0;
        for (size_t j = 0; j < comm[i].size(); ++j) {
            if ( comm[i][j].weight > max ) 
                max = comm[i][j].weight;
        }
        if ( max < minsub ) {
            result.clear();
            result.push_back(i);
            minsub = max;
        } else if ( max == minsub ) {
            result.push_back(i);
        } 
    }

    vector<int> sorted = countsort(result); 
    cout << (result[sorted[0]] + 1); 
    for (size_t i = 1; i < sorted.size(); ++i) 
        cout << " " << (result[sorted[i]] + 1); 
    cout << endl;

    return 0;
}				/* ----------  end of function main  ---------- */

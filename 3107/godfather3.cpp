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
    int target, weight;
    Edge(int t, int w) : target(t), weight(w) {};
};

int n;
vector<Edge> comm[MAXN];
int parent[MAXN], stack[MAXN], weight[MAXN];
size_t pos[MAXN], childpos[MAXN];


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
 *         Name:  isgodfather
 *  Description:  
 * =====================================================================================
 */
    int
isgodfather ( int godfather, int minsub )
{

    int sp = 0;
    stack[sp] = godfather;
    pos[sp] = 0;
    weight[godfather] = 1;
    parent[godfather] = -1;

    int max = 0;
    while ( sp >= 0 ) {
        int id = stack[sp];
        if ( id != godfather && weight[id] > minsub ) return n;
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
                parent[id] = stack[sp-1];
                weight[parent[id]] += weight[id];
                comm[parent[id]][childpos[sp]].weight = weight[id];
                if ( parent[id] == godfather && weight[id] > max ) max = weight[id];
            }
            --sp;
        }
    }

    return max; 
}		/* -----  end of function isgodfather  ----- */

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
        int a, b;
        cin >> a >> b;
        --a; --b;
        comm[a].push_back(Edge(b, 0));
        comm[b].push_back(Edge(a, 0));
    }

    vector<int> result;
    int minsub = n;
    for (int i = 0; i < n; ++i) {
        int res = isgodfather(i, minsub);
        if ( res > minsub ) continue;
        else if ( res == minsub ) result.push_back(i);
        else { minsub = res; result.clear(); result.push_back(i); }
    }

    vector<int> sorted = countsort(result); 
    cout << (result[sorted[0]] + 1); 
    for (size_t i = 1; i < sorted.size(); ++i) 
        cout << " " << (result[sorted[i]] + 1); 
    cout << endl;

    return 0;
}				/* ----------  end of function main  ---------- */

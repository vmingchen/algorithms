/*
 * =====================================================================================
 *
 *       Filename:  strategic.cpp
 *
 *    Description:  POJ 1463. Tree DP
 *
 *        Version:  1.0
 *        Created:  10/09/2010 08:57:32 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chenming), chenming@sohu-rd.com
 *        Company:  imeresearch@sogou
 *
 * =====================================================================================
 */

#include	<stdio.h>
#include	<vector>

using namespace std; 

class Node {
public:
    int id, parent;
    Node(int i, int p) : id(i), parent(p) {}
    Node() : id(-1), parent(-1) {}
};

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  addnode
 *  Description:  
 * =====================================================================================
 */
void addnode( size_t sz, int (*pathes)[1501], vector<Node> &nodes, vector<int> &newid )
{
    nodes.push_back(Node(0, -1)); 
    newid[0] = 0;
    for (size_t cur = 0; cur < nodes.size() && nodes.size() < sz; ++cur) {
        int id = nodes[cur].id;
        for (int i = 1; i <= pathes[id][0]; ++i) {
            if ( newid[pathes[id][i]] == -1 ) {
                int nid = nodes.size();
                nodes.push_back(Node(pathes[id][i], id));
                newid[pathes[id][i]] = nid;
            }
        }
    }
}		/* -----  end of function addnode  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  findmin
 *  Description:  
 * =====================================================================================
 */
int findmin( int (*pathes)[1501], vector<Node> &nodes, vector<int> &newid )
{
    int n = nodes.size();
    int states[1500][2]; 

    for (int i = n-1; i >= 0; --i) {
        states[i][0] = 0;
        states[i][1] = 1; 
        for (int j = 1; j <= pathes[i][0]; ++j) {
            if ( pathes[i][j] == nodes[i].parent ) continue;
            int c = newid[pathes[i][j]]; 
            states[i][0] += states[c][1];
            states[i][1] += (states[c][0] < states[c][1] ? states[c][0] : states[c][1]);
        }
    }

    return (states[0][0] < states[0][1] ? states[0][0] : states[0][1]);
}		/* -----  end of function findmin  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
    int
main ( int argc, char *argv[] )
{ 
    int n;
    int pathes[1500][1501]; 
    while ( scanf("%d", &n) != EOF ) {
        int id, num, tmp; 
        vector<Node> nodes; 
        vector<int> newid(n, -1);
        for (int i = 0; i < n; ++i) pathes[i][0] = 0;
        for (int i = 0; i < n; ++i) { 
            scanf("%d:(%d)", &id, &num);
            for (int j = 0; j < num; ++j) { 
                scanf(" %d", &tmp); 
                pathes[id][++pathes[id][0]] = tmp;
                pathes[tmp][++pathes[tmp][0]] = id;
            }
        }
        if ( n == 1 ) {
            printf("1\n");
            continue;
        }

        addnode(n, pathes, nodes, newid);
        printf("%d\n", findmin(pathes, nodes, newid));
    }
    return 0;
}				/* ----------  end of function main  ---------- */

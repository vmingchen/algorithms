/*
 * =====================================================================================
 *
 *       Filename:  phone.cpp
 *
 *    Description:  POJ 3630 Phone List
 *
 *        Version:  1.0
 *        Created:  07/21/2009 11:36:47 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  BUAA.edu
 *
 * =====================================================================================
 */


#include	<iostream>
#include	<cstring>

using namespace std;

const int MAXN = 11;
const int MAXNODE = 1100000;

typedef int PNode;
int nodes[MAXNODE];
int ni = 0;

inline PNode reset()
{
    memset(nodes, 0, sizeof(nodes));
    ni = 1;
    return 0;
}

inline PNode new_node()
{
    return 11 * (ni++);
}

inline PNode get_child(PNode pnode, int child) 
{
    return nodes[pnode + child + 1];
}

inline void set_child(PNode pnode, int child, PNode pchild) 
{
    nodes[pnode + child + 1] = pchild;
}

inline bool is_terminal(PNode pnode)
{
    return nodes[pnode] != 0;
}

inline void set_terminal(PNode pnode)
{
    nodes[pnode] = 1;
}

bool insert(PNode pnode, char *pstr)
{
    if ( is_terminal(pnode) ) return false;
    if ( *pstr == '\0' ) {
	set_terminal(pnode);
	return true;
    }
    int idx = *pstr++ - '0';
    if ( get_child(pnode, idx) == 0 ) {
	set_child(pnode, idx, new_node());
    } else if ( *pstr == '\0' ) {
	return false;
    }
    return insert(get_child(pnode, idx), pstr);
}

int main()
{
    int T, N;
    char str[MAXN];

    cin >> T;
    for (int t=0; t < T; ++t) {
	cin >> N;
	PNode proot = reset();
	bool result = true;
	for (int n=0; n < N; ++n) {
	    cin >> str;
	    if ( result == true && !insert(proot, str) ) {
		result = false;
	    }
	}
	cout << (result ? "YES" : "NO") << endl;
    }

    return 0;
}

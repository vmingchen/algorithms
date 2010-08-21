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

const int MAXN = 10001;
const int MAXNODE = 400000;

class Node {
public:
    bool terminal;
    Node *childern[10];
    Node() : terminal(false) {
	memset(childern, NULL, sizeof(childern));
    };
    void reset() {
	terminal = false;
	memset(childern, NULL, sizeof(childern));
    };
};

Node nodes[MAXNODE];
int ni = 0;

inline Node* new_node()
{
    Node *pnode = &nodes[ni++];
    pnode->reset();
    return pnode;
}

bool insert(Node *pnode, char *pstr)
{
    if ( pnode->terminal ) return false;
    if ( *pstr == '\0' ) {
	pnode->terminal = true;
	return true;
    }
    int idx = *pstr - '0';
    if ( pnode->childern[idx] == NULL ) {
	pnode->childern[idx] = new_node();
    }
    return insert(pnode->childern[idx], pstr+1);
}

int main()
{
    int T, N;
    char str[MAXN];

    cin >> T;
    for (int t=0; t < T; ++t) {
	cin >> N;
	ni = 0;
	Node *proot = new_node();
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

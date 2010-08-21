/*
 * =====================================================================================
 *
 *       Filename:  phone2.cpp
 *
 *    Description:  POJ 3630
 *
 *        Version:  1.0
 *        Created:  07/22/2009 12:31:45 AM
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

class Node {
public:
    bool terminal;
    Node *childern[10];
    Node() : terminal(false) {
	memset(childern, NULL, sizeof(childern));
    };
    ~Node() {
	for (int i=0; i<10; ++i) {
	    if ( childern[i] != NULL ) {
		delete childern[i];
		childern[i] = NULL;
	    }
	}
    };
};

bool insert(Node *pnode, char *pstr)
{
    if ( pnode->terminal ) return false;
    if ( *pstr == '\0' ) {
	pnode->terminal = true;
	return true;
    }
    int idx = *pstr - '0';
    if ( pnode->childern[idx] == NULL ) {
	pnode->childern[idx] = new Node();
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
	Node *proot = new Node();
	bool result = true;
	for (int n=0; n < N; ++n) {
	    cin >> str;
	    if ( result == true && !insert(proot, str) ) {
		result = false;
	    }
	}
	cout << (result ? "YES" : "NO") << endl;
	delete proot;
    }

    return 0;
}


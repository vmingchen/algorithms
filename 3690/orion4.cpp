/*
 * =====================================================================================
 *
 *       Filename:  orion.cpp
 *
 *    Description:  POJ 3690. Constellation
 *
 *        Version:  1.0
 *        Created:  07/03/2009 10:56:07 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  BUAA.edu
 *
 * =====================================================================================
 */


#include	<iostream>

using namespace std;

const int MAXN = 1001;
const int MAXP = 51;

int num_found = 0;

inline int c2i(char c) { return c=='*' ? 1 : 0; } 

class TNode {
    public:
	bool found;
	int count;
	TNode *children[2];
	TNode() : found(false), count(0) {
	    children[0] = NULL;
	    children[1] = NULL;
	};
	~TNode() {
	    if ( children[0] != NULL ) {
		delete children[0];
		children[0] = NULL;
	    }
	    if ( children[1] != NULL ) {
		delete children[1];
		children[1] = NULL;
	    }
	};
};

TNode * insert(TNode *pnode, char *str, int n)
{
    if ( n == 0 ) return pnode;
    int idx = c2i(*str);
    if ( pnode->children[idx] == NULL ) 
	pnode->children[idx] = new TNode();
    return insert(pnode->children[idx], ++str, n-1);
}

TNode* search(TNode *pnode, char *str, int n)
{
    if ( n == 0 ) return pnode;
    if ( pnode->children[c2i(*str)] == NULL )
	return NULL;
    return search(pnode->children[c2i(*str)], str+1, n-1);
}

int main()
{
    TNode *root, *pnode;
    int N, M, T, P, Q, caseNo=1;
    char sky[MAXN][MAXN], constellation[MAXP][MAXP];

    while ( cin >> N >> M >> T >> P >> Q ) {
	num_found = 0;
	if ( N == 0 ) break;
	for (int n=0; n<N; ++n) {
	    do {
		cin.getline(sky[n], M+1);
	    } while ( sky[n][0] == '\0' );
	}

	// read constellation and build trie
	root = new TNode();
	for (int t=1; t<=T; ++t) {
	    pnode = root;
	    for (int p=0; p<P; ++p) {
		do {
		    cin.getline(constellation[p], Q+1);
		} while ( constellation[p][0] == '\0' );
		pnode = insert(pnode, constellation[p], Q);
	    }
	    pnode->count++;
	}

	// search
	for (int n=0; n<=N-P; ++n) {
	    for (int m=0; m<=M-Q; ++m) {
		pnode = root;
		for (int p=0; p<P; ++p) {
		    pnode = search(pnode, sky[n+p]+m, Q);
		    if ( pnode == NULL ) break;
		}
		if ( pnode != NULL && !pnode->found ) {
		    num_found += pnode->count;
		    pnode->found = true;
		}
	    }
	}

	cout << "Case " << caseNo++ << ": " << num_found << endl;
	delete root;
    }

    return 0;
}

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
	TNode *children[2];
	TNode() {
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

void insert(TNode *pnode, char *str)
{
    if ( *str == '\0' ) return ;
    int idx = c2i(*str);
    if ( pnode->children[idx] == NULL ) 
	pnode->children[idx] = new TNode();
    insert(pnode->children[idx], ++str);
}

void search(TNode *pnode, char *str)
{
    if ( *str == '\0' ) {
	++num_found;
	return;
    }
    if ( pnode->children[c2i(*str)] == NULL )
	return;
    search(pnode->children[c2i(*str)], str+1);
}

void strcat(char *p, char *a, int len)
{
    while ( *p != '\0' ) ++p;
    for (int i=0; a[i] != '\0' && i < len; ++i) 
	*p++ = a[i];
    *p = '\0';
}

int main()
{
    TNode *root;
    int N, M, T, P, Q, caseNo=1;
    char sky[MAXN][MAXN], word[MAXN], constellation[MAXP*MAXP];

    while ( cin >> N >> M >> T >> P >> Q ) {
	num_found = 0;
	if ( N == 0 ) break;
	for (int n=0; n<N; ++n) {
	    do {
		cin.getline(sky[n], M+1);
	    } while ( sky[n][0] == '\0' );
	}

	// build trie
	root = new TNode();
	for (int n=0; n<=N-P; ++n) {
	    for (int m=0; m<=M-Q; ++m) {
		constellation[0] = '\0';
		for (int p=0; p<P; ++p) {
		    strcat(constellation, sky[n+p]+m, Q);
		}
		insert(root, constellation);
	    }
	}

	// read constellation and search
	for (int t=1; t<=T; ++t) {
	    constellation[0] = '\0';
	    for (int p=0; p<P; ++p) {
		do {
		    cin.getline(word, Q+1);
		} while ( word[0] == '\0' );
		strcat(constellation, word, Q);
	    }
	    search(root, constellation);
	}
	cout << "Case " << caseNo++ << ": " << num_found << endl;
	delete root;
    }

    return 0;
}

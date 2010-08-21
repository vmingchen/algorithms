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
#include	<cstring>

using namespace std;

const int MAXN = 1001;
const int MAXM = 126;
const int MAXP = 51;
const unsigned char masks[8] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};

int num_found = 0;

class TNode {
    public:
	bool found;
	int count;
	TNode *children[256];
	TNode() : found(false), count(0) {
	    memset(children, sizeof(children), NULL);
	};
	~TNode() {
	    for (int i=0; i<256; ++i) {
		if ( children[i] != NULL ) {
		    delete children[i];
		    children[i] = NULL;
		}
	    }
	};
};

TNode * insert(TNode *pnode, unsigned char *str, int n)
{
    if ( n == 0 ) return pnode;
    if ( pnode->children[*str] == NULL ) 
	pnode->children[*str] = new TNode();
    return insert(pnode->children[*str], str+1, n-1);
}

TNode* search(TNode *pnode, unsigned char *str, int n)
{
    if ( n == 0 ) return pnode;
    if ( pnode->children[*str] == NULL )
	return NULL;
    return search(pnode->children[*str], str+1, n-1);
}

unsigned char getbyte(char *p, int n)
{
    unsigned char c = 0;
    int lim = n < 8 ? n : 8;
    for (int i=0; *p != '\0' && i < lim; ++i) { 
	if ( *p++ == '*' ) c |= masks[i];
    }
    return c;
}

int main()
{
    TNode *root, *pnode;
    int N, M, T, P, Q, Qb, caseNo=1;
    unsigned char line[MAXM];
    char constellation[MAXP][MAXP];
    char sky[MAXN][MAXN];

    while ( cin >> N >> M >> T >> P >> Q ) {
	num_found = 0;
	if ( N == 0 ) break;
	for (int n=0; n<N; ++n) {
	    do {
		cin.getline(sky[n], M+1);
	    } while ( sky[n][0] == '\0' );
	}

	// build trie
	Qb = (Q+8-1)/8;
	root = new TNode();
	for (int n=0; n<=N-P; ++n) {
	    for (int m=0; m<=M-Q; ++m) {
		pnode = root;
		for (int p=0; p<P; ++p) {
		    for (int q=0; q<Q; q+=8) {
			line[q>>3] = getbyte(sky[n+p]+m+q, Q-q);
		    }
		    pnode = insert(pnode, line, Qb);
		}
	    }
	}

	// read candidates and search
	for (int t=1; t<=T; ++t) {
	    pnode = root;
	    for (int p=0; p<P; ++p) {
		do {
		    cin.getline(constellation[p], Q+1);
		} while ( constellation[p][0] == '\0' );
	    }
	    for (int p=0; p<P; ++p) {
		for (int q=0; q<Q; q+=8) {
		    line[q>>3] = getbyte(constellation[p]+q, Q-q);
		}
		pnode = search(pnode, line, Qb);
		if ( pnode == NULL ) break;
	    }
	    if ( pnode != NULL ) ++num_found;
	}

	cout << "Case " << caseNo++ << ": " << num_found << endl;
	delete root;
    }

    return 0;
}

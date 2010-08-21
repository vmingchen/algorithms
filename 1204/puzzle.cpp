/*
 * =====================================================================================
 *
 *       Filename:  puzzle.cpp
 *
 *    Description:  POJ 1204. Word puzzles
 *
 *        Version:  1.0
 *        Created:  07/02/2009 06:11:56 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  BUAA.edu
 *
 * =====================================================================================
 */


#include 	<cstdio>
#include 	<cstring>

using namespace std;

const int MAXN = 1001;
char board[MAXN][MAXN];

char words[MAXN];
int word_pos[MAXN][3];
const int DL[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int DC[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int L, C, W;
int num_found, curl, curc;

class TNode {
    public:
	int key;
	TNode *children[26];
	TNode() : key(-1) {
	    memset(children, NULL, sizeof(children));
	};
	~TNode() {
	    for (int i=0; i<26; ++i) {
		if ( children[i] ) {
		    delete children[i];
		    children[i] = NULL;
		}
	    }
	};
};

void insert(TNode *vertex, char *str, int idx) 
{
    if ( *str == '\0' ) {
	vertex->key = idx;
	return ;
    }
    if ( vertex->children[*str-'A'] == NULL ) 
	vertex->children[*str-'A'] = new TNode();
    insert(vertex->children[*str-'A'], str+1, idx);
}

void search(TNode *vertex, int l, int c, int d)
{
    if ( vertex->key >= 0 && word_pos[vertex->key][0] == -1 ) {
	word_pos[vertex->key][0] = curl;
	word_pos[vertex->key][1] = curc;
	word_pos[vertex->key][2] = d;
	++num_found;
    }
    if ( l<0 || l>=L || c<0 || c>=C ) return ;
    if ( vertex->children[board[l][c]-'A'] == NULL ) return ;
    search(vertex->children[board[l][c]-'A'], l+DL[d], c+DC[d], d);
}

int main()
{
    scanf("%d %d %d", &L, &C, &W);
    for (int l=0; l<L; ++l) {
	scanf("%s", board[l]);
    }

    TNode *root = new TNode();
    for (int w=0; w<W; ++w) {
	scanf("%s", words);
	insert(root, words, w);
	word_pos[w][0] = -1;
    }

    num_found = 0;
    for (int l=0; l<L; ++l) {
	for (int c=0; c<C; ++c) {
	    curl = l;
	    curc = c;
	    for (int d=0; d<8; ++d) {
		search(root, l, c, d);
	    }
	    if ( num_found == W ) {
		for (int w=0; w<W; ++w) {
		    printf("%d %d %c\n", 
			    word_pos[w][0], 
			    word_pos[w][1], 
			    word_pos[w][2] + 'A');
		}
		delete root;
		return 0;
	    }
	}
    }


    return 0;
}

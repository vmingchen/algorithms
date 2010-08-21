#include	<iostream>
#include	<sstream>

using namespace std;

const int MAXL = 100000;

class Node {
public:
    Node *children[26];
    int value;
    Node () : value(-1) {
	for ( int i = 0; i < 26; i++ ) children[i] = NULL;
    }
    ~Node() {
	for ( int i = 0; i < 26; i++ ) {
	    if ( children[i] != NULL ) {
		delete children[i];
		children[i] = NULL;
	    }
	}
    }
};

char inputs[100001][11], line[MAXL], lang[MAXL];

void insert( Node *pnode, char *p, int i ) 
{
    if ( *p == '\0' ) {
	pnode->value = i;
	return ;
    }
    Node *pchild = pnode->children[*p-'a'];
    if ( pchild == NULL ) { 
	pchild = new Node(); 
	pnode->children[*p-'a'] = pchild;
    }
    insert( pchild, p+1, i );
}

int query( Node *pnode, char *p )
{
    if ( pnode == NULL ) return -1;
    if ( *p == '\0' ) {
	return pnode->value;
    } else {
	return query( pnode->children[*p-'a'], p+1 );
    }
}

int main()
{
    Node *proot = new Node();
    for ( int i = 0; cin.getline( line, MAXL ) && line[0] != '\0'; ++i ) {
	stringstream ss (stringstream::in | stringstream::out);
	ss << line;
	ss >> inputs[i] >> lang;
	insert( proot, lang, i );
    }

    while ( cin >> lang ) {
	int r = query( proot, lang );
	if ( r >= 0 ) {
	    cout << inputs[r] << endl;
	} else {
	    cout << "eh" << endl;
	}
    }

    return 0;
}

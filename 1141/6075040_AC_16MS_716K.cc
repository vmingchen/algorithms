#include	<iostream>
#include	<string>

using namespace std;

const int MAXN = 101;
int shortest[MAXN][MAXN];
char ans[2*MAXN];
string bracket;

bool match(const char &a, const char &b) 
{
    if ( (a == '(' && b == ')')
	    || (a == '[' && b == ']')
	    || (a == '{' && b == '}') )
	return true;
    return false;
}

void fill(const char &a, char *p1, char *p2)
{
    switch(a) {
	case '(': case ')':
	    *p1 = '('; *p2 = ')'; break;
	case '{': case '}':
	    *p1 = '{'; *p2 = '}'; break;
	case '[': case ']':
	    *p1 = '[', *p2 = ']'; break;
    }
}

void search(int src, int len, int dest)
{
    if ( len == 1 ) {
	fill(bracket[src], &(ans[dest]), &(ans[dest+1]));
    }
    if ( len <= 1 ) return ;
    if ( match(bracket[src], bracket[src+len-1]) 
	    && shortest[src][len] == shortest[src+1][len-2] ) {
	ans[dest] = bracket[src];
	ans[dest+(len+shortest[src][len])-1] = bracket[src+len-1];
	search(src+1, len-2, dest+1);
	return ;
    }
    for (int l = 1; l < len; l++) {
	if ( shortest[src][len] == shortest[src][l] + shortest[src+l][len-l] ) {
	    search(src, l, dest);
	    search(src+l, len-l, dest+l+shortest[src][l]);
	    return ;
	}
    }
}

int main()
{
    cin >> bracket;
    int blen = bracket.length();

    for (int st = 0; st < blen; st++) {
	for (int l = 2; st+l <= blen; l++) shortest[st][l] = MAXN;
    }
    for (int st = 0; st <= blen; st++) shortest[st][0] = 0;
    for (int st = 0; st < blen; st++) shortest[st][1] = 1;

    for (int l = 2; l <= blen; l++) {
	for (int st = 0; (st+l) <= blen; st++) {
	    int s = shortest[st][l];
	    if ( match(bracket[st], bracket[st+l-1]) && shortest[st+1][l-2] < s ) 
		s = shortest[st+1][l-2];
	    for (int m = 1; m < l; m++) {
		int t = shortest[st][m] + shortest[st+m][l-m];
		if ( t < s ) s = t;
	    }
	    shortest[st][l] = s;
	}
    }

    search(0, blen, 0);
    ans[blen+shortest[0][blen]] = '\0';

    cout << ans << endl;
    return 0;
}

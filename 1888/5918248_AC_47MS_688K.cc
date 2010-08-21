#include	<iostream>

using namespace std;

const int MAXN = 10;

int main()
{
    int r, c;
    for ( int no = 1; cin >> r && r != 0; ++no ) {
	cin >> c;
	char board[MAXN][MAXN+1];
	int numbers[MAXN][MAXN] = {{0}}, count = 0;
	for ( int i = 0; i < r; ++i ) cin >> board[i];
	for ( int i = 0; i < r; ++i ) {
	    for ( int j = 0; j < c; ++j ) {
		if ( board[i][j] != '*' && (i == 0 || j == 0 
			|| board[i-1][j] == '*' || board[i][j-1] == '*') )
		    numbers[i][j] = ++count;
	    }
	}

	cout << "puzzle #" << no << ":" << endl;
	cout << "Across" << endl;
	for ( int i = 0; i < r; ++i ) {
	    for ( int j = 0; j < c; ++j ) {
		if ( numbers[i][j] > 0 && ( j == 0 || board[i][j-1] == '*' ) ) {
		    if ( numbers[i][j] < 10 ) cout << "  " << numbers[i][j] << ".";
		    else if ( numbers[i][j] < 100 ) cout << " " << numbers[i][j] << ".";
		    else cout << numbers[i][j] << ".";
		    for ( int k = j; k < c && board[i][k] != '*'; ++k )
			cout << board[i][k];
		    cout << endl;
		}
	    }
	}

	cout << "Down" << endl;
	for ( int i = 0; i < r; ++i ) {
	    for ( int j = 0; j < c; ++j ) {
		if ( numbers[i][j] > 0 && ( i == 0 || board[i-1][j] == '*' ) ) {
		    if ( numbers[i][j] < 10 ) cout << "  " << numbers[i][j] << ".";
		    else if ( numbers[i][j] < 100 ) cout << " " << numbers[i][j] << ".";
		    else cout << numbers[i][j] << ".";
		    for ( int k = i; k < r && board[k][j] != '*'; ++k )
			cout << board[k][j];
		    cout << endl;
		}
	    }
	}

	cout << endl;
    }
    return 0;
}

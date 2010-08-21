/*
 * =====================================================================================
 *
 *       Filename:  seven.cpp
 *
 *    Description:  POJ 3650. The Seven Percent Solution
 *
 *        Version:  1.0
 *        Created:  07/03/2009 10:00:02 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  BUAA.edu
 *
 * =====================================================================================
 */


#include	<iostream>

const int MAXN = 10001;

using namespace std;

int main()
{
    char line[MAXN], c;
    while ( cin.getline(line, MAXN) && line[0] != '#' ) {
	for (int i=0; line[i] != '\0'; ++i) {
	    c = line[i];
	    if ( c == ' ' ) cout << "\%20";
	    else if ( c == '!' ) cout << "\%21";
	    else if ( c == '$' ) cout << "\%24";
	    else if ( c == '%' ) cout << "\%25";
	    else if ( c == '(' ) cout << "\%28";
	    else if ( c == ')' ) cout << "\%29";
	    else if ( c == '*' ) cout << "\%2a";
	    else cout << c;
	}
	cout << endl;
    }
}

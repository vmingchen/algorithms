/*
 * =====================================================================================
 *
 *       Filename:  channel.cpp
 *
 *    Description:  POJ 1129 Channel allocation
 *
 *        Version:  1.0
 *        Created:  03/07/2010 02:58:07 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  Beihang University
 *
 * =====================================================================================
 */

#include	<iostream>
#include	<cstring>

using namespace std;

const int MAXL = 27;
int num, channels, color[MAXL];
bool map[MAXL][MAXL];

bool sound(int c, int n)
{
    for (int i = 0; i < num; i++) 
        if ( map[i][n] && c == color[i] ) return false;
    return true;
}

bool search(int n)
{
    if ( n == num ) return true;
    for (int i = 1; i <= num; i++) {
        if ( !sound(i, n) ) continue;
        color[n] = i;
        if ( search(n+1) ) return true;
    }
    return false;
}

int main()
{
    char line[MAXL];
    while ( (cin >> num) && num != 0 ) {
        cin.getline( line, MAXL );      // get rid of newline

        memset( map, 0, sizeof(map) );
        for (int l = 0; l < num; l++) {
            cin.getline( line, MAXL );
            for (int j = 2; line[j] != '\0'; j++) {
                map[l][line[j]-'A'] = true;
                map[line[j]-'A'][l] = true;
            }
            map[l][l] = true;
        }

        search(0);
        channels = 0;
        for (int i = 0; i < num; i++) 
            if ( color[i] > channels ) channels = color[i];

        cout << channels 
            << (channels == 1 ? " channel" : " channels")
            << " needed." << endl;
    }

    return 0;
}

/*
 * =====================================================================================
 *
 *       Filename:  balance.cpp
 *
 *    Description:  POJ 1837. Balance
 *
 *        Version:  1.0
 *        Created:  04/05/2010 03:19:19 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  Beihang University
 *
 * =====================================================================================
 */

#include	<iostream>

using namespace std;
const int MAXC = 20;
const int MAXG = 20;
const int MAXV = 25;
const int MAXV = 15*25*20;

int _value[2*MAXV+3] = {0};

int value( int idx )
{
    return _value[idx+MAXV+1];
}

int main()
{
    int C, G;
    int hooks[MAXC], weights[MAXG];

    cin >> C >> G;
    for ( int c = 0; c < C; ++c ) cin >> hooks[c];
    for ( int g = 0; g < G; ++g ) cin >> weights[g];


    return 0;
}

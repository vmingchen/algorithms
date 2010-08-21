/*
 * =====================================================================================
 *
 *       Filename:  median2.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/04/2010 12:12:39 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  Beihang University
 *
 * =====================================================================================
 */

#include	<algorithm>
#include	<iostream>

using namespace std;

const int MAXN = 10000;
int N, outputs[MAXN];

int main ( int argc, char *argv[] )
{ 
    cin >> N;
    for ( int i = 0; i < N; ++i ) cin >> outputs[i];
    sort( outputs, outputs+N );
    cout << outputs[N>>1] << endl;
    return 0;
}

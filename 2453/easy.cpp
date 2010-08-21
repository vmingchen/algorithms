/*
 * =====================================================================================
 *
 *       Filename:  easy.cpp
 *
 *    Description:  POJ 2453 Great bitwise operation
 *
 *        Version:  1.0
 *        Created:  08/01/2009 02:45:57 PM
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

int main()
{
    int n;
    while ( (cin >> n) && n != 0 ) {
	// the only '1' in x's binary form indicate the last '1' in n's binary form (n)_2
	int x = n & (-n);		
	// y change the last '01' in (n)_2 into '10', for example '1001110' to '1010000' 
	// this guarantee y is the smallest number larger than x
	int y = n + x;
	// z is '1011110' divided by '0000010' which moves the sequential '1's to the least 
	// significat bits '0101111', then it is right shifted by 2 to eliminate two '1's.
	// Lastly, z is added into y to obtain the answer with the same number of '1's.
	int z = ((n^y)/x) >> 2;
	cout << (y + z) << endl;
    }
    return 0;
}

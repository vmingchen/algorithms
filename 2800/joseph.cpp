// =====================================================================================
// 
//       Filename:  joseph.cpp
// 
//    Description:  POJ 2800
// 
//        Version:  1.0
//        Created:  7/20/2009 9:13:24 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Ming Chen
//        Company:  MSRA
// 
// =====================================================================================


#include	<iostream>

using namespace std;

int main()
{
	long long n, k;
	cin >> n >> k;

	long long t = n > k ? k : n;
	long long st = t;
	long long quotient = 0;
	while ( st >= 1 ) {
		int quo = k/st;
		int end = k/(quo+1);
		quotient += ((st-end)*(st+end+1)>>1)*quo;
		st = end;
	}

	long long result = t*k - quotient;
	result += (n-t)*k;
	cout << result << endl;
	return 0;
}

/*
 * =====================================================================================
 *
 *       Filename:  panda.cpp
 *
 *    Description:  POJ problem 3716.
 *
 *        Version:  1.0
 *        Created:  04/11/2009 10:19:52 AM
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

const int DIE_NUM = 4;
const int DIE_STATES = 7;
const int DICES_STATES = 2401;
const int X_STATES = 5;

int E_on_D_on_X [DICES_STATES * X_STATES] = {};	//2401 = 7^4

void init()
{

  int D, dv[DIE_NUM], di[DIE_NUM];
  int pD, pX_on_D[X_STATES], E_on_D = 0;
  int i, t;

  int PD[DIE_STATES] = {1, 6, 15, 20, 15, 6, 1}; 	// PD=PD/64
  int PX[X_STATES] = {1, 4, 6, 4, 1}; 			// PX=PX/16

  for (D=0; D < DICES_STATES; ++D) {
    for (i=0, t=D; i<DIE_NUM; ++i, t/=7) {
      dv[i] = t % 7; 
      di[i] = 6 - dv[i];
    }
    pX_on_D[0] = (di[0]*di[1]*di[2]*di[3]);
    pX_on_D[1] = (dv[0]*di[1]*di[2]*di[3] + di[0]*dv[1]*di[2]*di[3] 
		  + di[0]*di[1]*dv[2]*di[3] + di[0]*di[1]*di[2]*dv[3]);
    pX_on_D[2] = (dv[0]*dv[1]*di[2]*di[3] + dv[0]*di[1]*dv[2]*di[3]
		  + dv[0]*di[1]*di[2]*dv[3] + di[0]*dv[1]*dv[2]*di[3]
		  + di[0]*dv[1]*di[2]*dv[3] + di[0]*di[1]*dv[2]*dv[3]);
    pX_on_D[3] = (di[0]*dv[1]*dv[2]*dv[3] + dv[0]*di[1]*dv[2]*dv[3] 
		  + dv[0]*dv[1]*di[2]*dv[3] + dv[0]*dv[1]*dv[2]*di[3]);
    pX_on_D[4] = (dv[0]*dv[1]*dv[2]*dv[3]);		// pX_on_D = pX_on_D/(6*6*6*6)
    pD = PD[dv[0]]*PD[dv[1]]*PD[dv[2]]*PD[dv[3]];	// pD = pD/(6*6*6*6)
    E_on_D = dv[0] + dv[1] + dv[2] + dv[3];		// E_on_D=E_on_D/6
    for (i=0; i<X_STATES; ++i) {
      E_on_D_on_X[D*X_STATES + i] = (pX_on_D[i]*pD*E_on_D)/PX[i];	// 16/(64*6^9)
    }
  }
}

double expect(int x) 
{
  int D;
  double exp = 0.0;
  for ( D=0; D < DICES_STATES; ++D ) {
    exp += E_on_D_on_X[D*X_STATES + x];
  }
  return exp/(4*6*6*6*6*6*6*6*6*6);	// *16/(64*6^8) 
}

  int
main ( int argc, char *argv[] )
{
  int nc, x1, x2, ex;

  cout.precision(3);
  cout.setf(ios::fixed,ios::floatfield); 
  cin >> nc;
  init();
  for (int i=0; i<nc; i++) {
    cin >> x1 >> x2;
    ex = (expect(x1) + expect(x2))/2;
    cout << ex << endl;
  }

  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

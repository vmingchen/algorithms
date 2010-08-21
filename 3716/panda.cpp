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
const int DICES_STATES = 2401;	//2401 = 7^4
const int X_STATES = 5;

int PX_on_D[DICES_STATES * X_STATES] = {};
double EX_on_D[DICES_STATES] = {};
double posterior[DICES_STATES * X_STATES] = {};
double EX_on_x[X_STATES] = {};

int Pd[DIE_STATES] = {1, 6, 15, 20, 15, 6, 1}; 		// PD=PD/64
int Px[X_STATES] = {1, 4, 6, 4, 1}; 			// PX=PX/16

void init()
{
  int D, PD, dv[DIE_NUM], di[DIE_NUM];
  int offset, x, d, t;

  for (D=0; D < DICES_STATES; ++D) {
    for (d=0, t=D; d<DIE_NUM; ++d, t/=7) {
      dv[d] = t % 7; 
      di[d] = 6 - dv[d];
    }
    offset = D*X_STATES; 
    // condition PX on D, PX_on_D = PX_on_D/6^4
    PX_on_D[offset+0] = (di[0]*di[1]*di[2]*di[3]);
    PX_on_D[offset+1] = (dv[0]*di[1]*di[2]*di[3] + di[0]*dv[1]*di[2]*di[3] 
		  + di[0]*di[1]*dv[2]*di[3] + di[0]*di[1]*di[2]*dv[3]);
    PX_on_D[offset+2] = (dv[0]*dv[1]*di[2]*di[3] + dv[0]*di[1]*dv[2]*di[3]
		  + dv[0]*di[1]*di[2]*dv[3] + di[0]*dv[1]*dv[2]*di[3]
		  + di[0]*dv[1]*di[2]*dv[3] + di[0]*di[1]*dv[2]*dv[3]);
    PX_on_D[offset+3] = (di[0]*dv[1]*dv[2]*dv[3] + dv[0]*di[1]*dv[2]*dv[3] 
		  + dv[0]*dv[1]*di[2]*dv[3] + dv[0]*dv[1]*dv[2]*di[3]);
    PX_on_D[offset+4] = (dv[0]*dv[1]*dv[2]*dv[3]);		

    // condition EX on D, EX_on_D = EX_on_D/6^4
    EX_on_D[D] = PX_on_D[offset+0]*0 
		+ PX_on_D[offset+1]*1 
		+ PX_on_D[offset+2]*2 
		+ PX_on_D[offset+3]*3 
		+ PX_on_D[offset+4]*4; 
    EX_on_D[D] = EX_on_D[D]/(6*6*6*6);

    // work out posterior, PD = PD/64^4, posterior = posterior*16/(6^4*64^4)
    PD = Pd[dv[0]]*Pd[dv[1]]*Pd[dv[2]]*Pd[dv[3]];
    for ( x=0; x < X_STATES; ++x ) 
      posterior[offset+x] = PX_on_D[offset+x]*PD*16.0/(Px[x]*6*6*6*6*64*64*64*64);
  }

  for ( x=0; x < X_STATES; ++x ) {
    EX_on_x[x] = 0.0;
    for ( D=0; D < DICES_STATES; ++D ) 
      EX_on_x[x] += EX_on_D[D]*posterior[D*X_STATES+x];
  }

}

  int
main ( int argc, char *argv[] )
{
  int nc, x1, x2;
  double ex;

  cout.precision(3);
  cout.setf(ios::fixed,ios::floatfield); 
  cin >> nc;
  init();
  for (int i=0; i<nc; i++) {
    cin >> x1 >> x2;
    ex = (EX_on_x[x1] + EX_on_x[x2])/2.0;
    cout << ex << endl;
  }

  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

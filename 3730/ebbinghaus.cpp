/*
 * =====================================================================================
 *
 *       Filename:  ebbinghaus.cpp
 *
 *    Description:  POJ 3730
 *
 *        Version:  1.0
 *        Created:  04/23/2009 06:09:03 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  BUAA.edu
 *
 * =====================================================================================
 */


#include	<iostream>
#include	<vector>

using namespace std;

const int MAX_PERIOD = 1000;

const char MAX_TM = 3;
const char NEW_TM = 2;
const char REVIEW_TM = 1;
const char NEW_FREE = 1;
const char REVIEW_FREE = 2;

int review_num = 0;
int reviews[MAX_PERIOD] = {0};

class Schedule {
public :
  int today, period;
  std::vector<char> timetable;

  Schedule(int p) : today(0), period(p), timetable(p, 0) {
  }

  void proceed() {
    timetable[today] = 0;
    ++today;
    if ( today == period ) today = 0;
  }

  void study_new() {
    timetable[today] += NEW_TM;
    for ( int i=0; i<review_num; ++i ) {
      int r = today + reviews[i];
      if ( r>=period ) r -= period;
      timetable[r] += REVIEW_TM;
    }
  }

  bool is_free() {
    if ( timetable[today] > NEW_FREE ) return false;
    for ( int i=0; i<review_num; ++i ) {
      int r = today + reviews[i];
      if ( r>=period ) r -= period;
      if ( timetable[r] > REVIEW_FREE ) return false;
    }
    return true;
  }
};


  int
main ( int argc, char *argv[] )
{
  int m, days, studied;
  cin >> m >> review_num;

  if ( review_num == 0 ) {
    cout << m << endl;
    return 0;
  }

  for ( int i=0; i < review_num; ++i ) {
    cin >> reviews[i];
    --reviews[i];
  }

  Schedule schedule(reviews[review_num-1]+1);

  studied = 0;
  for ( days=0; studied < m; ++days ) {
    if ( schedule.is_free() ) {
      schedule.study_new();
      ++studied;
    }
    schedule.proceed();
  }

  cout << days + schedule.period - 1 << endl;


  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

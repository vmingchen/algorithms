/*
 * =====================================================================================
 *
 *       Filename:  party.cpp
 *
 *    Description:  POJ 3342. Tree DP
 *
 *        Version:  1.0
 *        Created:  10/09/2010 10:11:58 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chenming), chenming@sohu-rd.com
 *        Company:  imeresearch@sogou
 *
 * =====================================================================================
 */

#include	<vector>
#include	<string>
#include	<map>
#include	<iostream>

using namespace std; 

class State {
public:
    int num; 
    bool unique; 
    State() : num(0), unique(true) {}; 
};

class Employee {
public:
    int boss;
    vector<int> subordinates;
};


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  addname
 *  Description:  
 * =====================================================================================
 */
void addname ( string name, string boss, map<string, int> &names, vector<Employee> &employees, multimap<string, string> &buffer )
{
    int ci = names.size();
    int bi = names[boss];
    names[name] = ci;
    employees[bi].subordinates.push_back(ci);
    employees[ci].boss = bi;

    multimap<string, string>::iterator beg = buffer.lower_bound(name);
    multimap<string, string>::iterator end = buffer.upper_bound(name);
    if ( beg == buffer.end() ) return; 

    vector<string> subs; 
    for (multimap<string, string>::iterator it = beg ; it != end; ++it ) {
        subs.push_back(it->second); 
    }
    buffer.erase(beg, end);

    for (size_t i = 0; i < subs.size(); ++i) {
        addname( subs[i], name, names, employees, buffer ); 
    }
}		/* -----  end of function addname  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  solve
 *  Description:  
 * =====================================================================================
 */
void solve ( const vector<Employee>& employees, int &num, bool &unique )
{
    int n = employees.size();
    vector< vector<State> > states(n, vector<State>(2)); 

    for (int i = n-1; i >= 0; --i) {
        if ( employees[i].subordinates.size() == 0 ) {
            states[i][0].num = 0;
            states[i][1].num = 1;
            continue;
        }
        State st0, st1; 
        for (size_t j = 0; j < employees[i].subordinates.size(); ++j) {
            int c = employees[i].subordinates[j];
            if ( states[c][0].num == states[c][1].num ) {
                st0.num += states[c][0].num;
                st0.unique = false;
            } else if ( states[c][0].num > states[c][1].num ) {
                st0.num += states[c][0].num;
                st0.unique &= states[c][0].unique;
            } else {
                st0.num += states[c][1].num; 
                st0.unique &= states[c][1].unique;
            }
            st1.num += states[c][0].num;
            st1.unique &= states[c][0].unique;
        }
        states[i][0].num = st0.num; states[i][0].unique = st0.unique;
        states[i][1].num = st1.num + 1; states[i][1].unique = st1.unique;
    }

    if ( states[0][0].num > states[0][1].num ) {
        num = states[0][0].num; 
        unique = states[0][0].unique; 
    } else if ( states[0][0].num < states[0][1].num ) {
        num = states[0][1].num; 
        unique = states[0][1].unique; 
    } else {
        num = states[0][0].num; 
        unique = false; 
    }
}		/* -----  end of function solve  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
    int
main ( int argc, char *argv[] )
{ 
    int n = 0; 
    while ( cin >> n ) {
        if (n == 0) break;

        map<string, int> names;
        multimap<string, string> buffer; 
        vector<Employee> employees(n); 
        string head;
        cin >> head;
        names[head] = 0;

        for (int i = 1; i < n; ++i) {
            string name, boss;
            cin >> name >> boss;
            if ( names.count(boss) == 0 ) {         // defer insersion
                buffer.insert(make_pair(boss, name));
            } else {
                addname(name, boss, names, employees, buffer); 
            }
        }

        int num; 
        bool unique;
        solve(employees, num, unique); 
        cout << num << (unique ? " Yes" : " No") << endl; 
    }
    return 0;
}				/* ----------  end of function main  ---------- */

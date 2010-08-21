/*
 * =====================================================================================
 *
 *       Filename:  hr.cpp
 *
 *    Description:  POJ problem 2003
 *
 *        Version:  1.0
 *        Created:  02/25/2009 08:54:35 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  BUAA.edu
 *
 * =====================================================================================
 */


#include	<iostream>
#include	<string>
#include	<map>

using namespace std;

class Employee {
    public:
      Employee *parent, *sibling, *firstChild, *lastChild;
      string name;
      Employee(string nm) : name(nm) {
	parent = sibling = firstChild = lastChild = NULL;
      }
};

Employee * hire(Employee *employer, Employee *newEmployee) 
{
  newEmployee->parent = employer;
  if ( employer->firstChild == NULL ) {
    employer->firstChild = employer->lastChild = newEmployee;
  } else {
    employer->lastChild->sibling = newEmployee;
    employer->lastChild = newEmployee;
  }
  return newEmployee;
}

Employee * fire(Employee *victim) 
{
  Employee * drop = victim;
  while ( drop->firstChild != NULL ) { // promote first child
    drop->name = drop->firstChild->name;
    drop = drop->firstChild;
  }
  if ( drop->parent != NULL ) {
    if ( drop->parent->firstChild == drop ) {
      drop->parent->firstChild = drop->sibling;
    } else {
      Employee * ps;	// find preview sibling, update parent's last child
      ps = drop->parent->firstChild;
      while ( ps->sibling != drop ) ps = ps->sibling;
      ps->sibling = drop->sibling;
      if ( drop == drop->parent->lastChild ) {
	drop->parent->lastChild = ps;
      }
    }
  }
  return drop;
}

void print(Employee *root, int level) {
  for ( int i=0; i<level; ++i ) {
    cout << "+";
  }
  cout << root->name << endl;
  for ( Employee *fc = root->firstChild; fc!=NULL; fc = fc->sibling ) {
    print(fc, level+1);
  }
}

void print_hline()
{
  for ( int i=0; i<60; ++i ) 
    cout << "-";
  cout << endl;
}

    int
main ( int argc, char *argv[] )
{
    Employee *root;
    string token, name1, name2;
    map<string, Employee *> staff;

    if ( cin >> token ) { 
	root = new Employee(token);
	staff.insert(make_pair(root->name, root));
    }

    while ( cin >> token ) {
      if ( token == "print" ) {
	print(root, 0);
	print_hline();
      } else if ( token == "fire" ) {
	cin >> name1;
	fire(staff[name1]);
      } else {
	name1 = token;
	cin >> token >> name2;
	Employee *newEmployee = new Employee(name2);
	staff.insert(make_pair(name2, newEmployee));
	hire(staff[name1], newEmployee);
      }
    }

    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

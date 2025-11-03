#include <iostream>
#include <string>
#include "class.h"

using namespace std;

void print (char &cmd);
int
main ()
{
  Course course[5];

  char cmd;
  string input;
  int i = 0;
  cout << "\nWelcome to course maker! please select the following options" <<
    endl << endl;

  print (cmd);
  do
    {
      if (cmd == 'a')
	{
	  if (i < 5)
	    {
	      cout << "What course would you like to create? ";
	      cin.ignore ();
	      getline (cin, input, '\n');
	      course[i].setName (input);
	      // setting name for the course

	      cout << "What is the class code? ";
	      getline (cin, input, '\n');
	      course[i].setCode (input);
	      // setting code name for the course

	      i++;
	      // i increments the course 
	    }

	  else
	    {
	      cout << "\nError. Exceeded course limit." << endl;
	      // if the limit of courses has been added, then an error will occur
	    }
	}

      else if (cmd == 'r')
	{

	  if (i == 0)
	    {
	      cout << "\nError. no courses added yet. " << endl;
	    }
	  // Checks if no courses has been added yet with i. If there are courses then the process under will continue

	  else if (i != 0)
	    {
	      cout << "What course would you like to remove? " << endl;
	      for (int j = 0; j < i; j++)
		cout << j + 1 << ") " << course[j].getName () << endl;
	      // prints out the course list from + one to size + 1

	      cin.ignore ();
	      getline (cin, input, '\n');

	      bool courseRemoved = false;

	      for (int j = 0; j < i; j++)
		{
		  if (input == course[j].getName ())
		    {
		      course[j].resetRoster ();	// to reset the roster
		      for (int q = j; q < i - 1; q++)
			{
			  course[q] = course[q + 1];
			}
		      // to move the courses to the left 

		      courseRemoved = true;
		      break;
		    }
		}

	      if (courseRemoved)
		{
		  i--;
		}
	      // checks if you actually chose a course and if you did then i increments to the left

	      else
		{
		  cout << "\nError. Course not found." << endl;
		}
	      // same thing but if you did not chose the right course then an error occurs
	    }
	}

      else if (cmd == 'l')
	{

	  if (i == 0)
	    {
	      cout << "\nError. no courses added yet. " << endl;
	    }
	  // Checks if no courses has been added yet with i. If there are courses then the process under will continue

	  else if (i != 0)
	    {
	      for (int j = 0; j < i; j++)
		cout << course[j] << endl;
	    }
	}

      else if (cmd == 'e')
	{

	  if (i == 0)
	    {
	      cout << "\nError. no courses added yet. " << endl;
	    }
	  // Checks if no courses has been added yet with i. If there are courses then the process under will continue

	  else if (i != 0)
	    {
	      cout <<
		"What course would you like the student to be added to: " <<
		endl;

	      for (int j = 0; j < i; j++)
		cout << j + 1 << ") " << course[j].getName () << endl;
	      // prints out the course list from + one to size + 1

	      cin.ignore ();
	      getline (cin, input, '\n');

	      bool foundValue = false;
	      for (int j = 0; j < i; j++)
		{
		  if (input == course[j].getName ())
		    {
		      course[j].setRoster ();
		      foundValue = true;
		      break;
		      // If the course is found then, functions will be called for the students to be added to the roster of the course
		    }
		}
	      if (foundValue == false)
		cout << "\nError did not call the right course." << endl;
	      // if the input did not equal the course then an error occurs
	    }
	}

      else if (cmd == 's')
	{
	  if (i == 0)
	    {
	      cout << "\nError. no courses added yet. " << endl;
	    }
	  // Checks if no courses has been added yet with i. If there are courses then the process under will continue

	  else if (i != 0)
	    {
	      cout << "What course would you like to remove the student from "
		<< endl;
	      for (int j = 0; j < i; j++)
		cout << j + 1 << ") " << course[j].getName () << endl;
	      // prints out the course list from + one to size + 1

	      cin.ignore ();
	      getline (cin, input, '\n');

	      bool validateCourse = false;
	      for (int j = 0; j < i; j++)
		{
		  if (input == course[j].getName ())
		    {
		      course[j].callRemove ();
		      validateCourse = true;
		      break;
		      // If the course is found then, functions will be called for the students to be removed from the roster of the course
		    }
		}

	      if (validateCourse == false)
		{
		  cout << "\nError. Did not call the right course. " << endl;
		}
	      // if the input did not equal the course then an error occurs
	    }
	}
      print (cmd);
    }
  while (cmd != 'o');

  return 0;
}

void
print (char &cmd)
{
  cout << "   \033[4mCourse Options\033[0m" << endl;
  cout << "a: Create a course \nr: Remove a course \nl: List all courses" << endl << endl;

  cout << "   \033[4mEnrollment Options\033[0m" << endl;
  cout << "e: Enroll a student in a course \ns: Remove a student from a course" << endl << endl;

  cout << "OUT (o)" << endl;

  cout << "\n< ";
  cin >> cmd;
}

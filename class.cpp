#include <iostream>
#include <string>
#include "class.h"

using namespace std;

// ----------   STUDENT   ---------- //  

ostream & operator<< (ostream & oz, Student * contents)
{
  oz << "   Name: " << contents->getName () << endl;
  oz << "   ID: " << contents->getID () << endl;
  oz << "   Classification: " << contents->getClassification () << endl;
  return oz;
}

Student::Student ()
{
  name = " ";
  id = " ";
  classification = ' ';
}

void
Student::setName (string name)
{
  this->name = name;
}

void
Student::setID (string id)
{
  this->id = id;
}

void
Student::setClassification (char classification)
{
  this->classification = classification;
}

string Student::getName () const
{
  return name;
}

string Student::getID () const
{
  return id;
}

char
Student::getClassification () const
{
  return classification;
}

// ----------   ROSTER   ---------- //  

ostream & operator <<(ostream & os, Roster & roster)
{
  os << "Class size: " << roster.getSize () << endl;
  os << "Roster capacity: " << roster.getCapacity () << endl;

  roster.coutContents ();
  // goes to a function to call for the ostream operator of student

  return os;
}

Roster::Roster ()
{
  size = 0;
  capacity = 5;
  contents = new Student[capacity];
}

Roster::~Roster ()
{
  delete [] contents;
}

int
Roster::getSize () const
{
  return size;
}

int
Roster::getCapacity () const
{
  return capacity;
}

void
Roster::resetRoster()
{
  capacity = 5;
  size = 0; 
}

void
Roster::setCapacity(int capacity)
{
  this -> capacity = capacity;
}

void
Roster::callStudent ()
{  
    if (size == capacity)
  {
    capacity +=5; 
    Student* temp = new Student[capacity]; 

    for (int i=0; i < size; i++)
    {
      temp [i] = contents [i]; 
    }

    delete [] contents; 
    contents = temp; 
  }
  // checks if size = capacity, if it is then, a temp will be created with capacity += 5 and then equal the original

  string studentInput;

      cout << "What is the students name: ";
      getline (cin, studentInput, '\n');
      contents[size].setName (studentInput);

      cout << "Enter the students ID: ";
      getline (cin, studentInput, '\n');
      contents[size].setID (studentInput);

      char classification;
      cout << "Enter the classification of the student: ";
      cin >> classification;
      cin.ignore ();
      contents[size].setClassification (classification);
    
  size++;
}

void Roster::removeStudent() {

  if (size ==0)
  {
    cout << "\nError. no students are added to your course. " << endl; 
  }
  // Checks if no students have been added yet with size. If there are students then the process under will continue

  else if (size != 0)
  {
    string studentInput; 
    cout << "\nWhat student would you like to remove? " << endl; 
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ") " << contents[i].getName() << endl; 
    }
    // prints out the course list from + one to size + 1

    getline(cin, studentInput, '\n'); 

    int removeIndex = -1;
    // this int will make the array change easier

    for (int i = 0; i < size; i++) {
        if (studentInput == contents[i].getName()) {
            removeIndex = i;
            break;
        }
    }

    if (removeIndex == -1) {
        cout << "Error. Could not find the student." << endl;
        return;
    }
    // if the int stayed the same then an error occurs and will go back to the driver

    for (int i = removeIndex; i < size - 1; i++) {
        contents[i] = contents[i + 1];
    }
    // Shift elements to the left to overwrite the removed student

    size--; // Update the size
  }
}

void
Roster::coutContents ()
{
  cout << endl;
  for (int i = 0; i < size; i++)
    cout << "Student #" << i + 1 << "\n" << &contents[i];
}

Roster&
Roster::operator=(const Roster& source)
{
  if (this != &source)
  {
    delete [] contents; 

    size = source.size; 
    capacity = source.capacity; 
    contents = new Student [capacity]; 
    for (int i=0; i < size; i++)
    contents[i] = source.contents[i]; 
  }

  return *this; 
}

Roster::Roster(const Roster& source)
{
  size = source.size; 
  capacity = source.capacity; 

  contents = new Student [capacity]; 
  for (int i=0; i < size; i++)
  contents [i] = source.contents[i];
}

// ----------   COURSE   ---------- //  

ostream & operator<< (ostream & o, Course & course)
{
  o << "Course Name: " << course.getName () << endl;
  o << "Course Code: " << course.getCode () << endl;

  course.coutRoster ();
  // goes to a function to call for the ostream operator of roster

  return o;
}

Course::Course ()
{
  name = " ";
  code = " ";
}

void
Course::setName (string name)
{
  this->name = name;
}

void
Course::setCode (string code)
{
  this->code = code;
}

string Course::getName () const
{
  return name;
}

string Course::getCode () const
{
  return code;
}

void
Course::setRoster ()
{
  roster.callStudent ();
}

void
Course::callRemove()
{
  roster.removeStudent();
}

void
Course::coutRoster ()
{
  cout << roster;
}

Course & Course::operator= (const Course & temp)
{
  if (this != &temp)
    {
      this->name = temp.name;
      this->code = temp.code;
      this->roster = temp.roster;
    }
  return *this;
}


void
Course::resetRoster()
{
  roster.resetRoster();
}

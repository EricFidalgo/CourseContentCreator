#include <string> 
using namespace std;

class Student 
{
  friend ostream& operator<<(ostream& oz, Student* contents);

  private: 
  string name, id; 
  char classification; 

  public: 
  Student(); 
  void setName(string name); 
  void setID(string id); 
  void setClassification(char classification);

  string getName() const; 
  string getID() const; 
  char getClassification() const; 
};

class Roster 
{
  friend ostream& operator<<(ostream& os, Roster& roster);
  private: 
  Student* contents; 
  int size, capacity;

  public:
  Roster (); 
  ~Roster(); 
  int getSize() const; 
  int getCapacity() const; 
  void resetRoster(); 
  void setCapacity(int capacity); 

  void callStudent(); 
  void removeStudent(); 
  void coutContents();

  Roster& operator=(const Roster& source); 
  Roster(const Roster& source);
}; 

class Course 
{
  friend ostream& operator<<(ostream& o, Course& course); 
  
  private: 
  string name, code; 
  Roster roster; 

  public: 
  Course(); 
  void setName(string name); 
  void setCode(string code); 
  string getName() const; 
  string getCode() const; 

  void setRoster(); 
  void callRemove(); 
  void coutRoster();
  void resetRoster();  

  Course& operator=(const Course& temp); 
}; 


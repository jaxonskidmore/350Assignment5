#include <iostream>
#include "Student.h"

using namespace std;

Student::Student(){

}

Student::Student(int studentID1, string name1, string level1, string major1, double GPA1, int advisor1){
  studentID = studentID1;
  name = name1;
  level = level1;
  major = major1;
  GPA = GPA1;
  advisor = advisor1;
}

Student::~Student(){
  //delete Student;
}

void Student::printInfo(){
  cout << studentID << endl;
  cout << name << endl;
  cout << level << endl;
  cout << major << endl;
  cout << GPA << endl;
  cout << advisor << endl;
}

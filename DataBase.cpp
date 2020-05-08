#include <iostream>
#include "DataBase.h"

using namespace std;

DataBase::DataBase(){

}


void DataBase::addStudent(){
  int studentID1;
  string name1;
  string level1;
  string major1;
  double GPA1;
  int advisor1;
  cout << "enter students ID" << endl;
  cin >> studentID1;
  cout << "enter students name" << endl;
  cin >> name1;
  cout << "enter students level" << endl;
  cin >> level1;
  cout << "enter student major" << endl;
  cin >> major1;
  cout << "enter students GPA" << endl;
  cin >> GPA1;
  cout << "enter students advisor ID" << endl;
  cin >> advisor1;
  Student newStudent(studentID1, name1,level1, major1, GPA1, advisor1);
  masterStudent.insert(newStudent.studentID, newStudent);
}

void DataBase::printStudents(){
  masterStudent.printTree(masterStudent.root);
}
void DataBase::printStudentFromID(int studentID){
  masterStudent.printSingleNode(studentID);
}
void DataBase::deleteStudent(int studentID){
  masterStudent.deleteNode(studentID);
}

void DataBase::addFaculty(){
  int facultyID;
  string name;
  string level;
  string department;

  cout << "enter falculty ID" << endl;
  cin >> facultyID;
  cout << "enter faculty name" << endl;
  cin >> name;
  cout << "enter faculty level" << endl;
  cin >> level;
  cout << "enter faculty department" << endl;
  cin >> department;
  Faculty newFaculty(facultyID, name, level, department);
  masterFaculty.insert(newFaculty.facultyID, newFaculty);
}
void DataBase::printFaculty(){
  masterFaculty.printTree(masterFaculty.root);
}
void DataBase::printFacultyFromID(int facultyID){
  masterFaculty.printSingleNode(facultyID);
}
void DataBase::deleteFaculty(int facultyID){
  masterFaculty.deleteNode(facultyID);
}

/* void DataBase::printAllFacultyStudents(Faculty faculty){
  int count = faculty.
  for (int i = 0; i < 9; ++i) {
    cout << a.removeBack() << endl;
    cout << a.removeFront() << endl;
  }
} */

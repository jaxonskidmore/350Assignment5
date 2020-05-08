#include <iostream>
#include "DataBase.h"
#include <sstream>

using namespace std;

DataBase::DataBase(){

}


Student DataBase::addStudent(){
  int studentID;
  string name;
  string level;
  string major;
  double GPA;
  int advisor;
  cout << "enter students ID" << endl;
  cin >> studentID;
  cout << "enter students name" << endl;
  cin >> name;
  cout << "enter students level" << endl;
  cin >> level;
  cout << "enter student major" << endl;
  cin >> major;
  cout << "enter students GPA" << endl;
  cin >> GPA;
  cout << "enter students advisor ID" << endl;
  cin >> advisor;
  Student newStudent(studentID, name,level, major, GPA, advisor);
  masterStudent.insert(newStudent.studentID, newStudent);
  return newStudent;
}

void DataBase::printStudents(){
  masterStudent.printTree(masterStudent.root);
}
void DataBase::printStudentFromID(int studentID){
  masterStudent.printSingleNode(studentID);
}
void DataBase::deleteStudent(int studentID){
  masterStudent.deleteNode(studentID);
  // deleteLineFromStudent(studentID);  //figure this out
  /*int test = studentID;
  stringstream ss;
  ss << test << endl;
  string test2 = ss.str();
  deleteLineFromStudent(test2); */
}

Faculty DataBase::addFaculty(){
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
  return newFaculty;
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

void DataBase::studentFileWrite(Student student){
  ofstream myFile;
  myFile.open("masterStudent.txt", ios::app);
  myFile << student.studentID << " ";
  myFile << student.name << " ";
  myFile << student.level << " ";
  myFile << student.major << " ";
  myFile << student.GPA << " ";
  myFile << student.advisor << '\n';
}
void DataBase::facultyFileWrite(Faculty faculty){
  ofstream myFile;
  myFile.open("masterFaculty.txt", ios::app);
  myFile << faculty.facultyID << " ";
  myFile << faculty.name <<" ";
  myFile << faculty.level << " ";
  myFile << faculty.department << 'n';
}

void DataBase::studentFileRead(){   //reads in file and creates objects
  ifstream theFile("masterStudent.txt");

  int studentID;
  string name;
  string level;
  string major;
  double GPA;
  int advisor;

  while(theFile >> studentID >> name >> level >> major >> GPA >> advisor){
    Student newStudent(studentID, name,level, major, GPA, advisor);
    masterStudent.insert(newStudent.studentID, newStudent);
  }
}
void DataBase::facultyFileRead(){
  ifstream theFile("masterFaculty.txt");

  int facultyID;
  string name;
  string level;
  string department;

  while(theFile >> facultyID >> name >> level >> department){
    Faculty newFaculty(facultyID, name, level, department);
    masterFaculty.insert(newFaculty.facultyID, newFaculty);
  }
}
/*
void DataBase::deleteLineFromStudent(int studentID){
  ifstream fin;
  fin.open("masterStudent.txt");
  ofstream temp;
  temp.open("temp.txt");

  string line;
  cout << "test" << endl;
  int match = 0;
  while(getline(fin, line)){
    fin >> match;
    cout << match;
    if(match = studentID){
      cout << "test";
    }
  }

  //match = (string)studentID;


  temp.close();
  fin.close();
  remove("masterStudent.txt");
  rename("temp.txt", "masterStudent.txt");
}
*/

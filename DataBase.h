#include <iostream>
#include "Student.h"

using namespace std;


class DataBase{
public:

  DataBase();

  BST<Student> masterStudent;
  BST<Faculty> masterFaculty;

  void addStudent(Student student); //add to this method to ask user for input
  void printStudents();
  void printStudentFromID(int studentID);
  void deleteStudent(int studentID);
  void addFaculty(Faculty faculty); //add to this method to ask user for input
  void printFaculty();
  void printFacultyFromID(int facultyID);
  void deleteFaculty(int facultyID);


};

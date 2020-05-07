#include <iostream>
#include "Student.h"

using namespace std;


class DataBase{
public:

  DataBase();

  BST<Student> masterStudent;
  BST<Faculty> masterFaculty;

  void addStudent(Student student);
  void printStudents();
  void addFaculty(Faculty faculty);
  void printFaculty();

};

#include <iostream>
#include "Student.h"

using namespace std;


class DataBase{
public:

  DataBase();

  BST<Student> masterStudent;
  BST<Faculty> masterFaculty;

  void addStudent(); //ask user for input and adds to masterStudent
  void printStudents();
  void printStudentFromID(int studentID);
  void deleteStudent(int studentID);

  void addFaculty(); //asks user for input and adds to masterFaculty
  void printFaculty();
  void printFacultyFromID(int facultyID);
  void deleteFaculty(int facultyID);

  void printAllFacultyStudents(Faculty faculty);


};

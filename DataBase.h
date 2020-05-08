#include <iostream>
#include "Student.h"
#include <fstream> //file streams

using namespace std;


class DataBase{
public:

  DataBase();

  BST<Student> masterStudent;
  BST<Faculty> masterFaculty;

  Student addStudent(); //ask user for input and adds to masterStudent
  void printStudents();
  void printStudentFromID(int studentID);
  void deleteStudent(int studentID);

  Faculty addFaculty(); //asks user for input and adds to masterFaculty
  void printFaculty();
  void printFacultyFromID(int facultyID);
  void deleteFaculty(int facultyID);

  void printAllFacultyStudents(Faculty faculty);

  void studentFileWrite(Student student);
  void facultyFileWrite(Faculty faculty);

  void studentFileRead();
  void facultyFileRead();

  void deleteLineFromStudent(int studentID); //used with student delete method
  void deleteLineFromFaculty(); //used with faculty delete method

//  DoublyLinkedList<Student> studentList;
//  GenQueue<Student> studentQueue;


};

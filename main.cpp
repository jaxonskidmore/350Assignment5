#include <iostream>
#include <stdexcept>
#include "DataBase.h"



using namespace std;

int main(int argc, char** argv) {



  //Student(int studentID, string name, string level, string major, double GPA, int advisor)
  Student connor(2312185, "connor", "sophmore", "dataanalytics", 3.5, 2);
  Student jax(1234, "jax", "sophmore", "dataanalytics", 4.0, 5);

  Faculty shafer(12345, "shafer", "senior", "astronomy");
  Faculty shafer1(12345, "shafer", "senior", "astronomy");


  DataBase database = DataBase();
  database.studentFileRead();
  database.facultyFileRead();
  while(true){
    int input = 0;
    cout << "Enter the number of the operation you want to perform" << endl;
    cout << "1. Print all students" << endl;    //works
    cout << "2. Print all faculty members" << endl;   //works
    cout << "3. Display student using their ID number" << endl; //works
    cout << "4. Display faculty member using their ID number" << endl; //works
    cout << "5. Print a student's faculty advisor information using the student's ID number" << endl;
    cout << "6. Print all of a faculty member's students information using the faculty's  ID number" << endl;
    cout << "7. Add a new student" << endl; //works
    cout << "8. Delete a student via ID number" << endl; // works
    cout << "9. Add a new faculty member " << endl; //works
    cout << "10. Delete a faculty member via ID number" << endl; //works
    cout << "11. Change students advisor given both IDs" << endl;
    cout << "12. Remove advisee from a faculty member given both IDs" << endl;
    cout << "13. Rollback " << endl;
    cout << "14. Exit " << endl;
    cin >> input;
    if(input == 1){
      database.printStudents();
    }
    if(input == 2){
      database.printFaculty();
    }
    if(input == 3){
      int studentID;
      cout << "enter student's ID number" << endl;
      cin >> studentID;
      database.printStudentFromID(studentID);
    }
    if(input == 4){
      int facultyID;
      cout << "enter faculty's ID number" << endl;
      cin >> facultyID;
      database.printFacultyFromID(facultyID);
    }
    if(input == 7){         //segmentation error when there is already data in masterStudent - has to do with BST
      Student tempStudent = database.addStudent();
      database.studentFileWrite(tempStudent);
    }
    if(input == 8){
      int studentID;
      cout << "enter student's ID you want deleted" << endl;
      cin >> studentID;
      database.deleteStudent(studentID);
    }
    if(input == 9){
      Faculty tempFaculty = database.addFaculty();
      database.facultyFileWrite(tempFaculty);
    }
    if(input == 10){
      int facultyID;
      cout << "enter faculty's ID you want deleted" << endl;
      cin >> facultyID;
      database.deleteFaculty(facultyID);
    }
    if(input == 14){
      cout << "bye!" << endl;
      exit (EXIT_FAILURE);
    }

  }
database.~DataBase();


  //Student tempStudent = database.addStudent();
  //database.studentFileWrite(tempStudent);





//  database.printStudents();


/*
  //database.printStudentFromID(2312185);
//  database.printFacultyFromID(12345);
database.studentFileWrite(connor);
database.studentFileWrite(jax);

database.facultyFileWrite(shafer);
database.studentFileRead();
database.printStudents();



  while(!database.masterStudent.isEmpty()){

  } */
}

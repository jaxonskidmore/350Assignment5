#include <iostream>
#include "DataBase.h"

using namespace std;

DataBase::DataBase(){

}


void DataBase::addStudent(Student student){
  masterStudent.insert(student.studentID, student);
}

void DataBase::printStudents(){
  masterStudent.printTree(masterStudent.root);
}

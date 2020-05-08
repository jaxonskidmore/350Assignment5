#include <iostream>
#include "Faculty.h"

using namespace std;

Faculty::Faculty(){

}

Faculty::Faculty(int facultyID1, string name1, string level1, string department1){
  facultyID = facultyID1;
  name = name1;
  level = level1;
  department = department1;
  DoublyLinkedList<int> advisersStudentIDs;


}

Faculty::~Faculty(){

}

void Faculty::printInfo(){
  cout << facultyID << endl;
  cout << name << endl;
  cout << level << endl;
  cout << department << endl;
  DoublyLinkedList<int> advisersStudentIDs;


}

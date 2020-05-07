#include <iostream>
#include <stdexcept>
#include "DataBase.h"



using namespace std;

int main(int argc, char** argv) {
  BST<int> b;
  b.insert(1, 5);
  cout << b.search(1) << endl;
//  a.printTree(1,5);
  b.deleteNode(1);
  cout << b.search(1) << endl;

  DoublyLinkedList<int> a;

  //Student(int studentID, string name, string level, string major, double GPA, int advisor)
  Student connor(2312185, "connor", "sophmore", "data analytics", 3.5, 2);
  //connor.printInfo(connor);

  DataBase database = DataBase();
  database.addStudent(connor);
  database.printStudents();


}

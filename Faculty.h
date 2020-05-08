#ifndef FACULTY_H
#define FACULTY_H
#include <iostream>
#include "DoublyLinkedList.h"
#include "BST.h"

using namespace std;

class Faculty{
  public:
    Faculty();
    Faculty(int facultyID1, string name1, string level1, string department1);
    ~Faculty();

    void printInfo();

    DoublyLinkedList<int> advisersStudentIDs;

    int facultyID;
    string name;
    string level;
    string department;
};
#endif

#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include "Faculty.h"

using namespace std;

class Student{
  public:
    Student();
    Student(int studentID1, string name1, string level1, string major1, double GPA1, int advisor1);
    ~Student();

    void printInfo();

    int studentID;
    string name;
    string level;
    string major;
    double GPA;
    int advisor;
};
#endif

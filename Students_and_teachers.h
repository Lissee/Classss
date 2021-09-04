#include <iostream>
#include <vector>
using namespace std;

class Student {
protected:
   string name;
   string surname;
  vector<int> grades;

public:
    Student() = default;
    Student(string name, string surname) : name(name), surname(surname){}

    string GetName() {
        return name;
    }
    string GetSurname() {
        return surname;
    }
    void SetName(string name) {
        this->name = name;
    }
    void SetSurname(string surname) {
        this->surname = surname;
    }

    void SetGrade(vector<int> value) {
        grades = value;
    }

    //Определение отличника
    string Five (){
        for (int x = 0; x<grades.size(); x++) {
            if (grades[x] != 5) {
                return "Не отличник";
            }
        }
        return "Отличник";
    }
};

class Students : Student{
protected:
    vector<Student> names_1;
public:
    Students() = default;
    void SetStudents(vector<string> names, vector<string> surnames){
        Student A;
        int y = names_1.size();
        for ( int x = 0; x<names.size(); x++ ){
            names_1.push_back(A);
            names_1[y].SetName(names[x]);
            names_1[y].SetSurname(surnames[x]);
            y++;
        }
    }

    void GetStudent (int x) {
        cout << names_1[x].GetName() << " "<< names_1[x].GetSurname()<<endl;
    }
    void GetStudent () {
        for (int x = 0; x < names_1.size(); x++) {
            cout << names_1[x].GetName() << " "<< names_1[x].GetSurname()<<endl;
        }
    }

    void SetGrades (int x, vector<int> y) {
        names_1[x].SetGrade(y);
    }
    void GetGrades (int x) {
       cout <<  names_1[x].Five() <<endl;
    }
};

#ifndef UNTITLED19_STUDENTS_AND_TEACHERS_H
#define UNTITLED19_STUDENTS_AND_TEACHERS_H

#endif //UNTITLED19_STUDENTS_AND_TEACHERS_H

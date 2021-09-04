#include <iostream>
#include <vector>
using namespace std;

class Student {
protected:
   string name;
   string surname;
  vector<int> grades;
friend class Professor;

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

class Students : public Student{
protected:
    vector<Student> names_1;
    friend class Professor;
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

    void GetStudent (string name, string surname) {
        bool check = true;
        for (int x = 0; x < names_1.size(); x++) {
            if (name == names_1[x].GetName() && surname == names_1[x].GetSurname()) {
                cout << names_1[x].GetName() << " "<< names_1[x].GetSurname() << " - " << names_1[x].Five()<<endl;
                check = false;
            }
        }
        if (check) {cout << "This student is not in the database"<<endl;}
    }

    void GetStudent () {
        for (int x = 0; x < names_1.size(); x++) {
            cout << names_1[x].GetName() << " "<< names_1[x].GetSurname()<< " - " << names_1[x].Five()<<endl;
        }
    }
};

class Professor {
protected:
    string name;
    string surname;
public:
    Professor() = default;
    Professor ( string name, string surname) : name(name), surname(surname){}

    void SetGrades (string names, string surnames, vector<int> y, Students &A) {
        bool check = true;
        for (int x = 0; x < A.names_1.size(); x++){
            if (names == A.names_1[x].GetName() && surnames == A.names_1[x].GetSurname()){
        A.names_1[x].SetGrade(y);
            check = false;}
        }
        if (check) { cout << "This student is not in the database"<<endl;}
    }
};


#ifndef UNTITLED19_STUDENTS_AND_TEACHERS_H
#define UNTITLED19_STUDENTS_AND_TEACHERS_H

#endif //UNTITLED19_STUDENTS_AND_TEACHERS_H

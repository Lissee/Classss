#include <iostream>
#include <vector>
using namespace std;

int GetRandom () {
    int x;
    x =  rand () % 10;
    return x;

};

class Student {
protected:
   string name;
   string surname;
  vector<int> grades;
friend class Professor;
    friend class Parents;
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
        for (int x = 0; x<value.size(); x++) {
            grades.push_back(value[x]);
        }
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
    void GetGrade () {
        for (int x = 0; x < grades.size(); x++) {
            cout << grades[x] << " ";
        }
        cout<<endl;
    }
};

class Students : public Student{
protected:
    vector<Student> names_1;
    friend class Professor;
    friend class Para;
    friend class Parents;
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
    vector<Student> GetStudents () {
        return names_1;
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
    void SetGrades (string name, string surname, vector<int> y) {
        bool check = true;
        for (int x = 0; x < names_1.size(); x++) {
            if (name == names_1[x].GetName() && surname == names_1[x].GetSurname()) {
                names_1[x].SetGrade(y);
                bool check = false;
            }
        }
        if (check) {cout << "This student is not in the database" << endl;}
    }
    void GetGrades (string name, string surname){
        bool check = true;
        for (int x = 0; x < names_1.size(); x++) {
            if (name == names_1[x].GetName() && surname == names_1[x].GetSurname()) {
                names_1[x].GetGrade();
                check = false;
            }
        }
        if (check) {cout << "This student is not in the database" << endl;}
    }
};

class Professor {
protected:
    string name;
    string surname;
    int size = 0, maxsize = 5; //количество выставленных оценок
    bool mood = true;
    friend class Para;

public:
    Professor() = default;
    Professor ( string name, string surname) : name(name), surname(surname){}

    void SetNameProf(string name){
        this->name = name;
    }
    void SetSurnameProf(string surname){
        this->surname = surname;
    }
    int SetMaxSize() {
       return maxsize = rand()% 5;

    }
    int SetGrades (string names, string surnames, Students &A) {
            for (int x = 0; x < A.names_1.size(); x++) {
                if (names == A.names_1[x].GetName() && surnames == A.names_1[x].GetSurname()) {
                    if (size >= maxsize) {
                        size = 0;
                        if ((rand() % 2) == 1) {
                            SetMood ("Good");
                        } else { SetMood ("Bad");}
                    }
                    size ++;
                    if (this->name == "Leonid", this->surname == "Gusev") {
                        A.names_1[x].SetGrade({5});
                        return 5;
                    } else if (this->name == "Arnold", this->surname == "Ivanov") {
                            A.names_1[x].SetGrade({2});
                            return 2;
                        } else
                    if (A.names_1[x].Five() == "Отличник" && GetMood() == "Good") {
                        A.names_1[x].SetGrade({5});
                        return 5;
                    } else if (A.names_1[x].Five() == "Отличник" && GetMood() == "Bad") {
                        if (GetRandom() <= 5) { A.names_1[x].SetGrade({5});
                            return 5;}
                        else { A.names_1[x].SetGrade({4});
                            return 4;}
                    } else if (A.names_1[x].Five() == "Не отличник" && GetMood() == "Good") {
                        A.names_1[x].SetGrade({4});
                        return 4;
                    } else {
                        if (GetRandom() <= 5) {
                            A.names_1[x].SetGrade({4});
                            return  4;}
                        else { A.names_1[x].SetGrade({3});
                            return 3;}
                    }

                }
            }
            cout << "This student is not in the database" << endl;
        }

    void SetMood (string mood) {
        if (mood == "Good" ){
            this->mood = true;
        } else if (mood == "Bad") {
            this->mood = false;
        } else {
            cout << "Error! Enter again!" <<endl;
        }
    }
    string GetMood () {
        if (mood) {return "Good";}
        else {return "Bad";}
    }
};

class Professors : public Professor{
protected:
    vector<Professor> proff;
    friend class Para;
public:
    void SetProff (vector<string> name, vector<string> surname) {
        for (int x = 0; x< name.size(); x++) {
            Professor P;
            P.SetMaxSize();
            P.SetNameProf(name[x]);
            P.SetSurnameProf(surname[x]);
            proff.push_back(P);
        }
    }
};

class Para {
protected:
public:
    Professor Choice (Professors &P){
        int x = rand() % P.proff.size();
        return P.proff[x];
    }
    void Paraa (Professor &P,Students &S) {
        for (int x = 0; x < S.names_1.size(); x++) {
            if (GetRandom() <= 5) {
                cout << S.names_1[x].GetName() << " " << S.names_1[x].GetSurname() << " - присутствует" << endl;
                if (GetRandom() <= 5) {
                    cout << "Grade: " << P.SetGrades(S.names_1[x].GetName(), S.names_1[x].GetSurname(), S) << endl;
                }
            }
        }
}
void Paraa(Professors &P, Students &S) {
    for (int x = 0; x < S.names_1.size(); x++) {
        if (GetRandom() <= 5) {
            cout << S.names_1[x].GetName() << " " << S.names_1[x].GetSurname() << " - присутствует" << endl;
            if (GetRandom() <= 5) {
                cout << "Grade: " << Choice(P).SetGrades(S.names_1[x].GetName(), S.names_1[x].GetSurname(), S)
                << endl;
            }
        }
    }
}
};

class Parents {
protected:
    string name, surname;
    bool mood = true;
    vector<Student> children;
    string talkparents[11] = {"is an excellent student","is very obedient","plays the piano","plays football","likes to play DOTA 2",
                              "is not studying well","is very harmful","my children are so nice","my children study well",
                              "some of my children study well some poorly","my children study poorly"};
public:
    Parents(string name, string surname, vector<Student> children) : name(name), surname(surname), children(children) {}

   //Говорим про всех
    string Talking(string mood) {
        if (mood == "Good"){
            int k = 7 + (rand() %2);
            return  talkparents[k]+"\n";
        } else {
            int k = 8 + (rand() %2);
            return  talkparents[k]+"\n";
        }
    }
    //Говорит про конкретного
    string Talking(vector<Student> S, string name, string mood){
       for (int x =0; x < S.size(); x++) {
           if (S[x].GetName() == name) {
               if (mood == "Good" && S[x].Five() == "Отличник"){
                   int k =  (rand() %4);
                   return  name + " " + talkparents[k]+"\n";
               } else if ((mood == "Good" && S[x].Five() == "Не отличник") || (mood == "Bad" && S[x].Five() == "Отличник")){
                   int k = (rand() %6);
                   return  name + " " + talkparents[k]+"\n";
               } else {
                   int k = 3 + (rand() %2);
                   return  name + " " + talkparents[k]+"\n"; }
           }
       }
        return "You don't have a child with that name";
    }
    //Говорит про нескольких
    void Talking(vector<Student> S, string mood){
        for (int x =0; x < S.size(); x++) {
            if (GetRandom() <= 5) {
                if (mood == "Good" && S[x].Five() == "Отличник"){
                    int k =  (rand() %4);
                    cout<<  S[x].GetName() + " " + talkparents[k]<<endl;
                } else if ((mood == "Good" && S[x].Five() == "Не отличник") || (mood == "Bad" && S[x].Five() == "Отличник")){
                    int k = (rand() %6);
                    cout<<  S[x].GetName() + " " + talkparents[k]<<endl;
                } else {
                    int k = 3 + (rand() %2);
                    cout<<  S[x].GetName() + " " + talkparents[k]<<endl; }
            }
        }
    }
    //Говорит про рандомного
    string Talking(vector<Student> S, string mood, int x){
                    if (mood == "Good" && S[x].Five() == "Отличник") {
                        int k = (rand() % 4);
                        return S[x].GetName() + " " + talkparents[k]+"\n";
                    } else if ((mood == "Good" && S[x].Five() == "Не отличник") ||
                               (mood == "Bad" && S[x].Five() == "Отличник")) {
                        int k = (rand() % 6);
                        return S[x].GetName() + " " + talkparents[k]+"\n";
                    } else {
                        int k = 3 + (rand() % 2);
                        return S[x].GetName() + " " + talkparents[k] +"\n";
                    }
    }

    void SetMood (string mood) {
        if (mood == "Good" ){
            this->mood = true;
        } else if (mood == "Bad") {
            this->mood = false;
        } else {
            cout << "Error! Enter again!" <<endl;
        }
    }

    string GetMood () {
        if (mood) {return "Good";}
        else {return "Bad";}
    }
};

#ifndef UNTITLED19_STUDENTS_AND_TEACHERS_H
#define UNTITLED19_STUDENTS_AND_TEACHERS_H

#endif //UNTITLED19_STUDENTS_AND_TEACHERS_H

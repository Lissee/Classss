#include <iostream>
#include "Students_and_teachers.h"

using namespace std;

int main() {
//1-ый этап + 2 этап + 3 этап + 4 этап
    Students S;
    Professor P("Alexander", "Vladimirov");
    S.SetStudents({"Anton", "Timur", "Lena", "Anastasia", "Vadim", "Ira", "Vika", "Egor"},
                  {"Shevchenko", "Borisov", "Avdaseva","Lisitcyna", "Dyagilev", "Safonova", "Safonova", "Dyagilev"});
    cout<<endl;
    for (int x = 0; x < 3; x++) {
        P.SetGrades("Timur", "Borisov", S);
        S.GetStudent("Timur", "Borisov");
        P.SetGrades("Lena", "Avdaseva", S);
        S.GetStudent("Lena", "Avdaseva");
        S.GetGrades("Timur", "Borisov");
        S.GetGrades("Lena", "Avdaseva");
    }
    P.SetMood("Bad");
    for (int x = 0; x < 3; x++) {
        P.SetGrades("Timur", "Borisov", S);
        S.GetStudent("Timur", "Borisov");
        P.SetGrades("Lena", "Avdaseva", S);
        S.GetStudent("Lena", "Avdaseva");
        S.GetGrades("Timur", "Borisov");
        S.GetGrades("Lena", "Avdaseva");
    }
    Para R;
    R.Paraa(P,S);
    return 0;
}

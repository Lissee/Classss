#include <iostream>
#include "Students_and_teachers.h"

using namespace std;

int main() {
    srand(0);
//1-ый этап + 2 этап + 3 этап + 4 этап + 5 этап + 6 этап
    Students S;
    Professor P_Alex("Alexander", "Vladimirov");
    Professor P_Leo("Leonid", "Gusev");
    Professor P_Arn("Arnold", "Ivanov");
    S.SetStudents({"Anton", "Timur", "Lena", "Anastasia", "Vadim", "Ira", "Vika", "Egor"},
                  {"Shevchenko", "Borisov", "Avdaseva","Lisitcyna", "Dyagilev", "Safonova", "Safonova", "Dyagilev"});
    cout<<endl;
    P_Alex.SetMaxSize();
    for (int x = 0; x < 3; x++) {
        P_Alex.SetGrades("Timur", "Borisov", S);
        S.GetStudent("Timur", "Borisov");
        P_Alex.SetGrades("Lena", "Avdaseva", S);
        S.GetStudent("Lena", "Avdaseva");
        S.GetGrades("Timur", "Borisov");
        S.GetGrades("Lena", "Avdaseva");
    }

    for (int x = 0; x < 3; x++) {
        P_Alex.SetGrades("Timur", "Borisov", S);
        S.GetStudent("Timur", "Borisov");
        P_Alex.SetGrades("Lena", "Avdaseva", S);
        S.GetStudent("Lena", "Avdaseva");
        S.GetGrades("Timur", "Borisov");
        S.GetGrades("Lena", "Avdaseva");
    }
    Professors P;
    Para R;
    R.Paraa(P_Alex, S);
    cout <<"------------------------"<<endl;
    R.Paraa(P_Arn, S);
    cout <<"------------------------"<<endl;
    P.SetProff({"Anton", "Leonid", "Lena", "Arnold", "Vadim", "Ira"},
               {"Shevchenko", "Gusev", "Avdaseva","Ivanov", "Dyagilev", "Safonova"});

    R.Paraa(P, S);
    return 0;
}

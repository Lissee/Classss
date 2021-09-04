#include <iostream>
#include "Students_and_teachers.h"

using namespace std;

int main() {
//1-ый этап + 2 этап + 3 этап
    Students S;
    Professor P("Alexander", "Vladimirov");
    S.SetStudents({"Anton", "Timur", "Lena"}, {"Shevchenko", "Borisov", "Avdaseva"});
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
    return 0;
}

#include <iostream>
#include "Students_and_teachers.h"

using namespace std;

int main() {
//1-ый этап + 2 этап
    Students S;
    Professor P("Alexander", "Vladimirov");
    S.SetStudents({"Anton", "Timur", "Lena"}, {"Shevchenko", "Borisov", "Avdaseva"});
    cout<<endl;
    P.SetGrades("Timur", "Borisov", {5, 5, 5}, S);
    S.GetStudent("Timur", "Borisov");
    P.SetGrades("Lena", "Avdaseva", {5, 5, 5, 3, 5}, S);
    S.GetStudent("Lena", "Avdaseva");

    return 0;
}

#include <iostream>
#include "Students_and_teachers.h"

using namespace std;

int main() {
//1-ый этап
    Students R;
    R.SetStudents({"Anton", "Timur", "Lena"},{"Shevchenko", "Borisov", "Avdaseva"});
    cout<<endl;
    R.GetStudent(0);
    R.SetGrades(0, {5, 5, 5});
    R.GetGrades(0);
    cout <<"---------------------" <<endl;
    R.GetStudent(1);
    R.SetGrades(1, {5, 5,5,3,5});
    R.GetGrades(1);

    return 0;
}

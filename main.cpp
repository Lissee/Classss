#include <iostream>
#include "Students_and_teachers.h"

using namespace std;

int main() {
    srand(0);
//1-ый этап + 2 этап + 3 этап + 4 этап + 5 этап + 6 этап + 7 этап + 8 этап + 9 этап
//Создаем студентов
    Students Petrovi, Sidorovi, Ivanovi, Borisovi, Shevchenko, Anitovi;

    Petrovi.SetStudents({"Anton", "Timur", "Lena"},
                        {"Petrov", "Petrov", "Petrova"});
    Sidorovi.SetStudents({"Ekaterina"},{"Sidorova"});
    Ivanovi.SetStudents({"Anastasia","Ira","Andrei","Alex"},{"Ivanova","Ivanova","Ivanov","Ivanov"});
    Borisovi.SetStudents({"Igor","Ira"},{"Borisov","Borisova"});
    Shevchenko.SetStudents({"Lissa","Dima","Alex"},{"Shevchenko","Shevchenko","Shevchenko"});
    Anitovi.SetStudents({"Lissa","Dima","Alex"},{"Anitova","Anitov","Anitov"});

    Students vse;
    vse.SetStudents(Petrovi.GetVector());
    vse.SetStudents(Sidorovi.GetVector());
    vse.SetStudents(Ivanovi.GetVector());
    vse.SetStudents(Borisovi.GetVector());
    vse.SetStudents(Shevchenko.GetVector());
    vse.SetStudents(Anitovi.GetStudents());

    //Присваиваем студентов родителям
    Grandmother Anitova ("Anna", "Anitova",Anitovi.GetStudents());
    Parents Petrova_P( "Anna","Petrova", Petrovi.GetStudents());
    Parents Sidorova_P("Kira","Sidorova",  Sidorovi.GetStudents());
    Parents Ivanov_P("Andrey","Ivanov",  Ivanovi.GetStudents());
    Parents Borisova_P("Lera","Borisov",  Borisovi.GetStudents());
    Parents Shevchenko_P("Alex","Shevchenko",  Petrovi.GetStudents());

    //Создаем преподавателей
    Professor P_1("Alexander", "Vladimirov");
    Professor P_2("Leonid", "Gusev");
    Professor P_3("Arnold", "Ivanov");
    Professor P_4("Alexander", "Borisov");
    Professor P_5("Irina", "Guseva");
    Professor P_6("Olga", "Avdaseva");

    Professors P;
    //Проводим пары
    Para R;
    R.Paraa(P_1, vse);
    cout <<"------------------------"<<endl;
    R.Paraa(P_2, vse);
    cout <<"------------------------"<<endl;
    R.Paraa(P_3, vse);
    cout <<"------------------------"<<endl;
    R.Paraa(P_5, vse);
    cout <<"------------------------"<<endl;
//Собрание
    parent_teacher_meeting({P_2, P_4, P_5},{Sidorova_P,Ivanov_P,Shevchenko_P}, {Anitova});

    return 0;
}

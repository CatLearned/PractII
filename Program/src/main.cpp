/* 
    Основа работы с Базой данных велоклуба.
    Поля записи: Фамилия, имя, Отчество, Тип велосипеда(MTP, Дорожный, Гибрид, Электро), стаж участия в велоклубе
    Структура записи расположена в "Struct.h"
    
    функции:
    free_memoty - удаляет вектор
    int main - Содержит цикл в котором анализируется ввод. Значения вызывают определённые функции.
               Выход производится после ввода "!ext".
               Данная функция выполняет роль меню.
    
    vector<man> members - хранилище записей в заданной структуре man
*/

//#include "Struct.h"

#include <string>
#include <iostream>
#include <vector>

#include "members.h"

using namespace std;



int main()
{
    bool ext = false;
    string s = "";
    do
    {
        cout << ">"; cin >> s;
        if     (s == "!add") { add_member(); }
        else if(s == "!del") { del_member(); }
        else if(s == "!chg") { change_members(); }
        else if(s == "!prt") { print_all(); }
        else if(s == "!frd") { readfile();}
        else if(s == "!fwr") { savefile();}
        else if(s == "!hpl") { show_help();}
        else if(s == "!ext") { ext = true;}
        else {cout << "Wrong argement" << endl;}
    }
    while(!ext);
    
    free_memory;
    
    return 0;
}

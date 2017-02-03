/* src/struct.h.  Generated from struct.h.in by configure.  */
#include <string>

using namespace std;

#ifndef STRUCT_INCLUDED
#define STRUCT_INCLUDED

// man - структура записи члена велосипедного клуба.

struct man
{
    int id;                     // Номер для работы с записями. Идентификатор участника
    string fam, name, surname;  // ФИО участника
    int typebike;               // Тип велосипеда участника. 
                                // (Ограничен четыремя значениями: 1 - MTP, 2 - Дорожный, 3 - Гибрид, 4 - Электро)
    int ages;                   // Стаж участника
};

#endif

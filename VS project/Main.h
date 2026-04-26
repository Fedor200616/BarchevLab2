#include <iostream>
#include <windows.h>

#ifndef HEADER_H
#define HEADER_H

struct data
{
    std::string name;
    std::string pass;
    std::string group;
    std::string number;
};

/// <summary>
/// Функция вывода на экран меню
/// </summary>
/// <param name="menu[]">Массив полей меню</param>
/// <param name="size">Размер массива полей меню</param>
int print_menu(const std::string menu[], int size);


#endif 
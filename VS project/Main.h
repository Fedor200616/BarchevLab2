#include <iostream>
#include <windows.h>

#ifndef HEADER_H
#define HEADER_H

const int char_length = 255;
const int Aa = 32;
const int pass_length = 20;

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
int print_menu(std::string menu[], int size);


#endif 
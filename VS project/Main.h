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

int print_menu(std::string menu[], int size); //Функция вывода на экран меню


#endif 
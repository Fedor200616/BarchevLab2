#include <iostream>
#include <windows.h>
#include <conio.h> //чтение клваиш
#include <vector>

#ifndef GENERAL_H
#define GENERAL_H


int print_menu(std::string menu[], int size); //функция вывода на экран меню и работы с ним
std::vector<data> fillData(); // функция образует большой вектор со всеми именами и паролями студентов
std::string name_filename(); //выбор названия текствого файла имен или паролей 



#endif
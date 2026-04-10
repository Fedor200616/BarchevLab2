#include <iostream>
#include <windows.h>
#include <conio.h> 
#include <filesystem>


#ifndef GENERAL_H
#define GENERAL_H

//namespace fs = std::filesystem;

int work_menu(); // Обрабатываем запросы пользователя
int inop_funct(int r); // Функция высвечивает окно INOP если данная часть не готова, делает ретюрн аргумента
int print_arr(const std::vector<data>& vec, std::string sep = " | ", int strnum = 1, int keysel = 1); // Печатаем массив структур data на экран, для отладки

#endif

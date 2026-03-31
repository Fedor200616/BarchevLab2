#include <iostream>
#include <windows.h>
#include <conio.h> 
#include <filesystem>


#ifndef GENERAL_H
#define GENERAL_H

//namespace fs = std::filesystem;

int print_menu(std::string menu[], int size); //Функция вывода на экран меню
int work_menu(); // Обрабатываем запросы пользователя
int inop_funct(int r); // Функция высвечивает окно INOP если данная часть не готова, делает ретюрн аргумента
int print_arr(std::vector<data>& vec); // Печатаем массив структур data на экран, для отладки

#endif

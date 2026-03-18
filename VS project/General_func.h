#include <iostream>
#include <windows.h>
#include <conio.h> 
#include <filesystem>


#ifndef GENERAL_H
#define GENERAL_H

//namespace fs = std::filesystem;

int print_menu(std::string menu[], int size); //Функция вывода на экран меню
int work_menu(); // Обрабатываем запросы пользователя
int inop_funct();
int print_arr(std::vector<data>& vec);


#endif

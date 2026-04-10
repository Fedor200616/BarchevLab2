#pragma once
#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h> 
#include <filesystem>

#ifndef SEARCH_H
#define SEARCH_H

int main_search(const std::vector<data>& vec); // Функция для поиска данных пользователя, принимает массив структур data для поиска
int print_menuopt(const std::vector<data>& search_result, std::string search_str); // Функция для вывода на экран меню, принимает массив структур data для вывода и строку для поиска
std::string key_analyse(std::string search_str, int key); // Функция для анализа нажатых клавиш, принимает строку для поиска и код нажатой клавиши, возвращает измененную строку для поиска
std::vector<data> search(const std::vector<data>& result, std::string str); // Функция для поиска данных, принимает массив структур data для поиска и строку для поиска, возвращает количество найденных совпадений

//Ниже служебные функции для поиска совпадения в отедльной строке
int search_name(data d, std::string str);
int search_pass(data d, std::string str);
int search_group(data d, std::string str);
int search_number(data d, std::string str);

#endif

#pragma once
#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h> 
#include <filesystem>

#ifndef SEARCH_H
#define SEARCH_H

int main_search(const std::vector<data>& vec); // ‘ункци€ дл€ поиска данных пользовател€, принимает массив структур data дл€ поиска
int print_menuopt(const std::vector<data>& search_result, std::string search_str); // ‘ункци€ дл€ вывода на экран меню, принимает массив структур data дл€ вывода и строку дл€ поиска
std::string key_analyse(std::string search_str, int key); // ‘ункци€ дл€ анализа нажатых клавиш, принимает строку дл€ поиска и код нажатой клавиши, возвращает измененную строку дл€ поиска
std::vector<data> search(const std::vector<data>& result, std::string str); // ‘ункци€ дл€ поиска данных, принимает массив структур data дл€ поиска и строку дл€ поиска, возвращает количество найденных совпадений

#endif

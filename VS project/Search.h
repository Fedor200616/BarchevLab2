#pragma once
#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h> 
#include <filesystem>

#ifndef SEARCH_H
#define SEARCH_H

/// <summary>
/// Основная функция для поиска данных пользователя
/// </summary>
/// <param name="vec">Вектор данных пользователей</param>
/// <returns>1</returns>
int main_search(const std::vector<data>& vec); // Функция для поиска данных пользователя, принимает массив структур data для поиска

/// <summary>
/// Функция для вывода меню на экран 
/// </summary>
/// <param name="search_result">Вектор даных совпадений с поиском</param>
/// <param name="search_str">Строка поиска</param>
/// <returns>1 для просмотра результатов, 0 иначе</returns>
int print_menuopt(const std::vector<data>& search_result, std::string search_str); // Функция для вывода на экран меню, принимает массив структур data для вывода и строку для поиска

/// <summary>
/// Функция для анализа нажатых клавиш
/// </summary>
/// <param name="search_str">Строка поиска</param>
/// <param name="key">Нажатая кнопка</param>
/// <returns>Измененная строка поиска</returns>
std::string key_analyse(std::string search_str, int key); // Функция для анализа нажатых клавиш, принимает строку для поиска и код нажатой клавиши, возвращает измененную строку для поиска

/// <summary>
/// Функция для поиска данных
/// </summary>
/// <param name="result">Вектор данных поиска</param>
/// <param name="str">Строка поиска</param>
/// <returns>Результат поиска</returns>
std::vector<data> search(const std::vector<data>& result, std::string str); // Функция для поиска данных, принимает массив структур data для поиска и строку для поиска, возвращает количество найденных совпадений

/// <summary>
/// Функция вывода результатов поиска В меню поиска
/// </summary>
/// <param name="search_result">Вектор даных совпадений с поиском</param>
/// <returns>0</returns>
int print_search_res(const std::vector<data>& search_result);

//Ниже служебные функции для поиска совпадения в отедльной строке
int search_name(data d, std::string str);
int search_pass(data d, std::string str);
int search_group(data d, std::string str);
int search_number(data d, std::string str);

/// <summary>
/// Функция вывода на экран разделителя
/// </summary>
/// <returns></returns>
int separator();

#endif

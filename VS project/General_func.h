#include <iostream>
#include <windows.h>
#include <conio.h> 
#include <filesystem>


#ifndef GENERAL_H
#define GENERAL_H

const int arr_num = 20; // Количество строк при выводе
//namespace fs = std::filesystem;

/// <summary>
/// Обрабатываем запросы пользователя
/// </summary>
/// <returns>Выбранное пользователем поле</returns>
int work_menu();

/// <summary>
/// Функция высвечивает окно INOP если данная часть не готова
/// </summary>
int inop_funct(); // Функция высвечивает окно INOP если данная часть не готова

/// <summary>
/// Печатаем массив структур data на экран
/// </summary>
/// <param name="vec">Вектор структур данных для вывода</param>
/// <param name="sep">Разделитель между столбцами при выводе</param>
/// <param name="strnum">Флаг отображения информации о строках и страницах</param>
/// <param name="keysel">Флаг включения управления страницами через клавиатуру</param>
/// <returns>0</returns>
int print_arr(const std::vector<data>& vec, std::string sep = " | ", int strnum = 1, int keysel = 1); // Печатаем массив структур data на экран

/// <summary>
/// Функция вывода инструкции на экран
/// </summary>
/// <returns>0</returns>
int instruction();

#endif

#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h> 
#include <filesystem>

#ifndef OUTPUT_H
#define OUTPUT_H

namespace fs = std::filesystem;

struct menuopt {
	std::string option1;
	std::string option2;
	bool param;
};

enum menu_param_index {
	filetype = 0,
	only_full = 1,
	sep_type = 2,
	save_res = 3,
	exit_output = 4,
};

/// <summary>
/// Функция для вывода данных на экран
/// </summary>
/// <param name="vec">Вектор данных для вывода</param>
/// <returns>0</returns>
int output_menu(const std::vector<data>& vec); // Функция для вывода данных на экран, принимает массив структур data для вывода

/// <summary>
/// Функция для вывода на экран меню
/// </summary>
/// <param name="menu">массив информации menuopt</param>
/// <param name="size">Размер массива</param>
/// <returns>0</returns>
int print_menuopt(menuopt menu[], int size); // Функция для вывода на экран меню, принимает массив структур menuopt для вывода и его размер

/// <summary>
///	Функция для вывода данных в файл
/// </summary>
/// <param name="vec">Вектор данных для вывода</param>
/// <param name="menu">Выбранные параметра menuopt</param>
/// <returns>0</returns>
int output_to_file(const std::vector<data>& vec, menuopt menu[]); // Функция для вывода данных в файл, принимает массив структур data для вывода и тип файла для сохранения

/// <summary>
/// Функция для сохранения данных в текстовый файл
/// </summary>
/// <param name="vec">Вектор данных для вывода</param>
/// <param name="save_path">Путь сохранения</param>
/// <param name="separator">Разделительный знак</param>
/// <returns>0</returns>
int SaveToTXT(const std::vector<data>& vec, fs::path save_path, std::string separator = " | "); // Функция для сохранения данных в текстовый файл, принимает массив структур data для сохранения и путь для сохранения

/// <summary>
/// Функция для сохранения данных в CSV файл,
/// </summary>
/// <param name="vec">Вектор данных для вывода</param>
/// <param name="save_path">Путь сохранения</param>
/// <returns>0</returns>
int SaveToCSV(const std::vector<data>& vec, fs::path save_path); // Функция для сохранения данных в CSV файл, принимает массив структур data для сохранения и путь для сохранения

/// <summary>
/// Функция для фильтрации данных
/// </summary>
/// <param name="vec">Вектор данных для фильтрации</param>
/// <returns></returns>
std::vector<data> filter_data(const std::vector<data>& vec); // Функция для фильтрации данных, принимает массив структур data для фильтрации и возвращает отфильтрованный массив

#endif
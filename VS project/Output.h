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

int output_menu(const std::vector<data>& vec); // Функция для вывода данных на экран, принимает массив структур data для вывода
int print_menuopt(menuopt menu[], int size); // Функция для вывода на экран меню, принимает массив структур menuopt для вывода и его размер
int output_to_file(const std::vector<data>& vec, menuopt menu[]); // Функция для вывода данных в файл, принимает массив структур data для вывода и тип файла для сохранения
int SaveToTXT(const std::vector<data>& vec, fs::path save_path, std::string separator = " | "); // Функция для сохранения данных в текстовый файл, принимает массив структур data для сохранения и путь для сохранения
int SaveToCSV(const std::vector<data>& vec, fs::path save_path); // Функция для сохранения данных в CSV файл, принимает массив структур data для сохранения и путь для сохранения
std::vector<data> filter_data(const std::vector<data>& vec); // Функция для фильтрации данных, принимает массив структур data для фильтрации и возвращает отфильтрованный массив



#endif
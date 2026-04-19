#include <iostream>
#include <vector>
#include <windows.h>
#include <filesystem>
#include <commdlg.h>
#include <fstream>
#include <string>
#include <sstream>

#include "main.h"
#include "Output.h"


#ifndef FILESYS_H
#define FILESYS_H

namespace fs = std::filesystem;

/// <summary>
/// Функция обьединяет файлы в массив структур
/// </summary>
/// <param name="secname">Путь к файлу фамилий</param>
/// <param name="password">Путь к файлу паролей</param>
/// <returns>Вектор данных пользователей</returns>
std::vector<data> fillData(fs::path secname, fs::path password); // Функция обьединяет файлы в массив структур data

/// <summary>
/// Фунция высвечивает диалоговое окно проводника для выбора файла для открытия
/// </summary>
/// <returns>Путь к выбранному файлу</returns>
fs::path OpenFileDialog(); // Фунция высвечивает диалоговое окно проводника для выбора файла

/// <summary>
/// Функция для вставки данных паролей в массив всех данных
/// </summary>
/// <param name="vec">Вектор данных пользователей без пароля</param>
/// <param name="d">Структура данных пользователя без фамилии</param>
/// <returns>Обьединяет поля, возвращает 0</returns>
int compare(std::vector<data>& vec, data d); //Функция для вставки данных паролей в массив всех данных

/// <summary>
/// Фунция высвечивает диалоговое окно проводника для выбора файла для сохранения
/// </summary>
/// <param name="file_type">Расширение файла</param>
/// <returns>Путь к выбранному файлу</returns>
fs::path SaveFileDialog(int file_type); // Фунция высвечивает диалоговое окно проводника для выбора файла

#endif

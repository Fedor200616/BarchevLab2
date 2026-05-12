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

namespace fs = std::filesystem;

#ifndef FILESYS_H
#define FILESYS_H

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
/// <param name="filetype">Тип файла:  1 - имя, 2 - пароль</param>
/// <returns>Путь к выбранному файлу</returns>
fs::path OpenFileDialog(const int filetype); // Фунция высвечивает диалоговое окно проводника для выбора файла

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

/// <summary>
/// Проверяем файл фамилий или паролей ли это, открывается ли он, соответсвие по крайней мере первой строки формату
/// </summary>
/// <param name="file">Путь к файлу</param>
/// <param name="filetype">Тип файла:  1 - имя, 2 - пароль</param>
/// <returns>1 если файл соответсвует требованиям,
/// 0 файл другого формата, но открывается и содержит приемлемые символы в первой строке,
///	-1 если файл не открывается,
/// -2 если число | в первой строке не соответствует формату,
/// -3 файл пустой либо не найдено валидныдных символов.
/// </returns>
int is_valid_file(fs::path file, int filetype);

/// <summary>
/// Функция изменяет пустое поле на поле Нет данных
/// </summary>
/// <param name="result">Вектор данных пользователей</param>
void AdNodata(std::vector<data>& result);

#endif

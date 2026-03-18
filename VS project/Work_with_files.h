#include <iostream>
#include <vector>
#include <windows.h>
#include <filesystem>
#include <commdlg.h>
#include <fstream>
#include <string>
#include <sstream>

#include "main.h"


#ifndef FILESYS_H
#define FILESYS_H

namespace fs = std::filesystem;

std::vector<data> fillData(fs::path secname, fs::path password); // Функция обьединяет файлы в массив структур data
fs::path FileDialog(); // Фунция высвечивает диалоговое окно проводника для выбора файла

#endif

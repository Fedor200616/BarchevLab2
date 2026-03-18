#include <iostream>
#include <vector>
#include <windows.h>
#include <filesystem>
#include <commdlg.h>

#ifndef FILESYS_H
#define FILESYS_H

namespace fs = std::filesystem;

//std::vector<data> fillData(); // ôóíêöèÿ îáðàçóåò áîëüøîé âåêòîð ñî âñåìè èìåíàìè è ïàðîëÿìè ñòóäåíòîâ
fs::path FileDialog(); //âûáîð íàçâàíèÿ òåêñòâîãî ôàéëà èìåí èëè ïàðîëåé 

#endif

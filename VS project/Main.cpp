#define _CRT_SECURE_NO_WARNINGS
#include "Main.h"
#include "General_func.h"
#include "Work_with_files.h"

int main()
{
    //system("chcp 65001");
    SetConsoleCP(1251);       // входная кодировка
    SetConsoleOutputCP(1251); // выходная кодировка
    setlocale(LC_ALL, "");
    work_menu();


    return 0;
}

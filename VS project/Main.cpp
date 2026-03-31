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

int print_menu(std::string menu[], int size) { //функция вывода на экран меню
	int selected = 0;
	bool isdone = false;
	int key = 0;


	while (!isdone) {
		system("cls");
		for (int i = 0; i < size; i++) {
			if (i == selected) {
				std::cout << "--> " << menu[i] << '\n';
			}
			else {
				std::cout << "    " << menu[i] << '\n';
			}
		}

		key = _getch();
		if (key == 224)
		{
			key = _getch();

			if (key == 72) { // Стрелка вниз
				if (selected != 0) {
					selected--;
				}
				else
					selected = size - 1;

			}
			else if (key == 80) { // стрелка вверх
				if (selected != (size - 1)) {
					selected++;
				}
				else
					selected = 0;
			}
		}
		else if (key == 13) { // Enter
			isdone = true;
		}

	}
	return selected;
}

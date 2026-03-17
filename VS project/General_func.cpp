#define _CRT_SECURE_NO_WARNINGS
#include "Main.h"
#include "General_func.h"


int print_menu(std::string menu[], int size) {
	int selected = 0;
	bool isdone = false;
	int key = 0;


	while (!isdone) {
		system("cls");
		for (int i = 0; i < size; i++) {
			if (i == selected){
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

			if (key == 72) {
				if (selected != 0) {
					selected--;   // вверх
				}

			}
			else if (key == 80) {
				if (selected != (size - 1)){
					selected++;   // вниз
				}
			}
		}
		else if (key == 13) {
			isdone = true;
		}

	}
	return selected;
}

std::vector<data> fillData() {
	std::vector<data> result; 
	
									//Собирает данные из std::string name_filename();
	return result;
}

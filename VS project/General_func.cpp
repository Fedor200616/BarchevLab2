#define _CRT_SECURE_NO_WARNINGS
#include "Main.h"
#include "General_func.h"
#include "Work_with_files.h"


int print_menu(std::string menu[], int size) { //функция вывода на экран меню
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
		else if (key == 13) {
			isdone = true;
		}

	}
	return selected;
}

int work_menu() {
	int sel = 1;
	int isdone = 0;

	std::vector<data> result;

	std::string main_menu[] = {
	"Выберите файл имен...",
	"Выберите файл паролей...",
	"Вывод данных пользователя",
	"Полный вывод данных",
	"Выход из программы"
	};

	int menuSize = sizeof(main_menu) / sizeof(main_menu[0]);
	
	fs::path secname_file = "0";
	fs::path password_file = "0";


	while (!isdone) {
		sel = 1;
		int namechanged = 0; //флаг смены имени какого либо из файлов
		
		
		sel = print_menu(main_menu, menuSize);
		switch (sel)
		{
		case 0: 
			system("cls");
			std::cout << "Выберите файл фамилий во всплывающем окне \n";
			secname_file = FileDialog();
			if (secname_file != "0") {
				main_menu[0] = std::string("Выбран файл имен ") + secname_file.string();
				namechanged = 1;
			}

			break;
		case 1:
			system("cls");
			std::cout << "Выберите файл паролей во всплывающем окне \n";
			password_file = FileDialog();
			if (password_file != "0") {
				main_menu[1] = std::string("Выбран файл паролей ") + password_file.string();
				namechanged = 1;
			}
			break;
		case 2: // TODO вывод данных пользователя
			inop_funct(1);
			break; 
		case 3: // TODO вывод всех данных
			print_arr(result);
			break;
		default:
			sel = 0;
			isdone = 1;
			break;
		}

		if (namechanged && password_file != "0" && secname_file != "0") {
			system("cls");
			std::cout << "Выполняется обработка файлов \n";
			result = fillData(secname_file, password_file);
		}

	}


	return sel;
}

int inop_funct(int r) {
	system("cls");
	std::cout << "Разработчик уже работает над этой функцией и она появится позже\n";
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 20; j++) {
			std::cout << "INOP ";
		}
		std::cout << '\n';
	}
	std::cout << "Нажмите любую кнопку чтобы продолжить\n";
	_getch();
	return r;

}

int print_arr(std::vector<data>& vec) {
	system("cls");
	std::cout << vec.size() << '\n';
	for (int i = 0; i < vec.size(); i++) {
		std::cout << vec[i].name << " " << vec[i].pass << " " << vec[i].group << " " << vec[i].number << '\n';
	}
	std::cout << "Нажмите любую кнопку чтобы продолжить\n";
	_getch();
	return 0;
}
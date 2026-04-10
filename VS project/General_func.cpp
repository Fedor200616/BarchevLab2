#define _CRT_SECURE_NO_WARNINGS
#include "Main.h"
#include "General_func.h"
#include "Work_with_files.h"
#include "Output.h"
#include "Search.h"



int work_menu() {
	int sel = 1;
	int isdone = 0;

	std::vector<data> result;

	std::string main_menu[] = {
	"Выберите файл имен...",
	"Выберите файл паролей...",
	"Поиск данных пользователя",
	"Полный вывод данных в файл",
	"Инструкция по использованию",
	"Выход из программы"
	};

	const int menuSize = sizeof(main_menu) / sizeof(main_menu[0]);
	
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
			secname_file = OpenFileDialog();
			if (secname_file != "0") {
				main_menu[0] = std::string("Выбран файл имен ") + secname_file.string();
				namechanged = 1;
			}

			break;
		case 1:
			system("cls");
			std::cout << "Выберите файл паролей во всплывающем окне \n";
			password_file = OpenFileDialog();
			if (password_file != "0") {
				main_menu[1] = std::string("Выбран файл паролей ") + password_file.string();
				namechanged = 1;
			}
			break;
		case 2: // TODO вывод данных пользователя
			if (!result.empty()) {
				main_search(result);
			}
			else {
				system("cls");
				std::cout << "Нет данных для вывода, выберите файлы и дождитесь их обработки\n";
				std::cout << "Нажмите любую кнопку чтобы продолжить\n";
				_getch();
			}
			break; 
		case 3: // TODO вывод всех данных
			if (!result.empty()) {
				output_menu(result);
			}
			else {
				system("cls");
				std::cout << "Нет данных для вывода, выберите файлы и дождитесь их обработки\n";
				std::cout << "Нажмите любую кнопку чтобы продолжить\n";
				_getch();
			}
			break;
		case 4: // TODO инструкция
			inop_funct(1);
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

int print_arr(const std::vector<data>& vec, std::string sep, int strnum, int keysel) {
	
	if (strnum) {
		system("cls");
		std::cout << "Всего строк: " << vec.size() << '\n';
	}

	std::cout << std::left << std::setw(20) << "Имя" << sep
		<< std::left << std::setw(12) << "Группа" << sep
		<< std::left << std::setw(2) << "Номер" << sep
		<< std::left << std::setw(20) << "Пароль" << "\n"; // Заголовок

	for (const auto& d : vec) {
		std::cout << std::left << std::setw(20) << d.name << sep
			<< std::left << std::setw(12) << d.group << sep
			<< std::left << std::setw(2) << d.number << sep
			<< std::left << std::setw(20) << d.pass << "\n";
	}
	if (keysel)
		std::cout << "Нажмите любую кнопку чтобы продолжить\n";
	_getch();
	return 0;
}
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
		case 2:
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
		case 3:
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
			instruction();
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

int inop_funct() {
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
	return 0;

}

int print_arr(const std::vector<data>& vec, std::string sep, int strnum, int keysel) {
	const int list_num = vec.size() / arr_num;
	int page_num = 0;
	bool isdone = false;
	int get_char = 0;

	while (!isdone) {
		if (strnum) {
			system("cls");
			std::cout << "Всего строк: " << vec.size() << '\n';
			if (list_num > 0)
				std::cout << "Страница: " << (page_num + 1) << " из " << (list_num + 1) << '\n';
		}
		else {
			isdone = true;
		}
		std::cout << std::left << std::setw(20) << "Имя" << sep
			<< std::left << std::setw(12) << "Группа" << sep
			<< std::left << std::setw(5) << "Номер" << sep
			<< std::left << std::setw(20) << "Пароль" << "\n"; // Заголовок

		int start_index = page_num * arr_num;
		int end_index = arr_num;
		if (vec.size() / arr_num == page_num)
			end_index = vec.size() % arr_num;
		for (int i = start_index; i < start_index + end_index; i++) {
			std::cout << std::left << std::setw(20) << vec[i].name << sep
				<< std::left << std::setw(12) << vec[i].group << sep
				<< std::left << std::setw(5) << vec[i] .number << sep
				<< std::left << std::setw(20) << vec[i].pass << "\n";

		}
		if (keysel) {
			separator();
			std::cout << "Используйте стрелки влево и вправо для переключения страниц\n";
			std::cout << "Нажмите ESC чтобы продолжить\n";
			get_char = _getch();
			if (get_char == 224) {
				get_char = _getch();
				if (get_char == 75) { // Стрелка влево
					if (page_num != 0) {
						page_num--;
					}
				}
				else if (get_char == 77) { // стрелка вправо
					if (page_num != (list_num)) {
						page_num++;
					}
				}
			}
			else if (get_char == 27) { // ESC
				isdone = true;
			}
		}
	}
	return 0;
}

int instruction() { // Функция инструкции пользователю
	std::string line;

	std::ifstream ifile("instruction.md"); // Открытие файла инструкции
	system("cls");
	if (!ifile) {
		
		printf("Ошибка: файл instruction.md не найден!\n");
		printf("Нажмите любую клавишу для возврата в меню...\n");
		_getch();
		return 0;
	}

	while (std::getline(ifile, line)) {
		std::cout << line << '\n';
	} // Чтение и вывод строки из файла


	printf("\nНажмите любую клавишу для возврата в меню...\n");
	_getch();
	system("cls");
	return 0;
}
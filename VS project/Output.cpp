#define _CRT_SECURE_NO_WARNINGS
#include "Main.h"
#include "General_func.h"
#include "Output.h"
#include "Work_with_files.h"

int output_menu(const std::vector<data>& vec) {
	const std::string path = R"(C:\Users\I\Desktop\)";
	std::string save_path = "0";
	menuopt menu_param[] = {
		{"<Формат .TXT>", "<Формат .CSV>", 0}, //0
		{"<Вывести все поля>", "<Вывести только полностью заполненные поля>", 0}, //1
		{"<Сортировать по группе>", "<Сортировать по фамилии>", 0}, //2
		{"<Знак раздела ','>", "<Знак раздела '|'>"}, // 3
		{"<Вывести в файл>", "<Вывести в консоль>", 0}, // 4
		{"Вывести результат", "", 0},
		{"Назад в главное меню", "", 0}
	};
	const int menuSize = sizeof(menu_param) / sizeof(menu_param[0]);
	
	int selected = -1;
	bool isdone = 0;
	while (!isdone) {
		selected = print_menuopt(menu_param, menuSize);
		if (selected == 5) {
			output_to_file(vec, menu_param);
		}
		else if (selected == 6) {
			isdone = 1;
		}
		else {
			menu_param[selected].param = !menu_param[selected].param; // переключаем опцию
		}
	}
	return 0;
}

int print_menuopt(menuopt menu[], int size){ //функция вывода на экран меню
	static int selected = 0;
	bool isdone = false;
	int key = 0;


	while (!isdone) {
		system("cls");
		for (int i = 0; i < size; i++) {
			std::string str_buf;
			if (menu[i].param) {
				str_buf = menu[i].option2;
			}
			else {
				str_buf = menu[i].option1;
			}

			if (i == selected) {
				
				std::cout << "--> " << str_buf << '\n';
			}
			else {
				std::cout << "    " << str_buf << '\n';
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
			else if (key == 75) { // Стрелка влево
				isdone = true;
			}
			else if (key == 77) { // Стрелка вправо
				isdone = true;
			}
		}
		else if (key == 13) { // Enter
			isdone = true;
		}

	}
	if (selected == size - 1) {
		selected = 0;
		return size - 1;
	}
	return selected;
} //Возвращает индекс выбранного пункта меню

int output_to_file(const std::vector<data>& vec, menuopt menu[]) {
	std::vector<data> final_data = vec;
	if (menu[1].param == 1) { // Выводить только полностью заполненные поля
		final_data = filter_data(final_data);
	}
	final_data = sort_data(final_data, menu[2].param); // Сортировать по группе или по фамилии
	std::string separator; 
	if (menu[3].param == 0) { // Выбор знака раздела
		separator = " , ";
	}
	else {
		separator = " | ";
	}
	if (menu[4].param == 1) { // Выводить в консоль
		print_arr(final_data, separator);
		return 0;
	}

	fs::path save_path = SaveFileDialog(menu[0].param);
	if (save_path == "0") {
		return 0;
	}
	switch (menu[0].param) { // Сохранение в выбранном формате
	case 0:
		return SaveToTXT(final_data, save_path, separator);
		break;
	case 1:
		return SaveToCSV(final_data, save_path);
		break;
	default:
		break;
	}

	return 0;
}

int print_arr(const std::vector<data>& vec, std::string separator) {
	system("cls");
	std::cout << "Всего строк: " << vec.size() << '\n';
	std::cout << std::left << std::setw(20) << "Имя" << separator
		<< std::left << std::setw(12) << "Группа" << separator
		<< std::left << std::setw(2) << "Номер" << separator
		<< std::left << std::setw(20) << "Пароль"  << "\n"; // Заголовок
	for (const auto& d : vec) {
		std::cout << std::left << std::setw(20) << d.name << separator
			<< std::left << std::setw(12) << d.group << separator
			<< std::left << std::setw(2) << d.number << separator
			<< std::left << std::setw(20) << d.pass << "\n";
	}
	std::cout << "Нажмите любую кнопку чтобы продолжить\n";
	_getch();
	return 0;
}

int SaveToTXT(const std::vector<data>& vec, fs::path save_path, std::string separator) {
	std::ofstream outfile(save_path);
	if (!outfile.is_open()) {
		system("cls");
		std::cerr << "Не удалось открыть файл для записи\n";
		_getch();
		return -1;
	}
	outfile << std::left << std::setw(20) << "Имя" << separator
		<< std::left << std::setw(12) << "Группа" << separator
		<< std::left << std::setw(2) << "Номер" << separator
		<< std::left << std::setw(20) << "Пароль" << "\n"; // Заголовок
	for (const auto& d : vec) {
		outfile << std::left << std::setw(20) << d.name << separator
			<< std::left << std::setw(12) << d.group << separator
			<< std::left << std::setw(2) << d.number << separator
			<< std::left << std::setw(20) << d.pass << "\n";
	}
	outfile.close();
	system("cls");
	std::cout << "Данные успешно сохранены в файл: " << save_path << "\n";
	std::cout << "Нажмите любую кнопку чтобы продолжить\n";
	_getch();
	return 0;
}

int SaveToCSV(const std::vector<data>& vec, fs::path save_path) {
	std::ofstream outfile(save_path);
	if (!outfile.is_open()) {
		system("cls");
		std::cerr << "Не удалось открыть файл для записи\n";
		_getch();
		return -1;
	}
	outfile << "Имя;Группа;Номер;Пароль\n"; // Заголовок CSV
	for (const auto& d : vec) {
		outfile << d.name << ";" << d.group << ";" << d.number << ";" << d.pass << "\n";
	}
	outfile.close();
	system("cls");
	std::cout << "Данные успешно сохранены в файл: " << save_path << "\n";
	std::cout << "Нажмите любую кнопку чтобы продолжить\n";
	_getch();
	return 0;
}

std::vector<data> filter_data(const std::vector<data>& vec) {
	std::vector<data> filtered;
	for (const auto& d : vec) {
		if (!d.name.empty() && !d.group.empty() && !d.number.empty() && !d.pass.empty()) {
			filtered.push_back(d);
		}
	}
	return filtered;
}

std::vector<data> sort_data(const std::vector<data>& vec, bool sort_type) {
	std::vector<data> sorted = vec;
	if (sort_type == 0) { // Сортировка по группе
		std::sort(sorted.begin(), sorted.end(), [](const data& a, const data& b) {
			return a.group < b.group;
			});
	}
	else { // Сортировка по фамилии
		std::sort(sorted.begin(), sorted.end(), [](const data& a, const data& b) {
			return a.name < b.name;
			});
	}
	return sorted;
}
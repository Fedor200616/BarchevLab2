#define _CRT_SECURE_NO_WARNINGS
#include "Main.h"
#include "General_func.h"
#include "Output.h"
#include "Work_with_files.h"
#include "Search.h"

const int identic_num = 7; // макс количество совпадений, для вывода в промежуточном окне

int main_search(const std::vector<data>& vec) {
	std::string search_str = "";
	std::vector<data> search_result = vec;
	int done = 0;

	while (!done) {
		int have_res = print_menuopt(search_result, search_str);
		done = 0;
		int key = _getch();
		if (key == 13 && have_res) { // Enter
			if (!search_result.empty()) {
				print_arr(search_result);
			}
			else {
				system("cls");
				std::cout << "Произошла ошибка, данные не найдены\n";
				std::cout << "Нажмите любую кнопку чтобы продолжить\n";
				_getch();
				done = -1;
			}
		}
		else if (key == 27) { // Esc
			done = 1;
		}
		else search_str = key_analyse(search_str, key);
		if (key == 8) { // Backspace
			search_result = vec; // Сбрасываем результаты поиска перед фильтрацией
		}
		search_result = search(vec, search_str);
	}

	return done;
}

int print_menuopt(const std::vector<data>& search_result, std::string search_str) {
	static int selected = 0;

	system("cls");
	std::cout << " Введите строку для поиска (по фамилии, группе или номеру): \n";
	separator();

	std::cout << search_str << "\n";
	separator();

	//if (search_str.size()) { //Ввод не нулевой
		if (!search_result.empty()) { //Есть совпадения
			std::cout << "Найдено совпадений: " << search_result.size() << "\n";
			separator();
			if (search_result.size() <= identic_num) { //Выводим совпадения
				print_arr(search_result, " | ", 0, 0);
			}

		}
		else if (search_result.empty()) { // Совпадений нет
			std::cout << "Совпадений не найдено\n";
			separator();
		}
	//}


	int have_res = 0;
	if (search_result.size() > 0) {
		std::cout << "Нажмите Enter для просмотра результатов\n";
		have_res = 1;
	}
	std::cout << "Нажмите Esc для выхода в главное меню\n";

	return have_res;
}

int ftype = 0; //тип поля для поиска
std::string key_analyse(std::string search_str, int key) {
	if (key == 8) { // Backspace
		if (!search_str.empty()) {
			search_str.pop_back();
		}
	}
	else if (isgraph(key) || (key >= 192 && key <= 255) || key == 184 || key == 168) { // Печатаемые символы
		search_str += key;
	}
	return std::string(search_str.begin(), search_str.end());
}

std::vector<data> search(const std::vector<data>& vec, std::string str) {
	std::vector<data> search_result;
	int search_num = 0;
	
	for (const auto& d : vec) {
		int istrue[4] = { 0 };
		if (search_name(d, str) || search_pass(d, str) || search_group(d, str) || search_number(d, str)) {
			search_result.push_back(d);
			search_num++;
		}
	}
	return search_result;
}

int print_search_res(const std::vector<data>& search_result) { //Функция вывода результатов поиска на ЭКРАН ПОИСКА
	for (int i = 0; i < search_result.size(); i++) {
		std::cout << search_result[i].name << " " << search_result[i].group << '\n';
	}
	separator();
	return 0;
}

int search_name(data d, std::string str) {
	if (str.size() > d.name.size()) {
		return 0;
	}
	for (int i = 0; i < str.size(); i++) {
		if (!(str[i] == d.name[i]))
			return 0;
	}
	return 1;
}
int search_pass(data d, std::string str) {
	if (str.size() > d.name.size()) {
		return 0;
	}
	for (int i = 0; i < str.size(); i++) {
		if (!(str[i] == d.pass[i]))
			return 0;
	}
	return 2;
}
int search_group(data d, std::string str) {
	if (str.size() > d.name.size()) {
		return 0;
	}
	for (int i = 0; i < str.size(); i++) {
		if (!(str[i] == d.group[i]))
			return 0;
	}
	return 3;
}
int search_number(data d, std::string str) {
	if (str.size() > d.name.size()) {
		return 0;
	}
	for (int i = 0; i < str.size(); i++) {
		if (!(str[i] == d.number[i]))
			return 0;
	}
	return 4;
}

int separator() {
	std::string sep = "====================================================================\n";
	std::cout << sep;
}
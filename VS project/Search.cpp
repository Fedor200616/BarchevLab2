#define _CRT_SECURE_NO_WARNINGS
#include "Main.h"
#include "General_func.h"
#include "Output.h"
#include "Work_with_files.h"
#include "Search.h"

int main_search(const std::vector<data>& vec) {
	std::string search_str = "";
	std::vector<data> search_result;
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

int print_menuopt(const std::vector<data>& search_result, std::string search_str){
	std::string separator = "====================================================================\n";
	static int selected = 0;

	system("cls");
	std::cout << " Введите строку для поиска (по фамилии, группе или номеру): \n"
		<< separator;

	std::cout << search_str << "\n";
	std::cout << separator;

	if (!search_result.empty() && search_str.size() > 0) {
		std::cout << "Найдено совпадений: " << search_result.size() << "\n";
		std::cout << separator;
		//TODO Выводим найденные совпадения
	}
	else if (search_result.empty() && search_str.size() > 0) {
		std::cout << "Совпадений не найдено\n";
		std::cout << separator;
	}
	
	int have_res = 0;
	if (search_result.size() > 0 && search_str != "") {
		std::cout << "Нажмите Enter для просмотра результатов\n";
		have_res = 1;
	}
	std::cout << "Нажмите Esc для выхода в главное меню\n";

	return have_res;
}

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
	bool havenum = false;
	for (int i = 0; i < str.size(); i++) {
		if (isdigit(str[i])) {
			havenum = true;
			break;
		}
	}
	bool havespec = false;
	for (int i = 0; i < str.size(); i++) {
		int key = str[i];
		if (!isalnum(key) && !((key >= 192 && key <= 255) || key == 184 || key == 168)) {
			havespec = true;
			break;
		}
	}
	//  TYPE   num   spec
	//  name   0     0
	//  group  -     -
	//  num    1     0
	//  pass   1     1

	for (const auto& d : vec) {
		/*if (!havenum && !havespec) {
			// Ищем по фамилии
			if (d.name.find(str) != std::string::npos) {
				search_result.push_back(d);
				search_num++;
			}
		}
		else if (havenum && !havespec) {
			//Ищем по номеру
			if (d.number.find(str) != std::string::npos) {
				search_result.push_back(d);
				search_num++;
			}
		}
		else if (havenum && havespec) {
			//Ищем по паролю
			if (d.pass.find(str) != std::string::npos) {
				search_result.push_back(d);
				search_num++;
			}
		}
		else { // Ищем по группе (Экспериментально, в случае пробелм исправить на поиск по всем полям)
		*/	if (d.group.find(str) != std::string::npos || d.name.find(str) != std::string::npos || d.number.find(str) != std::string::npos || d.pass.find(str) != std::string::npos) {
				search_result.push_back(d);
				search_num++;
			}
		//}
	}
	return search_result;
}

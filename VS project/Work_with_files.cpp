#include "main.h"
#include "General_func.h"
#include "Work_with_files.h" 
#include "Output.h"


std::vector<data> fillData(fs::path secname, fs::path password) { // Функция обьединяет файлы в массив структур data
    std::ifstream sfile(secname);
    std::ifstream pfile(password);

    std::vector<data> result;
    std::string str_buf;

    if (!sfile.is_open()) {           // проверяем
        std::cerr << "Не удалось открыть файл фамилий\n";
        return result;
    }
    if (!pfile.is_open()) {           // проверяем
        std::cerr << "Не удалось открыть файл паролей\n";
        return result;
    }

    int i = 0;
    while (std::getline(sfile, str_buf)) {
        data d_buf = { "", "", "", "" };
        //bool secondvert = false; // Маркер что | уже была, и после нее чтоит еще одна, нужен для перехода на след строку в этом случае
        bool endofstring = false;
        int wordnum = 0;

        std::istringstream iss(str_buf); // 
        std::string word_buf;
        while (iss >> word_buf && !endofstring) { //Запишем имена группы и номера в структуру
            if (word_buf == "|") {
                wordnum++;
            }
            else {
                switch (wordnum) {
                case 1:
                    d_buf.name = word_buf;
                    break;
                case 2:
                    d_buf.group = word_buf;
                    break;
                case 3:
                    d_buf.number = word_buf;
                    break;
                default:
                    break;
                }
            }
            if (wordnum >= 9) {
                endofstring = true;
            }

        }

        //std::cout << d_buf.name << " " << d_buf.group << " " << d_buf.number << "\n"; //Отладка
        result.push_back(d_buf);

    }

    while (std::getline(pfile, str_buf)) { //Повторяем с паролем
        data d_buf = { "", "", "", "" };

        bool endofstring = false;
        int wordnum = 0;

        std::istringstream iss(str_buf); // 
        std::string word_buf;
        std::string password;
        while (iss >> word_buf && !endofstring) { //Запишем имена группы и номера в структуру
            if (word_buf == "|") {
                wordnum++;
            }
            else {
                switch (wordnum) {
                case 1:
                    d_buf.pass = word_buf;
                    break;
                case 2:
                    d_buf.group = word_buf;
                    break;
                case 3:
                    d_buf.number = word_buf;
                    break;
                default:
                    break;
                }
            }
        }
        compare(result, d_buf); //сравнивает структуру с полем
    }
    AdNodata(result);

    return result;
}

fs::path OpenFileDialog(const int filetype) {  // Вызов диалоговго окна выбора файла через проводник
    wchar_t filename[MAX_PATH];
    fs::path root = fs::current_path().root_directory();

    OPENFILENAME ofn;
    ZeroMemory(&filename, sizeof(filename));
    ZeroMemory(&ofn, sizeof(ofn));

    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFilter = L"Text Files\0*.txt\0*.*\0";  //фильтруем на текстовые
    ofn.lpstrFile = filename;
    ofn.nMaxFile = MAX_PATH;
    ofn.lpstrTitle = L"Выберите файл";  //заголовок
    ofn.lpstrInitialDir = root.c_str();
    ofn.Flags = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST; //Флаги не добавлять несуществующий, не делать недавним 

    if (GetOpenFileNameW(&ofn)) {
        std::wcout << L"You chose the file \"" << filename << L"\"\n";
        int valid = is_valid_file(filename, filetype);
        if (valid == 1)
            return fs::path(filename);
        else
            std::cout << "Для продолжения нажмите любую кнопку\n";
        int ch = _getch();
        return "0";
    }
    else {
        std::wcout << L"You cancelled.\n";
        return "0";
    }
}

int compare(std::vector<data>& vec, data d) { //Функция для вставки данных паролей в массив всех данных
    int is_inserted = 0;
    if (d.group == "" || d.number == "") {
        vec.push_back(d); // Если группа или номер пустые, добавляем эту запись как есть, так как она может быть из другого файла и может быть дополняющейs
        return 0; // Если группа или номер пустые, не обрабатываем эту запись
    }
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i].group == d.group && vec[i].number == d.number) {
            vec[i].pass = d.pass;
            is_inserted = 1;
        }
    }
    if (!is_inserted) {
        vec.push_back(d);
    }
    return 0;
}

fs::path SaveFileDialog(int file_type) {  // Вызов диалоговго окна выбора файла через проводник
    wchar_t filename[MAX_PATH];
    fs::path root = fs::current_path().root_directory();

    OPENFILENAME ofn;
    ZeroMemory(&filename, sizeof(filename));
    ZeroMemory(&ofn, sizeof(ofn));

    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    switch (file_type)
    {
    case 1:
        ofn.lpstrFilter = L"CSV Files\0*.csv\0*.*\0";  //фильтруем на CSV
        ofn.lpstrDefExt = L"csv"; // расширение
        break;
    case 0:
    default:
        ofn.lpstrFilter = L"Text Files\0*.txt\0*.*\0";
        ofn.lpstrDefExt = L"txt";
        break;
    }

    ofn.lpstrFile = filename;
    ofn.nMaxFile = MAX_PATH;
    ofn.lpstrTitle = L"Сохранить файл как";  //заголовок

    ofn.lpstrInitialDir = root.c_str();
    ofn.Flags = OFN_DONTADDTORECENT | OFN_OVERWRITEPROMPT;

    if (GetOpenFileNameW(&ofn)) {
        //std::cout << "Сохраняем в: " << filename << "\n";
        return fs::path(filename);
    }
    else {
        std::cout << "You cancelled.\n";
        return "0";
    }
}

int is_valid_file(const fs::path file, const int filetype) {
    std::ifstream infile(file);
    if (!infile.is_open()) {           // проверяем открывается ли файл
        std::cerr << "Не удалось открыть файл\n";
        return -1;
    }
    std::string first_line = "";
    std::getline(infile, first_line);
    std::istringstream iss(first_line); // объект потока для чтения из строки.
    std::string word;
    int sep_count = 0;
    int name_or_pass = 0; // 1 - имя, 2 - пароль
    while (iss >> word) {
        if (word == "|") {
            sep_count++;
        }
        else if ((word[0] >= 'А' && word[0] <= 'я' || word[0] == 'ё' || word[0] == 'Ё') && name_or_pass == 0) {
            name_or_pass = 1;
        }
        else if (isgraph(word[0]) && name_or_pass == 0) {
            name_or_pass = 2;
        }
    }
    if (name_or_pass == 0) {
        std::cerr << "Файл пустой или другая ошибка\n";
        return -3;
    }
    if (sep_count != 4) {
        std::cerr << "Неверный формат файла\n";
        return -2;
    }
    if (filetype == name_or_pass)
        return 1;
    else {
        std::cerr << "Выбранный файл не соответствует ожидаемому формату\n";
        return 0;
    }
}



void AdNodata(std::vector<data>& result) {
    for (auto& line : result) {
        if (line.name == "")
            line.name = "Нет данных";
        if (line.group == "")
            line.group = "Нет данных";
        if (line.number == "")
            line.number = "Нет данных";
        if (line.pass == "")
            line.pass = "Нет данных";
    }
}
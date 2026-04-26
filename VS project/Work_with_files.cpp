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
        data d_buf = {"", "", "", "" };
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
                switch (wordnum){
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
        data d_buf = {"", "", "", "" };

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
                switch(wordnum) {
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


    
    return result;
}

fs::path OpenFileDialog() {  // Вызов диалоговго окна выбора файла через проводник
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
        return fs::path(filename);    
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
    for(int i = 0; i < vec.size(); i++) {
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
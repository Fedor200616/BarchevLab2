#include "main.h"
#include "General_func.h"
#include "Work_with_files.h" 


std::vector<data> fillData(fs::path secname, fs::path password) {
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
        int d_type = 0;
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
                switch (d_type){
                case 0:
                    d_buf.name = word_buf;
                    break;
                case 1:
                    d_buf.group = word_buf; //Тут получается что при отсуствии имении - группа будет писаться вместо него, стоит исправить
                    break;
                case 2:
                    d_buf.number = word_buf;
                    break;
                default:
                    endofstring = true;
                    break;
                }
                d_type++;
                wordnum++;
            }
            if (wordnum >= 7) {
                endofstring = true;
            }

        }
         
        //std::cout << d_buf.name << " " << d_buf.group << " " << d_buf.number << "\n"; //Отладка
        result.push_back(d_buf);

    } //Записываем в вектор данные из файла фамилий
    
    while (std::getline(pfile, str_buf)) {
        data d_buf = {"", "", "", "" };
        int d_type = 0;

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
                switch(d_type) {
                case 0:
                    d_buf.pass = word_buf;
                    break;
                case 1:
                    d_buf.group = word_buf; //Тут получается что при отсуствии имении - группа будет писаться вместо него, стоит исправить
                    break;
                case 2:
                    d_buf.number = word_buf;
                    break;
                default:
                    endofstring = true;
                    break;
                }
            }
        }
        compare(result, d_buf);

        //std::cout << d_buf.name << " " << d_buf.group << " " << d_buf.number << "\n"; //Отладка
        result.push_back(d_buf);

    }


    
    return result;
}

fs::path FileDialog() {  // Вызов диалоговго окна выбора файла через проводник
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
    ofn.lpstrInitialDir = root.c_str();  // FIXME
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
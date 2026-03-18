#include "main.h"
#include "Work_with_files.h" 


std::vector<data> fillData(fs::path secname, fs::path password) {
    std::ifstream sfile(secname);
    std::ifstream pfile(password);

    std::vector<data> result;  // создаём пустой вектор
    std::string str_buf;
    data d_buf = {"", "", "", ""};

    if (!sfile.is_open()) {           // проверяем
        std::cerr << "Не удалось открыть файл фамилий\n";
        return result;
    }
    if (!pfile.is_open()) {           // проверяем
        std::cerr << "Не удалось открыть файл паролей\n";
        return result;
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
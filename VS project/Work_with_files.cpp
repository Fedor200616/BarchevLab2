#include "Work_with_files.h"  

fs::path FileDialog() {  
    wchar_t filename[MAX_PATH];  

    OPENFILENAME ofn;   //Структура OPENFILENAMEA (commdlg.h)
    ZeroMemory(&filename, sizeof(filename));  
    ZeroMemory(&ofn, sizeof(ofn));  

    ofn.lStructSize = sizeof(ofn);  
    ofn.hwndOwner = NULL;  
    ofn.lpstrFilter = L"Text Files\0*.txt\0*.*\0";  //фильтруем на текстовые
    ofn.lpstrFile = filename;  
    ofn.nMaxFile = MAX_PATH;  
    ofn.lpstrTitle = L"Выберите файл";  //заголовок
    ofn.Flags = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST; //Флаги не добавлять несуществующий, не делать последним 

    if (GetOpenFileNameW(&ofn)) {  
        std::wcout << L"You chose the file \"" << filename << L"\"\n";  
        return fs::path(filename);    
    }  
    else {  
        std::wcout << L"You cancelled.\n"; 
        return "0";
    }  
}
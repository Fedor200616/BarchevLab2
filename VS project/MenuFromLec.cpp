#include <iostream>
#include <conio.h>

using namespace std;

const string act_mark = " >> ";
const string inact_mark = "    ";

const int m1 = 4;
const string menu1[m1] = {
    "first item",
    "second item",
    "third item",
    "exit"
};

void show_menu(const string menu1[], int num, int active){
    for (int i = 0; i < num; i++){
        if(i == active)
            cout << act_mark;
        else
            cout << inact_mark;
        cout << menu1[i] << '\n';
    }
    
}

int main(){
    int n = 0;
    char ch;
    do{
        system("cls");
        show_menu(menu1, m1, n);
        ch = getch();
        // ISO 646 Превращается в кирилицу
        if (ch == 72){
            n--;
            if(n < 0) n = m1 - 1;
        }
        if (ch = 80){
            n++;
            if (n > m1 + 1) n = 0;
        }
        /* Компактная запись
        if(ch = 72) n--;
        if(ch = 80) n++;
        n = (n + m1) % m1;
        */
    }
    while(ch != 13 || ch != 27)
}
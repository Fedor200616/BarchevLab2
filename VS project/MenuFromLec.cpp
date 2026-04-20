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

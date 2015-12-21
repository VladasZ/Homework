//
//  main.cpp
//  strings1
//
//  Created by Vladas Zakrevskis on 21.12.15.
//  Copyright © 2015 Vladas Zakrevskis. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {

    char* str = "34534 53455 45645 6 6 6 6 43 43 43 34 34 34 456 546 5654 588";
    
    int numbersCount = 1;
    
    for(int i = 0; i < strlen(str); ++i)// считаем количество чисел в строке
        if (str[i] == ' ') numbersCount++; // для выделения нужного кол-ва памяти
    
    
    //split будет нашим массивом строк из отдельных чисел
    char** split = new char*[numbersCount];//выделяем память под указатели на строки
    
    for(int i = 0; i<numbersCount; ++i){
        split[i] = new char[50]; // выделяем по 50 символов для каждой строки
    }                            // можно и по 10, но бля ты че бля еврей нахуй?
    
    int splitCount = 0; // счетчик для массива строк
    
    
    
    int prevSpace = 0;// переменная для сохранения предыдущего пробела
    
    for(int i = 0; i <= strlen(str); ++i){
        if (str[i] == ' ' || i == strlen(str)) { // чикаем нашу строку на числа когла видим пробел
            strncpy(split[splitCount], str + prevSpace, i - prevSpace);
            // strncpy гугли что за функция
            splitCount++;// переходим на следущую строку
            prevSpace = i + 1; // сохраняем позицию пробела
        }
    }
    
    
   
    for(int i = 0; i < numbersCount; ++i){
        if(!((split[i][strlen(split[i]) - 1] - ' ') % 2)) // блять хуй знает как обьяснить тебе что тут)
        cout << split[i] << endl;                          // надо рисовать
    }                                                       // ну или повтыкай
                                                            // попробуй разбить по частям
    
    return 0;
}

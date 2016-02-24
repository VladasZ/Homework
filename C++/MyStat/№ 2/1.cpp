#include <iostream>
using namespace std;

class Stack{
    char *string = new char;
    int size = 0;
public:
    
    
    void add(char n){
        size++;
        char *temp = new char [size];
        for (int i =0;i<size;i++){
            temp[i] = string[i];
        }
        temp[size] = n;
        delete [] string;
        string = temp;
    }
    
    void pop(){
        cout << string[size] << endl;
        string[size] = '\0';
        size--;
    }
    
    void display(){
        for (int i =0;i<=size;i++){
            cout << string[i];
        }
        cout << endl;
    }
    
    
};

int main(){
    setlocale (LC_ALL, "rus");
    
    Stack a;
    
    a.add('a');
    a.add('b');
    a.add('c');
    a.add('d');
    a.add('f');
    a.add('g');
    cout << "Проверка стека" << endl;
    a.display();
    cout << "Извлечение элемента" << endl;
    a.pop();
    cout << "Проверка стека после извлечения элемента" << endl;
    a.display();
    

    
}
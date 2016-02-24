#include <iostream>
using namespace std;


class Stack{
    char *strng = new char;
    int size = 0;
public:
    

    
    void add(char  n){
        size++;
        char *temp = new char [size];
        for (int i =0;i<size;i++){
            temp[i] = strng[i];
        }
        temp[size] = n;
        ///delete [] strng; � visual studio ������ ������
        strng = temp;
    }
    
    void addString (char *str){
        
        for (int i =0; i<strlen(str); i++) {
            add(*(str+i));
        }
    }
    
    
    /*Логика проверки:
        если (количество открытых и закрытых скобок одинаково) и
        если (первая скобка не закрытая) и
        если (последняя скобка не открытая)
        скобки расставлены правильно         
     */
    bool checkOneTypeOfHooks(char openHook, char closeHook){
        int open = 0;
        int close = 0;
        char firstHook = 0;
        char lastHook = 0;
        
        for (int i =0; i<=size; i++) {
            
            
            if (strng[i] == openHook ){
                
                if (!firstHook) {
                    firstHook = openHook;
                }
                
                lastHook = openHook;
                
                open++;
            }
            
            
            
            if (strng[i] == closeHook ){
                
                if (!firstHook) {
                    firstHook = closeHook;
                }
                
                lastHook = closeHook;
                
                close++;
            }
            
            
            
            
            
        }
        
        
        if (open == close &&
            firstHook != closeHook   &&
            lastHook != openHook)
        {
            return true;
        }
        cout << "Wrong " << openHook << closeHook<< endl;
        return false;
    }

    
    bool checkHooks(){
        
        if (checkOneTypeOfHooks('(', ')')   &&
            checkOneTypeOfHooks('[', ']')   &&
            checkOneTypeOfHooks('{', '}')    )
        
        {
            return true;
        }
        
        return false;
    }
    
    void pop(){
        cout << strng[size] << endl;
        strng[size] = '\0';
        size--;
    }
    
    void display(){
        for (int i =0;i<=size;i++){
            cout << strng[i];
        }
        cout << endl;
    }
    
    
};



int main(){
    setlocale (LC_ALL, "rus");
    
    Stack a;
    
    
    a.addString("(1234[{}]()5)");
    
    a.display();
    
    cout << a.checkHooks() << endl;
  
    
  
    
}
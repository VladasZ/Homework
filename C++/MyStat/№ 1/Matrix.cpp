#include <iostream>
using namespace std;


#define RAND rand()%5


struct Matrix{
    int n[5][5];
    char name; // у каждой матрицы будет имя
    // для удобства при проверке функций
    
    
    
    Matrix(char name):name(name){
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                n[i][j] = RAND;
            }
        }
        
    }
    
    
    
    void display(){
        cout << name << endl;
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                cout << n[i][j] << ' ';
                if (n[i][j] <10) cout << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
    
    
    Matrix operator+(Matrix a){
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                a.n[i][j] += this->n[i][j];
            }
        }
        
        
        return a;
    }
    Matrix operator+=(Matrix a){
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                this->n[i][j] += a.n[i][j];
            }
        }
        
        
        return *this;
    }
    Matrix operator-(Matrix a){
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                this->n[i][j] -= a.n[i][j];
            }
        }
        
        
        return *this;
    }
    Matrix operator-=(Matrix a){
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                this->n[i][j] -= a.n[i][j];
            }
        }
        
        
        return *this;
    }
    Matrix operator*(Matrix a){
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                this->n[i][j] *= a.n[i][j];
            }
        }
        
        
        return *this;
    }
    Matrix operator*(int a){
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                this->n[i][j] *= a;
            }
        }
        
        
        return *this;
    }
    Matrix operator*=(Matrix a){
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                this->n[i][j] *= a.n[i][j];
            }
        }
        
        
        return *this;
    }
    Matrix operator*=(int a){
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                this->n[i][j] *= a;
            }
        }
        
        
        return *this;
    }
    Matrix operator/(Matrix a){
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                this->n[i][j] /= a.n[i][j];
            }
        }
        
        
        return *this;
    }
    Matrix operator/(int a){
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                this->n[i][j] /= a;
            }
        }
        
        
        return *this;
    }
    Matrix operator/=(Matrix a){
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                this->n[i][j] /= a.n[i][j];
            }
        }
        
        
        return *this;
    }
    Matrix operator/=(int a){
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                this->n[i][j] /= a
                ;
            }
        }
        
        
        return *this;
    }
    void operator^(int a){
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                for (int t=1; t<a; t++) {
                    this->n[i][j] *= this->n[i][j];
                }
                
            }
        }
   
    }
    bool operator ==(Matrix a){
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                if (this->n[i][j] != a.n[i][j]) return false;
            }
        }
        
        
        return true;
    }
    bool operator !=(Matrix a){
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                if (this->n[i][j] != a.n[i][j]) return true;
            }
        }
        
        
        return false;
    }
    
    void transpose(){
        int temp;
        for (int i =0;i<3;i++){
            for (int j=4;j>0;j--){
                 temp = n[i][j];
                n[i][j] = n[j][i];
                n[j][i] = temp;
                
            }
        }
        
        
        
    }
    
};




int main(){
    Matrix a = 'a', b = 'b';
    cout << "Вывод матриц на экран" << endl;
    a.display();
    b.display();
    cout << "Сумма матриц a и b" << endl;
    (a+b).display();
    b += a;
    cout << "Операция комбинированного присваивания" << endl;
    b.display();
    // Я не использовал методы -, *, / т.к. код там идентичен коду
    // в методах с плюсом, только изменен оператор
    
    Matrix c = 'c';
    Matrix d = c;
    
    cout << "Сравнение на равенство 2х одинаковых матриц" <<endl;
    cout << (c==d) << endl;
    c.n[2][2] = 434534; // изменяем один элемент в матрице с
    cout << "Сравнение на неравенство после изменения элемента в матрице с" <<endl;
    cout << (c!=d) << endl ;
    
    cout << endl;
    
    cout << "Матрица а в степени 2" << endl;
    a^2;
    a.display();
    cout << "Транспонированная матрица а"<< endl;
    a.transpose();
    a.display();
    
    // Остальные методы реализовать не смог т.к. я не проходил матрицы
    // и вообще не представляю что нужно сделать
}
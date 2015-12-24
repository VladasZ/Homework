
#include <iostream>
#include <string>

#define MIN_ZARPLATA 4000
#define STUDENTS_COUNT 50

using namespace std;


struct student{
    string name;
    int group, sredBal, sredDohod;
};

student students[STUDENTS_COUNT];


string names[5] = {"Kolja", "Vasja", "Petja", "Sascha", "Pasha"};
string lNames[5] = {"Petrov", "Ivanov", "Udmurtov", "Kopilow", "Bureika"};

string getRandomName(){
    string newName;
    
    newName.append(names[rand()%5]);
    newName.append(" ");
    newName.append(lNames[rand()%5]);
    
    return newName;
}

void generateRandomData(){
    for(int i = 0; i< 50; ++i){
        students[i].name = getRandomName();
        students[i].sredBal = rand()%11;
        students[i].group = rand()%5;
        students[i].sredDohod = rand()%30000;
    }
}

void showStudent(student st){
    cout << st.name  << "\nNomer gruppi - " << st.group
    <<  "\nsrednii ball - "<< st.sredBal
    << "\nsrednii dohod " << st.sredDohod << endl << endl;
}

void showAllStudents(){
    for(int i = 0; i < 50; ++i){
        showStudent(students[i]);
    }
}

void sortStudent(){
    
    int minDohodCount = 0;/* считаем количество нищих студентов 
                           для того чтобы потом исключить их 
                           из сортировки по среднему баллу*/
    
    for(int i = 0; i < STUDENTS_COUNT; ++i){//считаем нищих студентов и одновременно
        if (students[i].sredDohod < MIN_ZARPLATA*2) {//переносим их в начало списка
            swap(students[i], students[minDohodCount]);
            minDohodCount++;
        }
    }
    
    for (int i = minDohodCount; i < STUDENTS_COUNT - 1; ++i) {// потом просто сортируем богачей по среднему балу
        for (int j = minDohodCount; j < STUDENTS_COUNT - 1; ++j) {// изи птс
            if (students[j].sredBal < students[j+1].sredBal) {
                swap(students[j], students[j+1]);
            }
        }
    }
    
    
    
    
}


int main(){
    
    generateRandomData();
    
    sortStudent();
    
    showAllStudents();
    
    
    
    
    return 0;
}
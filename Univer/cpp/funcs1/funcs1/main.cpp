//
//  main.cpp
//  funcs1
//
//  Created by Vladas Zakrevskis on 25.12.15.
//  Copyright © 2015 Vladas Zakrevskis. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

typedef double fn(double,double,int&);

double row(double x, double eps, int& k){
    
    double result = 1;
    double increment = fabs((log(9)/1)*(x));
    
    while (increment > eps) {
        
        if (x>0)   result += increment;
        else result -= increment;
      
        //cout << increment << endl;
        increment *= fabs(((x)*log(9))/k);
        k++;
    }
    
    return result;
}

double func(double x, double eps, int& k){
    k = 1;
    return pow(9, x);
}

void tabl(fn fun){
    
    int k = 2;
    
    for(double i = 0; i <= 3; i+= 0.1){
        cout << setw(4)<< i << setw(15) << fun(i,pow(10, -4), k) << ' ' << k << endl;
        k = 2;
    }
    
}

int main() {

    tabl(func);
    cout << "row" << endl;
    tabl(row);
    
    
    return 0;
}

#include <iostream>
#include <numeric>
#include <cmath>
#include <math.h>
using namespace std;
int main(){
    double x=0.2;
    double h=pow(10,-20);
    double sin(double x);
    double cos(double x);
    double blad;
    double pochD;
    while(h<pow(10,3)){
        h*=1.01;
        pochD=(sin(x+h)-sin(x))/h;
        blad=abs(pochD-cos(x));
        cout<<h<<" "<<blad<<endl;
    }
    
}
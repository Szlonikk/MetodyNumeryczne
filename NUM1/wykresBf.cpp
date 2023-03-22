#include <iostream>
#include <numeric>
#include <cmath>
#include <math.h>
using namespace std;
int main(){
    float x=0.2;
    float h=pow(10,-20);
    float sinf(float x);
    float cosf(float x);
    float blad;
    float pochD;
    while(h<pow(10,3)){
        h*=1.01;
        pochD=(sinf(x+h)-sinf(x-h))/(2*h);
        blad=abs(pochD-cosf(x));
        cout<<h<<" "<<blad<<endl;
    }
    
}
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <fstream>
#define N 100

using namespace std;

int main(){
    int iteracje=200;
    fstream plik;
    double precyzja=pow(10,-15);
    double wyrazyWolne[N];
    vector<double > norma;
    double start[N];
    srand(time(NULL));
    vector<double > blad;
    //uzupelnianie danych z zadania
    for(int i=0;i<N;i++){
    
       wyrazyWolne[i]=i+1;
       start[i]=rand()%iteracje;
    }
    plik.open("jacobi.txt",ios::out);
    double start_cp[N];
    double norm1=0;
    for(int k=0;k<iteracje;k++){
        copy(start,start+N,start_cp);
        for(int i=0;i<N;i++){
            if(i==0){
                start[i]=(wyrazyWolne[i]-start[i+1]-0.2*start[i+2])/3;
        
            }else{
            if(i==1){
                start[i]=(wyrazyWolne[i]-start_cp[i-1]-start[i+1]-0.2*start[i+2])/3;
            }else{
            if(i==N-1){
                start[i]=(wyrazyWolne[i]-start_cp[i-1]-0.2*start_cp[i-2])/3;
            }else{
            if(i==N-2){
                start[i]=(wyrazyWolne[i]-start_cp[i-1]-0.2*start_cp[i-2]-start[i+1])/3;
            }else{
                start[i]=(wyrazyWolne[i]-start_cp[i-1]-0.2*start_cp[i-2]-start[i+1]-0.2*start[i+2])/3;
            }
            }
            }
            }
        }
        double x=0;
        for(int j=0;j<N;j++){
            x+=pow(start[j]-start_cp[j],2);
        }
        double norm2=sqrt(x);
        double prec=abs(norm1-norm2);

        norma.push_back(norm2);
        
        if(prec<precyzja){
            norma.push_back(prec);
            break;
        }
        blad.push_back(start[N-1]);
        norm1=norm2;
        
        
    }
    cout<<"Jacobi: { ";
    for(int i=0;i<N;i++){
        cout<<start[i]<<", ";
    }
    cout<<"}";
    double ostatni=start[N-1];
    for(unsigned long int i=0;i<blad.size();i++){
        blad.at(i)=abs(blad.at(i)-ostatni);
        plik<<i<<" "<<blad.at(i)<<endl;
    }

    
    plik.close();

}
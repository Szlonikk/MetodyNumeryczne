#include <iostream>
#include <algorithm>
#include <chrono>
#include <fstream>
#define N 50

using namespace std;

int main(){

    double y[N];
    double b[N];
    double u[N];
    double vt[N];
    double A[2][N]; ///tablica B=A+u*v^t
    double z[N],x[N]; /// A^-1 b      A^-1 u
    fill_n(b,N,5);
    fill_n(u,N,1);
    fill_n(vt,N,1);
    for(int i=0;i<N;i++){  /// macierz A jest już w rozkladzie LU
        A[0][i]=9;
        A[1][i]=7;
    }

    ///------ Obliczamy Az=b oraz Ax=u---------
    z[N-1]= b[N-1]/A[0][N-1];
    x[N-1]= u[N-1]/A[0][N-1];
    for(int i=N-2;i>0;i--){
        z[i]= (b[i] - A[1][i]*z[i+1] )/A[0][i];
        x[i]= (u[i] - A[1][i]*x[i+1] )/A[0][i];
    }
    ///------ Podstawiamy pod wzor Shermana-Morrisona ---------
    double vtz=0;
    double vtx=0;
    for(int i=0;i<N;i++){
        vtz=vtz+vt[i]*z[i];
        vtx=vtx+vt[i]*x[i];
    }
    for(int i=0;i<N;i++){
        y[i]=z[i]-x[i]*vtz/(1+vtx);
    }
    cout<<"Y={";
    for(int i=0;i<N;i++){
        cout<<y[i]<<", ";
    }
    cout<<"}";
    
}
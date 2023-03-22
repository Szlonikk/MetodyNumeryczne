#include <iostream>
#include <cmath>
#define N 100
using namespace std;

int main(){                  
    
    double A[4][N];
    double x[N];
    double p[N]; ///wektor przejsciowy Ux=y
    double y[N];
    double wyznacznik=1;
    ///------ Pobieranie zawartosci macierzy -------------
    for(int i=0;i<N;i++){
        A[0][i]=0.2;        /// pod diagonala L(i+1)i
        A[1][i]=1.2;        /// diagonala - Uii
        A[2][i]=0.1/(i+1);      /// 1 nad diagonala - Ui(i+1)
        A[3][i]=0.4/((i+1)*(i+1));  /// 2 nad diagonala - Ui(i+2)
        x[i]=i+1;
    }
    
    
    ///------ Przekształcenie do macierzy LU--------------

    A[0][0]/=A[1][0];   // pierwszy wyraz diagonali dolnej
    for(int i=1;i<N;i++){
        A[3][i]=A[3][i]; // 2 diagonala gorna pozostaje bez zmian bo w sumie mnozymy zawsze przez 0
        A[2][i]=A[2][i]-(A[0][i-1]*A[3][i-1]); /// przeksztalcenie 1 nad diagonala
        A[1][i]=A[1][i]-(A[0][i-1]*A[2][i-1]); /// przekształcanie diagonali do Uii
        A[0][i]/=A[1][i-1]; ///diagonala dolna - pozostały tylko czesc mianownika w rownaniu
    }
    for(int i=0;i<N;i++){
        wyznacznik*=A[1][i];
    }
    cout<<"Wyznacznik: "<<wyznacznik<<endl;
    
    ///------ Rozwiazywanie ukladu rownan Ay=x -----------
    p[0]=x[0];
    for(int i=1;i<N;i++){
        p[i]=x[i]-(A[0][i-1]*p[i-1]);  //stworzenie wektora przejsciowego
    }
    
    //----- Rozwiazanie Ux=p --------
    y[N-1]=p[N-1]/A[1][N-1];
    y[N-2]=(p[N-2] - (y[N-1]*A[2][N-2]))/A[1][N-2];
    for(int i=N-3;i>=0;i--){
       y[i]=(p[i]-(y[i+2]*A[3][i])-(y[i+1]*A[2][i]))/A[1][i];
    }
    cout<<"Y={"<<endl;
    for(int i=0;i<N;i++){
        cout<<y[i]<<", ";
    }
    cout<<"}";




}
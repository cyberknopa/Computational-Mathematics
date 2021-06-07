#include <bits/stdc++.h> 
#define _USE_MATH_DEFINES  
#include <cmath> 
 
using namespace std; 
 
void print_complex(complex <double> c) { 
    double a = c.real(); 
    double b = c.imag(); 
    string sign = ""; 
    if(b >= 0) 
        sign = "+"; 
    else 
        sign = "-"; 
    cout << a << sign << "j" << abs(b) << " "; 
 
} 
 
int main(){ 
    cout << "Введите n" << endl; 
    int l = 2; 
    cin >> l; 
  int N = pow(2, l); 
  cout << "Введите вектор сигнала в пространстве координат-отсчетов по времени, состоящий из " << N << " элементов" << ":" << endl; 
  complex <double> j(0, -1); 
  vector <vector<complex<double> > > matrix (N, vector<complex<double> >(N)); 
  for(int k = 0; k < N; k++) { 
      for(int n = 0; n < N; n++) { 
          matrix[k][n] = (1/sqrt(N)) * pow(M_E, (j * (2 * M_PI * k * n/N))); 
          double a = matrix[k][n].real(); 
          double b = matrix[k][n].imag(); 
          if(abs(a) < 1e-7) 
              a = 0; 
          if(abs(b) < 1e-7) 
              b = 0; 
          complex<double> tmp (a, b); 
          matrix[k][n] = tmp; 
      } 
  } 
    vector <vector<complex<double> > > matrix_s (N, vector<complex<double> >(N)); 
    for(int i = 0; i < N; i++) { 
        for(int j = 0; j < N; j++) { 
            matrix_s[i][j] = conj(matrix[i][j]); 
            double a = matrix_s[i][j].real(); 
            double b = matrix_s[i][j].imag(); 
            if(abs(a) < 1e-7) 
                a = 0; 
            if(abs(b) < 1e-7) 
                b = 0; 
            complex<double> tmp (a, b); 
            matrix_s[i][j] = tmp; 
        } 
        } 
    vector <complex<double> >  x (N, (0, 0)); 
    vector <complex<double> > X (N, (0, 0)); 
    vector <complex<double> > x_t (N, (0, 0)); 
 
    double c; 
    for(int i = 0; i < N; i++) { 
        cin >> c; 
        complex <double> tmp(c, 0); 
        x[i] = tmp; 
    } 
 
    for (int i = 0; i < N; i++) 
    { 
        for (int j = 0; j < N; j++) 
        { 
                X[i] += matrix[i][j] * x[j]; 
                double a = X[i].real(); 
                double b = X[i].imag(); 
                if(abs(a) < 1e-7) 
                    a = 0; 
                if(abs(b) < 1e-7) 
                    b = 0; 
                complex<double> tmp (a, b); 
                X[i] = tmp; 
 
        } 
 
    } 
    for (int i = 0; i < N; i++) 
    { 
        for (int j = 0; j < N; j++) 
        { 
            x_t[i] += matrix_s[i][j] * X[j]; 
            double a = x_t[i].real(); 
            double b = x_t[i].imag(); 
            if(abs(a) < 1e-7) 
                a = 0; 
            if(abs(b) < 1e-7) 
                b = 0; 
            complex<double> tmp (a, b); 
            x_t[i] = tmp; 
 
        } 
 
    } 
 
    cout << "Прямое преобразование Фурье: " << endl; 
      for(int i = 0; i < N; i++) { 
          print_complex(X[i]); 
          cout << endl; 
      } 
     cout << "Обратное преобразование Фурье: " << endl; 
    for(int i = 0; i < N; i++) { 
        print_complex(x_t[i]); 
        cout << endl; 
    } 
return 0; 
} 

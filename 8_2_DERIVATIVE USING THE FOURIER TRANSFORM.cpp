#define _USE_MATH_DEFINES 
#include <iostream> 
#include <cmath> 
#include <complex> 
#include <vector> 
  
using namespace std; 
  
int main() { 
    setlocale(LC_ALL, "Russian"); 
    cout << "Введите n" << endl; 
    int l = 2; 
    cin >> l; 
    int N = pow(2, l); 
    cout << "Введите вектор сигнала в пространстве координат-отсчетов по времени, состоящий из " << N << " элементов" << ":" << endl; 
    complex <double> j(0, -1); 
    vector <vector<complex<double> > > matrix(N, vector<complex<double> >(N)); 
    for (int k = 0; k < N; k++) { 
        for (int n = 0; n < N; n++) { 
            matrix[k][n] = (1 / sqrt(N)) * pow(M_E, (j * (2 * M_PI * k * n / N))); 
            double a = matrix[k][n].real(); 
            double b = matrix[k][n].imag(); 
            if (abs(a) < 1e-7) 
                a = 0; 
            if (abs(b) < 1e-7) 
                b = 0; 
            complex<double> tmp(a, b); 
            matrix[k][n] = tmp; 
        } 
    } 
    complex <double> om(2 * M_PI/ N, 0); 
    vector <vector<complex<double> > > matrix_s(N, vector<complex<double> >(N)); 
    for (int i = 0; i < N; i++) { 
        for (int k = 0; k < N; k++) { 
            matrix_s[i][k] = conj(matrix[i][k]); 
            //matrix_s[i][k] *= om * j * real(k);// real(i)* real(k); 
            double a = matrix_s[i][k].real(); 
            double b = matrix_s[i][k].imag(); 
            if (abs(a) < 1e-7) 
                a = 0; 
            if (abs(b) < 1e-7) 
                b = 0; 
            complex<double> tmp(a, b); 
            matrix_s[i][k] = tmp; 
        } 
    } 
    vector <complex<double> >  x(N, (0, 0)); 
    vector <complex<double> > X(N, (0, 0)); 
    vector <complex<double> > x_t(N, (0, 0)); 
  
    double c; 
    for (int i = 0; i < N; i++) { 
        cin >> c; 
        complex <double> tmp(c, 0); 
        x[i] = tmp; 
    } 
  
    for (int i = 0; i < N; i++) 
    { 
        for (int k = 0; k < N; k++) 
        { 
            X[i] += matrix[i][k] * x[k]; 
            double a = X[i].real(); 
            double b = X[i].imag(); 
            if (abs(a) < 1e-7) 
                a = 0; 
            if (abs(b) < 1e-7) 
                b = 0; 
            complex<double> tmp(a, b); 
            X[i] = tmp; 
  
        } 
  
    } 
  
    for (int i = 0; i < N; i++) 
    {    
        for (int k = 0; k < N; k++) 
        { 
            x_t[i] += matrix_s[i][k] * X[k] * j * om * real(k); 
            double a = x_t[i].real(); 
            double b = x_t[i].imag(); 
            if (abs(a) < 1e-7) 
                a = 0; 
            if (abs(b) < 1e-7) 
                b = 0; 
            complex<double> tmp(a, b); 
            x_t[i] = tmp; 
  
        } 
  
    } 
  
    cout << "Производная через преобразование Фурье: " << endl; 
    for (int i = 0; i < N; i++) { 
        cout << abs(x_t[i]); 
        cout << endl; 
    } 
    return 0; 
} 

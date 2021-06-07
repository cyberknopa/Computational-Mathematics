#define _USE_MATH_DEFINES 
  
#include <iostream> 
#include <cmath> 
#include <complex> 
  
using namespace std; 
double a, b, x, y, eps1 ,eps2; 
complex <float> z0, z1, amendment, epsilon, k1, k2; 
complex <float> kfree, kexp; 
int number; 
  
  
  
  
complex <float> fz(complex <float> z, int number) { 
    switch (number) { 
        case 1: 
            k1 = 4.0; 
            k2 = 2.0; 
            kfree = (1.3,0); 
            return (k1 * pow(z, 4) + k2 * pow(z, 2) + kfree); 
        case 2: 
            kfree = 2.71; 
            return (pow(z, 2) + kfree); 
        case 3: 
            k1 = 2.0; 
            kfree = sqrt(2); 
            kexp = M_E; 
            return (k1 * pow(kexp, z) + kfree); 
    } 
} 
  
complex <float> dfz(complex <float> z, int number) { 
    switch (number) { 
        case 1: 
            k1 = 16.0; 
            k2 = 4.0; 
            return (k1 * pow(z, 3) + k2 * z); 
        case 2: 
            k1 = 2.0; 
            return (k1 * z); 
        case 3: 
            k1 = 2.0; 
            kexp = M_E; 
            return (k1 * pow(kexp, z)); 
    } 
} 
  
  
int main() { 
     
    float a, b; 
    cout << "Выберите уравнение." << endl << "1 - '4*z^4 + 2*z^2 + 1.3 = 0';\n" << "2 - 'z^2 + 2.71';\n" << "3 - '2*e^z + sqrt(2)'\n"; 
    cin >> number; 
    cout << "Введите грубое приближение z0 (Re и Im), EPS (Re и Im)\n"; 
    cin >> a >> b >> eps1 >> eps2; 
    cout << "Введите левую и правую границы\n"; 
    cin >> x >> y; 
    complex <float> z0(a, b); 
    complex <float> zero = 0.0; 
    epsilon = (eps1, eps2); 
    do 
    { 
        amendment = fz(z0,number) / dfz(z0,number); 
        z1 = z0 - amendment; 
        if (fz(z1,number) == zero) 
            break; 
        z0 = z1; 
    } while (abs(fz(z1,number)) > abs(epsilon)); 
    cout << "Корень уравнения = " << z1 << endl; 
  
} 

//3.3
#include <iostream> 
#include <cmath> 
#include <windows.h> 
  
using namespace std; 
double x, l, r, d, epsilon; 
int number; 
  
double func(double x) { 
    if (number == 1) 
    { 
        return (pow(5, x) * sqrt(pow(8, (x - 1))) - 189); 
    } 
    if (number == 2) 
    { 
        return (pow(x, 3) - pow(x, 2) + 2 * x - 5); 
    } 
    if (number == 3) 
    { 
        return (2 * log10(pow(x, 2)) - 5 * pow(log10(x), 2) - 4); 
    } 
    if (number == 4) 
    { 
        return (2 * sin(2 * x) - cos(3 * x) - 0.5); 
    } 
    if (number == 5) 
    { 
        return (2 * pow(x, 3) - 7 * pow(x, 2) - 7 * x - 2.5); 
    } 
    else 
    { 
        cout << "Некорректный выбор" << endl; 
        exit(0); 
    } 
} 
  
double dfunc_2(double x) { 
    if (number == 1) 
    { 
        return (sqrt(2) * pow(5, x) * (pow(log(8), 2) + 4 * pow(log(5), 2) + 4 * log(5) * log(8)) * sqrt(pow(8, x)) / 16); 
    } 
    if (number == 2) 
    { 
        return (6 * x - 2); 
    } 
    if (number == 3) 
    { 
        return (2 * (5 * log10(x) - 5 / (log(10)) - 2) / (pow(x, 2) * log(10))); 
    } 
    if (number == 4) 
    { 
        return (-8 * sin(2 * x) + 9 * cos(3 * x)); 
    } 
    if (number == 5) 
    { 
        return (2 * (6 * x - 7)); 
    } 
  
} 
  
void solve() { 
    if (dfunc_2(r) * func(r) < 0) x = l; 
    if (dfunc_2(l) * func(l) < 0) x = r; 
    do { 
        d = x; 
        x = l - func(l) * (r - l) / (func(r) - func(l)); 
        d = abs(d - x); 
        if (func(x) * func(r) < 0) l = x; 
        if (func(x) * func(l) < 0) r = x; 
        cout << l << ", " << r << " " << d << endl; 
    } while (d > epsilon); 
} 
  
  
int main() { 
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251); 
    cout << "Выберите уравнение." << endl << "1 - '5^x*sqrt(8^(x-1)) - 189';" << endl << "2 - 'x^3 - x^2 + 2*x - 5';" << endl << "3 - '2*lg(x^2) - 5*(lg(x)^2) - 4';" << endl << "4 - '2*sin(2*x) - cos(3*x) - 0.5;'" << endl << "5 - '2*x^3 - 7*x^2 - 7*x - 2.5'" << endl << endl; 
    cin >> number; 
    cout << "Введите левую и правую границы" << endl; 
    cin >> l >> r; 
    cout << "Введите погрешность" << endl; 
    cin >> epsilon; 
    if (abs(r - l) <= epsilon) { 
        cout << "Некорректный выбор границ интервала" << endl; 
        exit(0); 
    } 
    if (func(l) * func(r) > 0) { 
        cout << "Некорректный выбор границ интервала" << endl; 
        return 2; 
    } 
    solve(); 
    cout << "x = " << x << ", e = " << d << endl; 
} 

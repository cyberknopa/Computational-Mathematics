#include <iostream> 
#include <cmath> 
 
using namespace std; 
double l, r, epsilon, x0, x1, amendment; 
int number; 
  
double f7(double x) { 
    if (number == 1) 
    { 
        return (2 * log10(x) - cos(x)); 
    } 
    if (number == 2) 
    { 
        return (2*pow(x,3) - 5 * pow(x,2) -1); 
    } 
    if (number == 3) 
    { 
        return (2* pow(sin(2*x),3) - cos(x)); 
    } 
    if (number == 4) 
    { 
        return (pow(x, 5) - 3 * pow(x, 4) + 8 * pow(x, 2) + 2 * x - 7); 
    } 
    if (number == 5) 
    { 
        return (0.5 * pow(x,2) + 5 * cos(2*x) - 2); 
    } 
    else 
    { 
        cout << "Некорректный выбор" << endl; 
        exit(0); 
    } 
} 
double df7(double x) { 
    if (number == 1) 
    { 
        return (2 / (x * log(10)) + sin(x)); 
    } 
    if (number == 2) 
    { 
        return (6 * pow(x, 2) - 10 * x); 
    } 
    if (number == 3) 
    { 
        return (12 * pow(sin(2 * x), 2) * cos(2*x) + sin(x)); 
    } 
    if (number == 4) 
    { 
        return (5 * pow(x, 4) - 12 * pow(x, 3) + 16 * x + 2); 
    } 
    if (number == 5) 
    { 
        return (x - 10 * sin(2 * x)); 
    } 
    else 
    { 
        cout << "Некорректный выбор" << endl; 
        exit(0); 
    } 
} 
  
  
int main() { 
    //SetConsoleCP(1251); 
    //SetConsoleOutputCP(1251); 
    cout << "Выберите уравнение." << endl << "1 - '2*lg(x) - cos(x)';" << endl << "2 - '2*x^3 - 5*x^2 -1';" << endl << "3 - '2*(sin(2*x))^3 - cos(x)';" << endl << "4 - 'x^5 - 3*x^4 + 8*x^2+2*x-7';" << endl << "5 - '0.5*x^2 + 5*cos(2*x)-2'" << endl << endl; 
    cin >> number; 
    cout << "Введите грубое приближение x0, EPS" << endl; 
    cin >> x0 >> epsilon; 
    cout << "Введите левую и правую границы" << endl; 
    cin >> l >> r; 
  
    if (epsilon < 0) 
        cout << "Шаг не может быть отрицательным числом" << endl; 
    if (x0 > r || x0 < l) 
        cout << "Грубое приближения корня должно входить в интервал" << endl; 
  
    do 
    { 
        amendment = f7(x0) / df7(x0); 
        x1 = x0 - amendment; 
        if (f7(x1) == 0) 
            break; 
        x0 = x1; 
    } while (abs(f7(x1)) > epsilon); 
    cout << "Корень уравнения = " << x1 << endl; 
    exit(0); 
} 

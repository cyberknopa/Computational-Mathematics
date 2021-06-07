#include <iostream> 
#include <cmath> 
using namespace std; 
 
double f(double x) { 
    return 2 * pow(x, 4) + pow(x, 3) + 2 * pow(x, 2) + 3 * x + 24; 
} 
int main() { 
    double a, b; 
    int n; 
    cout << "Введите границы интегрирования: " << endl; 
    cin >> a >> b; 
    cout << "Введите N: " << endl; 
    cin >> n; 
 
    double x = a; 
    double h = (b - a) / n; 
    double left_sum = 0; 
    double right_sum = 0; 
 
    for (int i = 0; i < n; ++i) { 
        left_sum += f(x) * h; 
        x += h; 
        right_sum += f(x) * h; 
    } 
    cout << "Результат метода левых прямоугольников: " << left_sum << endl; 
    cout << "Результат метода правых прямоугольников: " << right_sum << endl; 
} 

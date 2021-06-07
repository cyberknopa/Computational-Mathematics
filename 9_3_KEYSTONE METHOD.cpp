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
    double h = (b - a) / n; 
    double sum = 0; 
    for (int i = 0; i < n; i++) { 
        const double x1 = a + i * h; 
        const double x2 = a + (i + 1) * h; 
        sum += 0.5 * (x2 - x1) * (f(x1) + f(x2)); 
    } 
    cout << sum << endl; 
} 
 

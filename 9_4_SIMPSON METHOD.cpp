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
    double h, sum2 = 0, sum4 = 0, sum = 0; 
    h = (b - a) / (2 * n); 
    for (int i = 1; i <= 2 * n - 1; i += 2) { 
        sum4 += f(a + h * i); 
        sum2 += f(a + h * (i + 1)); 
    } 
    sum = f(a) + 4 * sum4 + 2 * sum2 - f(b); 
    cout << (h / 3) * sum << endl; 
} 

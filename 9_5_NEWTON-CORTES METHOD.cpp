#include <iostream> 
#include <cmath> 
 
using namespace std; 
 
double f(double x) { 
    return 2 * pow(x, 4) + pow(x, 3) + 2 * pow(x, 2) + 3 * x + 24; 
} 
double NewtonCotes(double a, double b, int degree, int n) { 
    int H[10][10] = { 
            1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
            1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 
            1, 4, 1, 0, 0, 0, 0, 0, 0, 0, 
            1, 3, 3, 1, 0, 0, 0, 0, 0, 0, 
            7, 32, 12, 32, 7, 0, 0, 0, 0, 0, 
            19, 75, 50, 50, 75, 19, 0, 0, 0, 0, 
            41, 216, 27, 272, 27, 216, 41, 0, 0, 0, 
            751, 3577, 1323, 2989, 2989, 1323, 3577, 751, 0, 0, 
            989, 5888, -928, 10496, -4540, 10496, -928, 5888, 989, 0, 
            2857, 15741, 1080, 19344, 5778, 5778, 19344, 1080, 15741, 2857 
    }; 
    double k[10] = {1, 1.0 / 2, 1.0 / 3, 3.0 / 8, 2.0 / 45, 5.0 / 288, 1.0 / 140, 7.0 / 17280, 4.0 / 14175, 9.0 / 89600}; 
    double result, sum; 
    double h = (b - a) / (degree * n); 
    result = 0; 
    for (int j = 0; j < n; j++) { 
        sum = 0; 
        for (int i = 0; i <= degree; i++) 
            sum += H[degree][i] * f(a + (i + j * degree) * h); 
        result += k[degree] * sum * h; 
    } 
    return result; 
} 
int main() { 
    double a, b; 
    int n; 
    cout << "Введите границы интегрирования: " << endl; 
    cin >> a >> b; 
    cout << "Введите N: " << endl; 
    cin >> n; 
    cout << NewtonCotes(a, b, 3, n) << endl; 
} 

#include <iostream> 
#include <vector> 
 
using namespace std; 
 
int main(){ 
 
vector<double> coef; 
int n; 
cout << "Введите степень алгебраического уравнения: "; 
cin >> n; 
cout << "Введите коэффициенты при степенях х и свободный член: \n"; 
for (int i = 0; i <= n; i++){ 
cout << "при x^" << n-i << ":  "; 
double a; 
cin >> a; 
coef.push_back(a); 
} 
int k; 
cout << "Введите точность (число членов последовательности, удовлетворяющей конечно-разностному уравнению в методе Бернулли): \n"; 
cin >> k; 
vector<double> y(n-1, 0.0); 
y.push_back(1.0); 
for (int i = 0; i <= k-n; i++){ 
double S = 0; 
for (int j = 0; j < n; j++) 
S += coef[n-j]*y[i+j]; 
S /= -1*coef[0]; 
y.push_back(S); 
} 
cout << "Наибольший по абсолютной величине корень алгебраического уравнения:  " << y[y.size()-1]/y[y.size()-2] << "\n"; 
 
 
return 0; 
} 
 

//3.2
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double func(double x, int number) {
switch (number) {
case 1:
return 2 * pow(x, 3) + pow(x, 2) - 7;
case 2:
return 5 * cos(3 * x) + 0.5 * x - 2;
case 3:
return pow(x, 5) - 2 * pow(x, 4) + 6 * pow(x, 2) + 2 * x - 4;
case 4:
return pow(x, 3) - 0.2 * pow(x, 2) - 0.2 * x - 1.2;
case 5:
return log(abs(pow(x, 3)) + 1) + pow(x, 3) - 2;
}
}
void roots(double a, double b, double eps, int number) {
if (b - a > eps) {
double mid = (a + b) / 2;
if (func(mid,number) == 0) {
cout << "The root of the equation is : ";
cout << fixed << setprecision(abs(log10(eps))) << (a + b) / 2;
cout << "\n Check the root : " << func((a + b) / 2, number) << endl;
}
else if (func(a, number) * func(mid, number) < 0)
roots(a, mid, eps, number);
else
roots(mid, b, eps, number);
  }
else {
cout << "The root of the equation is : ";
cout << fixed << setprecision(abs(log10(eps))) << (a + b) / 2;
cout << "\n Check the root : " << func((a + b) / 2, number) << endl;
}
return;
}
int main() {
double eps = 0;
int number = 0;
double a = 0, b = 0;
cout << "Enter the number of task : ";
cin >> number;
cout << "\nEnter the section from a to b : ";
cin >> a >> b;
cout << "\nEnter the value of the error : ";
cin >> eps;
if (func(a, number) * func(b, number) < 0)
roots(a, b, eps, number);
else
cout << "\n No root in this section";
return 0;
}

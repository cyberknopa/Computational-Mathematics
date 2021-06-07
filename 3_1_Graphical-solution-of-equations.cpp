//3.1
#include <bits/stdc++.h>
using namespace std;
double f(double x, int k ) {
switch (k) {
case 1:
return 5*pow(x, 4) - 2*pow(x, 3) + 3*pow(x, 2) + x - 4;
case 2:
return pow(x, 5) - 3*pow(x, 4) + 7*pow(x,2) + x - 8;
}
}
int main() {
double a = -10.0, b = 10.0; // левая и правые границы
double n = 100000; // число отрезков
double h = (b - a)/n; // шаг
int k = 2; // номер функции
double x0 = a, y0 = f(x0,k), x = x0 + h;
double y;
while(x <= b) {
y = f(x,k);
if(y * y0 < 0)
cout « x0 « " "« x « endl;
x0 = x;
y0 = y;
x += h;
}
return 0;
}

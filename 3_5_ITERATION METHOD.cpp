#include <iostream> 
#include <cmath> 
#include <iomanip> 
 
#define e 2.7182818284 
 
using namespace std; 
 
double IterativeFunction(int taskNumber, double argument) { 
    double x = argument; 
    switch (taskNumber) { 
    case(1): 
        return acos(1./10); 
    case(2): 
        return pow(1000 - x, 1./3); 
    case(3): 
        return pow(pow(x,4)+pow(x,2)+x+5, 1./5); 
    case(4): 
        return pow(1+x, 1./3); 
    case(5): 
        return 2.25-log(x); 
    default: 
        return 0; 
    } 
} 
double CheckResult(int taskNumber, double argument) { 
    double x = argument; 
    switch (taskNumber) { 
    case(1): 
        return cos(x) - 0.1; 
    case(2): 
        return pow(x, 3) + x - 1000; 
    case(3): 
        return pow(x, 5) - pow(x, 4) - pow(x, 2) - x - 5; 
    case(4): 
        return pow(x, 3) - x - 1; 
    case(5): 
        return log(x) + x - 2.25; 
    default: 
        return 0; 
    } 
} 
 
void SolveEquation(int taskNumber, double accuracy) { 
    double root = 1; 
    double previousRoot = 0; 
 
    root = IterativeFunction(taskNumber, root); 
    do { 
         previousRoot = root; 
         root = IterativeFunction(taskNumber, root); 
    } while (abs(root - previousRoot) > accuracy); 
 
    cout << "Корень x равен " << fixed << setprecision((abs(log10(accuracy)))) << root; 
    cout << "\nПроверка решения. f(x) = " << fixed << setprecision((abs(log10(accuracy)))) << CheckResult(taskNumber, root); 
} 
 
int main() 
{ 
 
    double epsilon; 
    int taskNumber; 
    cout << "Введите номер задачи: "; 
    cin >> taskNumber; 
    cout << "Введите точность нахождения решения: "; 
    cin >> epsilon; 
    SolveEquation(taskNumber, epsilon); 
    return 0;
    } 

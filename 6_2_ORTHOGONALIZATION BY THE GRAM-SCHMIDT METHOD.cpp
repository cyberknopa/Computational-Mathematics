#include <iostream> 
#include <cmath> 
#include <vector> 
  
using namespace std; 
  
vector<double> operator-(const vector<double> & l, const vector<double> & r) { 
    vector<double> result; 
    for (int i = 0; i < l.size(); i++) 
        result.push_back(l[i] - r[i]); 
    return result; 
} 
  
vector<double> operator+(const vector<double> & l, const vector<double> & r) { 
    vector<double> result; 
    for (int i = 0; i < l.size(); i++) 
        result.push_back(l[i] + r[i]); 
    return result; 
} 
  
double operator*(const vector<double> & l, const vector<double> & r) { 
    double result = 0; 
    for (int i = 0; i < l.size(); i++) 
        result += l[i] * r[i]; 
    return result; 
} 
  
vector<double> operator*(double l, const vector<double> & r) { 
    vector<double> result; 
    for (double i : r) result.push_back(l * i); 
    return result; 
} 
  
vector<double> proj(const vector<double> & a, const vector<double> & b) { 
    return ((a * b) / (b * b)) * b; 
} 
  
int main() { 
    vector<vector<double>> arr; 
  
    int n; 
    cout <<" " <<endl<< "Введите n: " << endl; 
    cin >> n; 
  
    for (int i = 0; i < n; i++) { 
        vector<double> t; 
        cout << "Введите значения для вектора " << i << endl; 
for (int j = 0; j < n; j++) { 
            double x; 
            cin >> x; 
            t.push_back(x); 
        } 
        arr.push_back(t); 
    } 
  
    vector<vector<double>> result; 
    for (auto & a : arr) { 
        vector<double> t = a; 
        for (auto & b : result) 
            t = t - proj(a, b); 
        result.push_back((1.0/sqrt(t * t) * t)); 
    } 
  
    for (auto & i : result) { 
        for (auto & j : i) 
            cout << j << " "; 
        cout << endl; 
    } 
cout <<"Проверка нормировки: "<< endl; 
    for (auto a : result){ 
        cout <<  sqrt(a*a) << endl; 
    } 
 
    cout <<"Проверка ортогональности: "<< endl; 
for (int i = 0; i< result.size(); i++) { 
    for(int j=0; j<result.size(); j++){ 
        if (i!=j) cout << result[i] * result[j]<< endl; 
    } 
} 
    return 0; 
} 

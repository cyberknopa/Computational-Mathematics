#include <bits/stdc++.h> 
 
using namespace std; 
 
typedef vector<vector<double>> real_matrix; 
 
void input_matrix(real_matrix &arr, int n) { 
    cout << "Вводите матрицу" << endl; 
    arr.resize(n); 
    for (int i = 0; i < n; i++) { 
        cout << "Введите строчку " << to_string(i) << endl; 
        arr[i].resize(n); 
        for (int j = 0; j < n; j++) 
            cin >> arr[i][j]; 
    } 
} 
 
void transpose(real_matrix & from, real_matrix & to, int n) { 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            to[j][i] = from[i][j]; 
} 
 
void output_matrix(real_matrix & a) { 
    for (int i = 0; i < a.size(); i++) { 
        for (int j = 0; j < a[i].size(); j++) 
            cout << a[i][j] << '\t'; 
        cout << endl; 
    } 
    cout << endl; 
} 
 
vector<double> choletsky_method(real_matrix a, vector<double> b, int n) { 
    double pk, sum; 
    real_matrix L(n, vector<double>(n, 0.0)); 
    real_matrix T(n, vector<double>(n, 0.0)); 
    vector<double> x(n), y(n); 
 
    L[0][0] = sqrt(a[0][0]); 
    for (int i = 1; i < n; i++) 
        L[i][0] = a[i][0] / L[0][0]; 
 
    for (int i = 1; i < n; i++) { 
        sum = 0; 
        for (int k = 0; k < i; k++) 
            sum += L[i][k] * L[i][k]; 
        pk = a[i][i] - sum; 
        L[i][i] = sqrt(pk); 
 
        for (int j = i + 1; j < n; j++) { 
            sum = 0; 
            for (int k = 0; k < i; k++) 
                sum += L[j][k] * L[i][k]; 
            pk = a[j][i] - sum; 
            L[j][i] = pk / L[i][i]; 
        } 
    } 
 
    transpose(L, T, n); 
 
    cout << "Матрица L: " << endl; 
    output_matrix(L); 
    cout << "Матрица T: " << endl; 
    output_matrix(T); 
 
    // Решение L*y=b 
    y[0] = b[0] / L[0][0]; 
    for (int i = 1; i < n; i++) { 
        sum = 0; 
        for (int k = 0; k < i; k++) 
            sum += L[i][k] * y[k]; 
        pk = b[i] - sum; 
        y[i] = pk / L[i][i]; 
    } 
 
    // Решение T*x=y 
    x[n - 1] = y[n - 1] / T[n - 1][n - 1]; 
    for (int i = n - 2; i >= 0; i--) { 
        sum = 0; 
        for (int k = i + 1; k < n; k++) 
            sum += T[i][k] * x[k]; 
        pk = y[i] - sum; 
        x[i] = pk / T[i][i]; 
    } 
 
    return x; 
} 
 
int main() { 
    int n; 
    cout << "Введите n: " << endl; 
    cin >> n; 
 
    real_matrix a; 
    input_matrix(a, n); 
 
    vector<double> b; 
    b.resize(n); 
    cout << "Введите вектор свободных членов: " << endl; 
    for (int i = 0; i < n; i++) 
        cin >> b[i]; 
 
    vector<double> x = choletsky_method(a, b, n); 
    for (int i = 0; i < x.size(); i++) 
        cout << "x" << to_string(i) << " = " << x[i] << endl; 
}

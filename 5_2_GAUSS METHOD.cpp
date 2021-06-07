#include <bits/stdc++.h> 
 
using namespace std; 
 
typedef vector<vector<double>> real_matrix; 
const double EPS = 1E-9; 
 
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
 
double determinant(real_matrix a, int n) { 
    double d = 1; 
    for (int i = 0; i < n; ++i) { 
        int k = i; 
        for (int j = i + 1; j < n; ++j) 
            if (abs(a[j][i]) > abs(a[k][i])) 
                k = j; 
        if (abs(a[k][i]) < EPS) { 
            d = 0; 
            break; 
        } 
        swap(a[i], a[k]); 
        if (i != k) 
            d = -d; 
        d = a[i][i] * d; 
        for (int j = i + 1; j < n; ++j) 
            a[i][j] /= a[i][i]; 
        for (int j = 0; j < n; ++j) 
            if (j != i && abs(a[j][i]) > EPS) 
                for (int k = i + 1; k < n; ++k) 
                    a[j][k] -= a[i][k] * a[j][i]; 
    } 
    return d; 
} 
 
vector<double> gauss_method(real_matrix a, vector<double> b, int n) { 
    double max; 
    int index; 
    int k = 0; 
    vector<double> x(n); 
 
    while (k < n) { 
        max = abs(a[k][k]); 
        index = k; 
        for (int i = k + 1; i < n; i++) { 
            if (abs(a[i][k]) > max) { 
                max = abs(a[i][k]); 
                index = i; 
            } 
        } 
        if (max < EPS) { 
            cout << "Решение получить невозможно" << endl; 
            return vector<double>(0, 0); 
        } 
        for (int j = 0; j < n; j++) { 
            double temp = a[k][j]; 
            a[k][j] = a[index][j]; 
            a[index][j] = temp; 
        } 
 
        double t = b[k]; 
        b[k] = b[index]; 
        b[index] = t; 
        for (int i = k; i < n; i++) { 
            t = a[i][k]; 
            if (abs(t) < EPS) continue; 
            for (int j = 0; j < n; j++) 
                a[i][j] = a[i][j] / t; 
            b[i] = b[i] / t; 
            if (i == k) continue; 
            for (int j = 0; j < n; j++) 
                a[i][j] = a[i][j] - a[k][j]; 
            b[i] = b[i] - b[k]; 
        } 
        k++; 
    } 
 
    for (k = n - 1; k >= 0; k--) { 
        x[k] = b[k]; 
        for (int i = 0; i < k; i++) 
            b[i] = b[i] - a[i][k] * x[k]; 
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
 
    double det = determinant(a, n); 
    cout << "Определитель: " << det << endl; 
 
    vector<double> x = gauss_method(a, b, n); 
    for (int i = 0; i < x.size(); i++) 
        cout << "x" << to_string(i) << " = " << x[i] << endl; 
} 

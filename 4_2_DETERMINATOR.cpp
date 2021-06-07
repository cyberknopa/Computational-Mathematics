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
int main() { 
    int n; 
    cout << "Введите n: " << endl; 
    cin >> n; 
 
    real_matrix a; 
    input_matrix(a, n); 
    double det = determinant(a, n); 
    cout << "Определитель: " << det << endl; 
 
return 0; 
} 

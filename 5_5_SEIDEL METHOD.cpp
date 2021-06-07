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
 
vector<double> Seidel_method(real_matrix a, vector<double> b, int n) { 
    vector<double> previous_x(n, 0.0); 
    for (int i = 0; i < n; i++) 
        previous_x[i] = b[i]; 
 
    while (true) { 
        vector<double> current_x(n); 
 
        for (int i = 0; i < n; i++) { 
            current_x[i] = b[i]; 
            for (int j = 0; j < n; j++) { 
                if (j < i) 
                    current_x[i] -= a[i][j] * current_x[j]; 
                if (j > i) 
                    current_x[i] -= a[i][j] * previous_x[j]; 
            } 
            current_x[i] /= a[i][i]; 
        } 
 
        double error = 0.0; 
        for (int i = 0; i < n; i++) 
            error += abs(current_x[i] - previous_x[i]); 
        if (error < EPS) 
            break; 
 
        previous_x = current_x; 
    } 
 
    return previous_x; 
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
 
    vector<double> x = Seidel_method(a, b, n); 
 
    for (int i = 0; i < x.size(); i++) 
        cout << "x" << to_string(i) << " = " << x[i] << endl; 
} 

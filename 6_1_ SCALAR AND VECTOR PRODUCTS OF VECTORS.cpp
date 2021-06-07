#include <bits/stdc++.h> 
 
using namespace std; 
 
typedef vector<vector<double>> real_matrix; 
 
void input_matrix(real_matrix &arr, int n) { 
    arr.resize(n); 
    arr[0].resize(n); 
    for (int j = 0; j < n; j++) 
        arr[0][j] = 1; 
    for (int i = 1; i < n; i++) { 
        cout << "Введите вектор " << to_string(i) << endl; 
        arr[i].resize(n); 
        for (int j = 0; j < n; j++) 
            cin >> arr[i][j]; 
    } 
} 
 
double scalar_multiply(const real_matrix & mat, int n) { 
    double result, t; 
    for (int j = 0; j < n; j++) { 
        t = 1; 
        for (int i = 0; i < n; i++) 
            t *= mat[i][j]; 
        result += t; 
    } 
    return result; 
} 
 
double vector_multiply(const real_matrix & mat, int n) { 
    double a; 
    real_matrix submat(n, vector<double>(n)); 
 
    if (n == 2) { 
        return ((mat[0][0] * mat[1][1]) - (mat[1][0] * mat[0][1])); 
    } 
    else { 
        for (int k = 0; k < n; k++) { 
            int subi = 0; 
            for (int i = 1; i < n; i++) { 
                int subj = 0; 
                for (int j = 0; j < n; j++) { 
                    if (j == k) 
                        continue; 
                    submat[subi][subj] = mat[i][j]; 
                    subj++; 
                } 
                subi++; 
            } 
            a = (pow(-1, k) * mat[0][k] * vector_multiply(submat, n - 1)); 
            cout << a << " "; 
        } 
        return 0; 
    } 
} 
 
int main() { 
    int n; 
    cout << "Введите n: " << endl; 
    cin >> n; 
 
    real_matrix a; 
    input_matrix(a, n); 
 
    cout << endl << "Скалярное произведение: " << scalar_multiply(a, n); 
    cout << endl << "Векторное произведение: "; 
    vector_multiply(a, n); 
 
    return 0; 
} 

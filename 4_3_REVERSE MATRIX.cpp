#include <iostream> 
using namespace std; 
 
void inversion(double **A, int N) 
{ 
    double temp; 
 
    double **E = new double *[N]; 
 
    for (int i = 0; i < N; i++) 
        E[i] = new double [N]; 
 
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) 
        { 
            E[i][j] = 0.0; 
 
            if (i == j) 
                E[i][j] = 1.0; 
        } 
 
    for (int k = 0; k < N; k++) 
    { 
        temp = A[k][k]; 
 
        for (int j = 0; j < N; j++) 
        { 
            A[k][j] /= temp; 
            E[k][j] /= temp; 
        } 
 
        for (int i = k + 1; i < N; i++) 
        { 
            temp = A[i][k]; 
 
            for (int j = 0; j < N; j++) 
            { 
                A[i][j] -= A[k][j] * temp; 
                E[i][j] -= E[k][j] * temp; 
            } 
        } 
    } 
 
    for (int k = N - 1; k > 0; k--) 
    { 
        for (int i = k - 1; i >= 0; i--) 
        { 
            temp = A[i][k]; 
 
            for (int j = 0; j < N; j++) 
            { 
                A[i][j] -= A[k][j] * temp; 
                E[i][j] -= E[k][j] * temp; 
            } 
        } 
    } 
 
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) 
            A[i][j] = E[i][j]; 
 
    for (int i = 0; i < N; i++) 
        delete [] E[i]; 
 
    delete [] E; 
} 
 
int main() 
{ 
    int N; 
 
    std::cout << "Введите размерность квадратной матрицы N: "; 
    std::cin >> N; 
 
    double **matrix = new double *[N]; 
    double **matrix2 = new double *[N]; 
    double **res = new double *[N]; 
    for (int i = 0; i < N; i++){ 
        matrix[i] = new double [N]; 
        matrix2[i] = new double [N]; 
        res[i] = new double [N]; 
    } 
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) 
        { 
            cout << "Введите элемент матрицы[" << i << "][" << j << "] = "; 
            cin >> matrix[i][j]; 
            matrix2[i][j] = matrix[i][j]; 
        } 
 
    inversion(matrix, N); 
    cout << "Обратная матрица:"<< '\n'; 
    for (int i = 0; i < N; i++) 
    { 
        for (int j = 0; j < N; j++) 
            cout <<matrix[i][j] << "  "; 
 
        cout << std::endl; 
    } 
 
    for (int i = 0; i < N; i++){ 
        for (int k = 0; k < N; k++){ 
            double el = 0.0; 
            for (int j = 0; j<N; j++) 
                el += matrix2[i][j]*matrix[j][k]; 
            res[i][k] = el; 
        } 
    } 
    cout << "Проверка:"<< '\n'; 
    for (int i = 0; i < N; i++) 
    { 
        for (int j = 0; j < N; j++) 
            cout <<res[i][j] << "  "; 
 
        cout << std::endl; 
    } 
 
    for (int i = 0; i < N; i++){ 
        delete [] matrix[i]; 
        delete [] matrix2[i]; 
        delete [] res[i]; 
    } 
 
 
    delete [] matrix; 
    delete [] matrix2; 
    delete [] res; 
 
    cin.get(); 
    return 0; 
} 

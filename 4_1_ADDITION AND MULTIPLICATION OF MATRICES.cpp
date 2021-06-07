#include <iostream> 
#include <complex> 
#include <cmath> 
 
using namespace std; 
 
class Matrix 
{ 
private: 
    complex <double>** matrix; 
    int n, m; 
    bool isSquared = false; 
public: 
    Matrix(int numberOfRows, int numberOfColumns) 
    { 
        n = numberOfRows; 
        m = numberOfColumns; 
        if (n == m) 
            isSquared = true; 
        matrix = new complex <double> * [n]; 
        for (int i = 0; i < n; ++i) 
        { 
            matrix[i] = new complex <double>[m]; 
            for (int j = 0; j < m; ++j) 
                matrix[i][j] = 0; 
        } 
    } 
    Matrix() 
    { 
        matrix = 0; 
        n = 0; 
        m = 0; 
    } 
    int numberOfRows() 
    { 
        return n; 
    } 
    int numberOfColumns() 
    { 
        return m; 
    } 
    bool IsSquared()  
    { 
        return isSquared; 
    } 
    complex <double>* operator [] (int index) 
    { 
        return getRow(index); 
    } 
    // получить строку матрицы 
    complex <double>* getRow(int index) 
    { 
        if (index < 0 || index >= n) 
            return 0; 
        return matrix[index]; 
    } 
}; 
    // прочитать матрицу из консоли 
    Matrix MarixInput() 
    { 
        int rows, columns; 
        cout << "Количество строк: "; 
        cin >> rows; 
        cout << "Количество столбцов: "; 
        cin >> columns; 
        Matrix a = Matrix(rows, columns); 
        cout << "Введите элементы матрицы через Enter: " << endl; 
        for (int i = 0; i < rows; ++i) 
            for (int j = 0; j < columns; ++j) 
                cin >> a[i][j]; 
        return a; 
    } 
    // вывести матрицу в консоль 
    void printMatrix(Matrix& a) 
    { 
        for (int i = 0; i < a.numberOfRows(); ++i) 
        { 
            for (int j = 0; j < a.numberOfColumns(); ++j) 
                cout << a[i][j] << " "; 
            cout << endl; 
        } 
    } 
 
    // сложить две матрицы 
    Matrix MatrixSumm(Matrix& firstMatrix, Matrix& secondMatrix) 
    { 
        Matrix a = firstMatrix; 
        Matrix b = secondMatrix; 
        if (a.numberOfRows() != b.numberOfRows() || a.numberOfColumns() != b.numberOfColumns()) 
        { 
            cout << "Ошибка. Матрицы нельзя сложить между собой. (Несовпадение размеров)" << endl; 
            return Matrix(); 
        } 
        Matrix result = Matrix(a.numberOfRows(), b.numberOfColumns()); 
        for (int i = 0; i < result.numberOfRows(); ++i) 
            for (int j = 0; j < result.numberOfColumns(); ++j) 
                result[i][j] = a[i][j] + b[i][j]; 
        return result; 
    } 
    // вычесть две матрицы 
    Matrix MatrixSubstraction(Matrix& firstMatrix, Matrix& secondMatrix) 
    { 
        Matrix a = firstMatrix; 
        Matrix b = secondMatrix; 
        if (a.numberOfRows() != b.numberOfRows() || a.numberOfColumns() != b.numberOfColumns()) 
        { 
            cout << "Ошибка. Произвести вычитание невозможно (Несовпадение размеров)." << endl; 
            return Matrix(); 
        } 
        Matrix result = Matrix(a.numberOfRows(), b.numberOfColumns()); 
        for (int i = 0; i < result.numberOfRows(); ++i) 
            for (int j = 0; j < result.numberOfColumns(); ++j) 
                result[i][j] = a[i][j] - b[i][j]; 
        return result; 
    } 
 
    // умножение матрицы на вещественное число 
    Matrix MatrixMultiplication(Matrix& matrix, double multiplicator) 
    { 
        int k = multiplicator; 
        Matrix result = Matrix(matrix.numberOfRows(), matrix.numberOfColumns()); 
        for (int i = 0; i < matrix.numberOfRows(); ++i) 
            for (int j = 0; j < matrix.numberOfColumns(); ++j) 
                result[i][j] = matrix[i][j] * multiplicator; 
        return result; 
    } 
 
    // умножение матрицы на комплексное число 
    Matrix MatrixMultiplication(Matrix& matrix, complex<double> multiplicator) 
    { 
        complex<double> k = multiplicator; 
        Matrix result = Matrix(matrix.numberOfRows(), matrix.numberOfColumns()); 
        for (int i = 0; i < matrix.numberOfRows(); ++i) 
            for (int j = 0; j < matrix.numberOfColumns(); ++j) 
                result[i][j] = matrix[i][j] * multiplicator; 
        return result; 
    } 
    // умножение двух матриц 
    Matrix MatrixMultiplication(Matrix& firstMatrix, Matrix& secondMatrix) 
    { 
        Matrix a = firstMatrix; 
        Matrix b = secondMatrix; 
        if (a.numberOfColumns() != b.numberOfRows()) 
        { 
            cout << "Ошибка. Нельзя произвести перемножение матриц. (Кол-во столбцов А != кол-во срок B" << endl; 
            return Matrix(); 
        } 
        Matrix c = Matrix(a.numberOfRows(), b.numberOfColumns()); 
        for (int i = 0; i < a.numberOfRows(); ++i) 
            for (int j = 0; j < b.numberOfColumns(); ++j) 
                for (int k = 0; k < a.numberOfColumns(); ++k) 
                    c[i][j] += a[i][k] * b[k][j]; 
        return c; 
    } 
 
    int main() 
    { 
        setlocale(LC_ALL, "Russian"); 
 
        complex<double> deter; 
        cout << "Ввод первой матрицы. Ввод комплексных чисел в формате (real, image)" << endl; 
        Matrix firstMatrix = MarixInput(); 
        cout << "Ввод второй матрицы. " << endl; 
        Matrix secondMatrix = MarixInput(); 
        cout << "Первая матрица A: " << endl; 
        printMatrix(firstMatrix); 
        cout << "Вторая матрица B:  " << endl; 
        printMatrix(secondMatrix); 
 
        cout << "A + B = " << endl; 
        Matrix sumOfTwo = MatrixSumm(firstMatrix, secondMatrix); 
        printMatrix(sumOfTwo); 
 
        cout << "A - B = " << endl; 
        Matrix subtrOfTwo = MatrixSubstraction(firstMatrix, secondMatrix); 
        printMatrix(subtrOfTwo); 
 
        cout << "Введите вещественный множитель: "; 
        double multNumber; 
        cin >> multNumber; 
        cout << "A * " << multNumber << " = " << endl; 
        Matrix multToNumber = MatrixMultiplication(firstMatrix, multNumber); 
        printMatrix(multToNumber); 
 
 
        cout << "Введите комплексный множитель: "; 
        complex<double> multNumber2; 
        cin >> multNumber2; 
        cout << "A * " << multNumber2 << " = " << endl; 
        multToNumber = MatrixMultiplication(firstMatrix, multNumber2); 
        printMatrix(multToNumber); 
 
        cout << "A * B = " << endl; 
        Matrix multOfTwo = MatrixMultiplication(firstMatrix, secondMatrix); 
        printMatrix(multOfTwo); 
        return 0; 
    } 

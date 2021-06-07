#include <complex> 
#include <iostream> 
#include <valarray> 
  
using namespace std; 
const double PI = 3.141592653589793238460; 
typedef complex<double> Complex; 
typedef valarray<Complex> CArray; 
void Fast_Fourier_transform(CArray& x) 
{ 
    const size_t N = x.size(); 
    if (N <= 1) return; 
    CArray even = x[slice(0, N/2, 2)]; 
    CArray  odd = x[slice(1, N/2, 2)]; 
    Fast_Fourier_transform(even); 
    Fast_Fourier_transform(odd); 
    for (size_t k = 0; k < N/2; ++k) 
    { 
        Complex t = polar(1.0, -2 * PI * k / N) * odd[k]; 
        x[k    ] = even[k] + t; 
        x[k+N/2] = even[k] - t; 
    } 
} 
void ifft(CArray& x) 
{ 
    x = x.apply(conj); 
    Fast_Fourier_transform(x); 
    x = x.apply(conj); 
    x /= x.size(); 
} 
  
int main() 
{ 
    const Complex test[] = { 0.0, 1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0 }; 
    CArray data(test, 8); 
    Fast_Fourier_transform(data); 
    cout << "Быстрое преобразование Фурье:" << endl; 
    for (int i = 0; i < 8; ++i) 
    { 
        cout << data[i] << endl; 
    } 
    ifft(data); 
    cout << endl << "Обратное преобразование Фурье:" << endl; 
    for (int i = 0; i < 8; ++i) 
    { 
        cout << data[i] << endl; 
    } 
    return 0; 
} 

#include <cstdlib> 
#include <iostream> 
#include <cmath> 
  
using namespace std; 
#define pi 3.1415926 
int n; 
double* a,*b; 
double Function(double); 
double A(int j) 
{ 
    double S=0; 
    int ii; 
    for (int i=-n;i<n+1;i++) 
    { 
  
        S=S+Function(2*pi*double(i)/(2*n+1))*cos(2*pi*double(j)*double(i)/(2*n+1)); 
    } 
    if (j==0) return 1/double(2*n+1)*S; 
  
    return 2/double(2*n+1)*S; 
} 
double B(int j) 
{ 
    int ii; 
    double S=0; 
    for (int i=-n;i<n+1;i++) 
    { 
        ii=-n+i; 
        S=S+Function(2*pi*double(i)/double(2*n+1))*sin(2*pi*double(j*i)/double(2*n+1)); 
    } 
    return 2/double(2*n+1)*S; 
} 
double Function(double x) 
{ 
    if (x<-1.5) return double(1); 
    if (x>=-1.5 && x<1.6) return 0.5; 
    return -0.333; 
} 
double Interpolate(double x) 
{ 
    double S=a[0]; 
    for (int i=1;i<n;i++) 
    { 
        S=S+a[i]*cos(double(i)*x)+b[i]*sin(double(i)*x); 
    } 
    return S; 
} 
int main() 
{ 
    double size; 
    cout <<"Введите число интерполяционных членов: "; 
    cin>>n; 
    cout<<"Введите размер результирующего вектора: "; 
    cin >>size; 
  
  
    a=new double[n]; 
    b=new double[n]; 
  
    cout <<endl; 
    cout<<"Коэффициент a :"<<endl << endl; 
    for (int j=0; j<n;j++) 
    { 
        a[j]=A(j); 
        cout<<a[j]<<endl; 
    } 
    cout <<endl; 
    cout<<"Коэффициент b :"<<endl << endl; 
    for (int j=1; j<n;j++) 
    { 
        b[j]=B(j); 
        cout<<b[j]<<endl; 
    } 
    cout <<endl; 
    double x; 
    cout<< "Координаты и значения в них:"<<endl; 
    for (int j=0;j<size;j++) 
    { 
        x=-pi+2*pi/size*j; 
        cout<<x<<"\t"<<Function(x)<<endl; 
    } 
    for (int j=0;j<size;j++) 
    { 
        x=-pi+2*pi/size*j; 
        cout<<x<<"\t"<<Interpolate(x)<<endl; 
    } 
    cout<< endl<<"Ошибка: "<<endl; 
    for (int j=0;j<n;j++) 
    { 
        x=-pi+2*pi/size*j; 
        cout<<x<<"\t"<<Interpolate(x)-Function(x)<<endl; 
    } 
  
    return 0; 
} 

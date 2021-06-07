#include <iostream> 
#include <math.h> 
#include <vector> 
  
using namespace std; 
struct dat { 
  double y; 
  double x; 
}; 
int fack(int x) { 
  if( x == 0 ) return 1; 
  return x * fack(x - 1); 
  } 
double delta(vector<dat> a, int index, int num) { 
  if (index == 1) { 
    return a[num+1].y - a[num].y; 
    } 
  else { 
    return delta(a, index-1, num+1) - delta(a, index-1, num); 
    } 
} 
  
int main() { 
  int n; 
  vector<dat> arr; 
  dat z; 
  cout << "Введите число точек: " << endl; 
  cin >> n; 
  cout << "Введите точки, с разделением координат пробелом: "<< endl; 
  for(int i = 0; i < n; i++) { 
    cin >> z.y >> z.x; 
    arr.push_back(z); 
  } 
  cout << "Введите искомую точку: " << endl; 
  double X; 
  cin >> X; 
  double step = arr[1].x - arr[0].x; 
  double q =  X - arr[0].x / step; 
  int n1 = 0; 
  if (n % 2 != 1) { 
    n1 = n*0.5; 
  } 
  else { 
    n1 = (n+1)*0.5; 
  } 
  double summ = arr[n1].y + q*(arr[n1+1].y-arr[n1].y); 
  int key = 0; 
  for(int i = 3; i < n1; i++) { 
    if (key % 2 == 0) { 
      summ += pow(q,i)*delta(arr,n1-i,key*0.5)/fack(i); 
    } 
    else { 
      q += i*0.5-1; 
      summ += pow(q,i)*delta(arr, n1-1,(key-1)*0.5)/fack(i); 
    } 
    key++; 
    } 
  cout << "Формула 1: " << summ << endl; 
  summ = arr[0].y; 
  key = 2; 
  for(int i = 1; i < n1; i++) { 
    if (key % 2 == 0) { 
      summ += pow(q,i)*delta(arr,n1-i,key*0.5)/fack(i); 
    } 
    else { 
      q += i*0.5-1; 
      summ += pow(q,i)*delta(arr, n1-1,(key-1)*0.5)/fack(i); 
    } 
    key++; 
    } 
  cout << "Формула 2:" << summ << endl; 
} 

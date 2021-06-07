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
  cout << "Введите точки, с разделением координат пробелом: " << endl; 
  for(int i = 0; i < n; i++) { 
    cin >> z.y >> z.x; 
    arr.push_back(z); 
  } 
  cout << "Введите искомую точку: " << endl; 
  double X; 
  cin >> X; 
  double summ = arr[0].y; 
  double step = arr[1].x - arr[0].x; 
  double q =  X - arr[0].x / step; 
  double thing = q; 
  for(int i = 1; i < n; i++) { 
    summ += thing*(delta(arr, i, 0))/fack(i); 
    thing *= (q - i); 
    } 
  cout << summ << endl; 
} 

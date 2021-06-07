#include <iostream> 
#include <vector> 
 
std::vector <double> dif_finite_differences(const std::vector<double> &data, double h) 
{ 
if (data.size() == 0 || h <= 0) 
throw "Неверные входные данные"; 
std::vector <double> res(data.size() - 1); 
 
for (int index = 0; index < res.size(); ++index) 
res[index] = (data[index + 1] - data[index]) / h; 
 
return res; 
} 
 
int main() 
{ 
std::vector<double> func{ 3.912, 3.951, 3.989, 4.025, 4.06, 4.094, 4.127, 4.159, 4.19, 4.22 }; 
double h = 2; 
double x0 = 50; 
std::vector<double> first_differences = dif_finite_differences(func, h); 
std::vector<double> second_differences = dif_finite_differences(first_differences, h); 
std::vector<double> third_differcences = dif_finite_differences(second_differences, h); 
 
std::cout << "Функция:\n"; 
for (int index = 0; index < func.size(); ++index) 
std::cout << "f(" << x0 + index * h << ") = " << func[index] << std::endl; 
 
std::cout << "Первая производная через левые конечные разности: \n"; 
for (int index = 0; index < first_differences.size(); ++index) 
std::cout << "f'(" << x0 + h + index * h << ") = " << first_differences[index] << std::endl; 
 
std::cout << "Вторая производная через левые конечные разности: \n"; 
for (int index = 0; index < second_differences.size(); ++index) 
std::cout << "f'’(" << x0 + 2 * h + index * h << ") = " << second_differences[index] << std::endl; 
 
std::cout << "Третья производная через левые конечные разности: \n"; 
for (int index = 0; index < third_differcences.size(); ++index) 
std::cout << "f'’’(" << x0 + 3 * h + index * h << ") = " << third_differcences[index] << std::endl; 
 
std::cout << "Первая производная через правые конечные разности: \n"; 
for (int index = 0; index < first_differences.size(); ++index) 
std::cout << "f'(" << x0  + index * h << ") = " << first_differences[index] << std::endl; 
 
std::cout << "Вторая производная через правые конечные разности: \n"; 
for (int index = 0; index < second_differences.size(); ++index) 
std::cout << "f'’(" << x0  + index * h << ") = " << second_differences[index] << std::endl; 
 
std::cout << "Третья производная через правые конечные разности: \n"; 
for (int index = 0; index < third_differcences.size(); ++index) 
std::cout << "f'’’(" << x0 + index * h << ") = " << third_differcences[index] << std::endl; 
 
system("pause"); 
return 0; 
} 

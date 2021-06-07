#include <iostream> 
#include <vector> 
using namespace std; 
 
double count_finite_differences(const vector<double> &data, int start, int k) 
{ 
    if (start < 0 || k <= 0) 
        throw "Неверные входные данные"; 
    if (start + k > data.size() - 1) 
        return 0; 
 
    vector<double> differences(k); 
    for (int index = 0; index < differences.size(); ++index) 
        differences[index] = data[start + index + 1] - data[start + index]; 
 
    while (differences.size() > 1) 
    { 
        for (int index = 0; index < differences.size() - 1; ++index) 
            differences[index] = differences[index + 1] - differences[index]; 
        differences.pop_back(); 
    } 
 
    return differences[0]; 
} 
vector<double> count_first_diffirencial(const vector<double> &data, double h) 
{ 
    vector<double> res(data.size()); 
    for (int index = 0; index < res.size(); ++index) 
    { 
        res[index] = (count_finite_differences(data, index, 1) - count_finite_differences(data, index, 2) / 2 + count_finite_differences(data, index, 3) / 3 - count_finite_differences(data, index, 4) / 4 + count_finite_differences(data, index, 5) / 5 ) / h; 
    } 
    return res; 
} 
 
vector<double> count_second_diffirencial(const std::vector<double> &data, double h) 
{ 
    vector<double> res(data.size()); 
    for (int index = 0; index < res.size(); ++index) 
    { 
        res[index] = (count_finite_differences(data, index, 2) - count_finite_differences(data, index, 3) + count_finite_differences(data, index, 4) * 11/ 12 - count_finite_differences(data, index, 5) * 5 / 6) / h / h; 
    } 
    return res; 
} 
 
int main() 
{ 
    vector<double> func{ 3.912, 3.951, 3.989, 4.025, 4.06, 4.094, 4.127, 4.159, 4.19, 4.22 }; 
    double h = 2; 
    double x0 = 50; 
 
    auto first_differences = count_first_diffirencial(func, h); 
    auto second_differences = count_second_diffirencial(func, h); 
 
    cout << "Функция:\n"; 
    for (int index = 0; index < func.size(); ++index) 
        cout << "f(" << x0 + index * h << ") = " << func[index] << std::endl; 
 
    cout << "Первая производная через левые конечные разности: \n"; 
    for (int index = 0; index < first_differences.size(); ++index) 
        cout << "f'(" << x0 + h + index * h << ") = " << first_differences[index] << std::endl; 
 
    cout << "Вторая производная через левые конечные разности: \n"; 
    for (int index = 0; index < second_differences.size(); ++index) 
        cout << "f''(" << x0 + 2 * h + index * h << ") = " << second_differences[index] << std::endl; 
    return 0; 
} 

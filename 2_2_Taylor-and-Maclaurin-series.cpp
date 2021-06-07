//2.2
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

double* r_ln(double x, int n){			
	double* pack = new double[3];
	pack[0] = 0; // result	
	for (int i = 1; i <= n; i++) pack[0] += pow(-1, i + 1) * pow(x, i) / i;	
	double q = 0.9999;
	pack[1] = pow(-1, n + 1) * (1 + x) / (n * (n + 1) * pow(q, n)); // tail part
	pack[2] = pack[0] - log(1 + x); // mistake	
	return pack;
}
double factor(int n){	
	double k = 1.0;
	for (int i = 1; i <= n ; i++) k *= i;
	return k;
}
double* r_sin(double x, int n){
	double* pack = new double[3];
	pack[0] = 0;
	for (int i = 0; i <= n; i++) pack[0] += pow(-1, i) * pow(x, 2*i + 1) / factor(2*i + 1);
	pack[1] = pow(x, 2*n + 1) / factor(2*n + 1);
        	pack[2] = pack[0] - sin(x);
	return pack;
}

double* r_cos(double x, int n){
        double* pack = new double[3];
        pack[0] = 0;
        for (int i = 0; i <= n; i++) pack[0] += pow(-1, i) * pow(x, 2*i) / factor(2*i);
        pack[1] = pow(x, 2*n) / factor(2*n);
        pack[2] = pack[0] - sin(x);
        return pack;
}
int main(){	
	while (1) {
		cout << "[*]Режим работы программы: \n";
		cout << "[1] – Демонстрация\n";
		cout << "[2] - Вывод в файл зависимостей точных значений, остаточных членов и ошибок вычисления от числа членов ряда \n";
		cout << "[3] – Выход\n";
		int regime;
		cin >> regime;
		if (regime == 1){
			cout << "[*]Для выбора введите число и нажмите Enter: \n";
			cout << "[1] - Логарифмическая функция\n”;
			cout << "[2] - Гармоническая функция\n";
			int var;
			cin >> var;
			if (var == 1){
				double x;
				int n;
				cout << "[*]Введите значение х: ";
				cin >> x;
				if (x <= 1.0 && x > -1.0){
					cout << "[*]Введите значение n: ";
					cin >> n;
					double* res = r_ln(x, n);
					cout << "--Значение функции в заданной точке: " << res[0] << "\n";
					cout << "--Значение остаточного члена: " << res[1] << "\n";
					cout << "--Значение ошибки вычисления: " << res[2] << "\n";
				}
				else cout << "[*]Значение х для разложения ln(1+x) в ряд Маклорена должно быть в полуинтервале (-1.0, 1.0]\n";
			}
			if (var == 2){
				double x;
				int n;
				cout << "[*]Введите значение х: ";
				cin >> x;
				if (x >= 0 && x <= M_PI/4){
					cout << "[*]Введите значение n: ";
					cin >> n;
					double* res = r_sin(x, n);
					cout << "--Значение функции в заданной точке: " << res[0] << "\n";
					cout << "--Абсолютное значение остаточного члена <=  " << res[1] << "\n";
					cout << "--Значение ошибки вычисления: " << res[2] << "\n";
				}
				else if (x >= M_PI/4 && x <= M_PI/2){
					cout << "[*]Введите значение n: ";
					cin >> n;
					double* res = r_sin(M_PI - x, n);
					cout << "--Значение функции в заданной точке: " << res[0] << "\n";
					cout << "--Абсолютное значение остаточного члена <=  " << res[1] << "\n";
					cout << "--Значение ошибки вычисления: " << res[2] << "\n";
				}
				else cout << "[*]Значение х для разложения Sin(x) в ряд Маклорена должно находится в отрезке [0, pi/2]\n";
			}
		}
if (regime == 2){
			ofstream fout;
			double x1, x2;
			int Nmax;
			cout << "[*]Введите максимальное кол-во членов для разложения в ряды Маклорена логарифмической и гармоничеcкой функций: ";
			cin >> Nmax;
			fout.open("logsLN.txt");
			if (!fout.is_open()) {
				cout << "[*]Ошибка при открытии файла для записи. Файл logsLN.txt не существует или поврежден, создаю новый файл.\n";
				ofstream fout("logsLN.txt");
			}
			cout << "[*]Введите значение х1 (для ln(1+x1)): ";
			cin >> x1;
			if (x1 <= 1.0 && x1 > -1.0){
				fout << "n,точное значение,остаточный член,ошибка\n";	
				for (int n = 1; n <= Nmax; n++){
					double* res = r_ln(x1, n);
					fout << n << "," << res[0] << "," << res[1] << "," << res[2] <<  "\n";
				}
			}
			else cout << "[*]Значение х для разложения ln(1+x) в ряд Маклорена должно быть в полуинтервале (-1.0, 1.0]\n";
			fout.close();
			fout.open("logsSIN.txt");
			if (!fout.is_open()){
			       	cout << "[*]Ошибка при открытии файла для записи. Файл logsSIN.txt не существует или поврежден, создаю новый файл.\n";
				ofstream fout("logsSIN.txt");
			}
			cout << "[*]Введите значение х2 (для Sin(x2)): ";
			cin >> x2;
			fout << "n,точное значение,остаточный член,ошибка\n";
			if (x2 >= 0 && x2 <= M_PI/4){
				for (int n = 1; n <= Nmax; n++){
					double* res = r_sin(x2, n);
					fout << n << "," << res[0] << "," << res[1] << "," << res[2] <<  "\n";
				}
			}
			else if (x2 >= M_PI/4 && x2 <= M_PI/2){
				for (int n = 1; n <= Nmax; n++){
					double* res = r_cos(M_PI - x2, n);
                                        				fout << n << "," << res[0] << "," << res[1] << "," << res[2] <<  "\n";
				}
			}
			else cout << "[*]Значение х для разложения Sin(x) в ряд Маклорена должно находится в отрезке [0, pi/2]\n";
		}
		if (regime == 3) break;
	}
	return 0;
}

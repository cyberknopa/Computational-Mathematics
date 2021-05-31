//1.1
#include <bits/stdc++.h>

using namespace std;

int main() {
string s1, s2;
double a, da, b, db;
string tmp1, tmp2, tmp3, tmp4;
cin >> tmp1 >> s1 >> tmp2 >> s2 >> tmp3 >> s1 >> tmp4;

int a1 = tmp1.size() - tmp1.find(".") - 1;
int a3 = tmp3.size() - tmp3.find(".") - 1;
int a2 = tmp2.size() - tmp2.find(".") - 1;
int a4 = tmp4.size() - tmp4.find(".") - 1;
int k1 = max(a1, a3);
int k2 = max(a2, a4);
int k = max(k1, k2);
a = stod(tmp1);
da = stod(tmp2);
b = stod(tmp3);
db = stod(tmp4);
double rez, drez;
if(s2 == "+") {
rez = a + b;
drez = da + db;
cout.setf(std::ios::fixed);
cout.precision(k);
cout << rez << " +- ";
cout.precision(k);
cout « drez;

}
if(s2 == "-") {
rez = a - b;
drez = da + db;
cout.setf(std::ios::fixed);
cout.precision(k);
cout << rez << " +- ";
cout.precision(k);
cout « drez;
}
if(s2 == "*") {
rez = a * b;
drez = (da/a + db/b)*rez;
cout.setf(std::ios::fixed);
cout.precision(k);
cout << rez << " +- ";
cout.precision(k);
cout << drez;
}
if(s2 == "/") {
rez = a / b;
drez = (da/a + db/b)*rez;
cout.setf(std::ios::fixed);
cout.precision(k);
cout << rez << " +- ";
cout.precision(k);
cout << drez;
}
return 0;
}

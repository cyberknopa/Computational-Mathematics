//2.1
#include <stdlib.h>
#include <stdio.h>
int main(){
	printf(" Введите степень многочлена: "); 
	int n, e;
	scanf("%d", &n);
	int* a = (int*) calloc(n+1, sizeof(int));
	int* b = (int*) calloc(n, sizeof(int));
	printf(" Введите коэффициенты многочлена (по
 	возрастанию степени): ");
	for (int i = 0; i < (n+1); i++){ 
	scanf("%d", &a[i]);
	}
	printf(" Введите  свободный член делящего двучлена: ");
	scanf("%d", &e);
	b[n-1] = a[n];
printf("Результат деления: ");
for (int i = n - 1; i > 0; i--){ 
b[i-1] = b[i]*e + a[i];
printf("%d*x^%d ", b[i], i);
if (i>1) printf("+ "); 
}
printf(";  Остаток: %d\n", b[0]);
int* k = (int*) calloc(n, sizeof(int));
k[n-1] = b[n-1];
for (int i = n - 2; i > 0; i--){
k[i] = b[i-1] - e*b[i];
if (k[i]!=a[i]){
free(k);
free(a);
free(b);
printf("Проверка не пройдена \n");
return 0;
}
}
free(k);
free(a);
free(b);
printf("Проверка пройдена \n");
return 0;
}

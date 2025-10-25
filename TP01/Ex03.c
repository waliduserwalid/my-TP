#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int f1(int n) {

	int u0 = 1, u1 = 1, Un;
	if(n <= 1) {
		return 1;
	}else {
		for(int i = 2; i <= n; i++) {
			Un = u1 + u0;
			u0 = u1;
			u1 = Un;
		}
		return Un;
	}

}

int f2(int n) {

	if(n <= 1) {
		return 1;
	}else {
		return f2(n - 1) + f2(n - 2);
	}
}


int main() {
	clock_t T1, T2, T3, T4;
	int n;
	printf("Taper la valeur de n : ");
	scanf("%d", &n);

	T1 = clock();
	f1(n);
	T2 = clock();

	float temps1 = (double)(T2 - T1) / (double)CLOCKS_PER_SEC;
	
	T3 = clock();
	f2(n);
	T4 = clock();

	float temps2 = (double)(T4 - T3) / (double)CLOCKS_PER_SEC;

	printf("Le temp d'execution de f1 est : %.3f second(s) \n", temps1);
	printf("Le temp d'execution de f2 est : %.3f second(s) \n", temps2);


	return 0;
}

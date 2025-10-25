#include <stdio.h>
#include <stdlib.h>

int main() {

	int i, n;
	long S = 0, N = 0;


	printf("Taper le nombre n : ");
	scanf("%d", &n);

	for(i = 1; i <= n; i++) {
		S += i;
		N++;
	}

	printf("La somme est : %ld \n", S);
	printf("Le nombre d'iterations est : %ld \n", N);

	return 0;
}

#include <stdio.h>
#include <stdlib.h>


int main() {

	int i, j, n;
	long S = 0, N = 0;

	printf("Taper le nombre n : ");
	scanf("%d", &n);

	for(i = 1; i <= n; i++) {
		for(j = 1; j <= i; j++) {
			S += 1;
			N++;
		}
	}

	printf("La somme est : %ld \n", S);
	printf("Le nombre d'iteration est : %ld \n", N);

	return 0;
}

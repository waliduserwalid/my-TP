#include <stdio.h>
#include <stdlib.h>



int main() {
	
	int n;
	long S;

	printf("Taper le nombre n : ");
	scanf("%d", &n);

	S = n * (n + 1) / 2;

	printf("La somme est : %ld \n", S);


	return 0;
}

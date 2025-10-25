#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool estTri(int T[], int n) {

	for(int i = 0; i < n - 1; i++) {

		if(T[i] > T[i + 1]) {
			return false;
		}
	
	}

	return true;


}



bool valeurExiste(int T[], int n, int x) {

	if(estTri(T, n)) {

		int a = 0;
		int b = n - 1;
		while(b >= a) {

			int p = (a + b) / 2;
			if(T[p] == x) {
				return true;
			}else if(T[p] > x) {
				b = p - 1;
			}else {
				a = p + 1;
			}
		
		}
	}

	return false;



}



int nombreOccurrence(int T[], int n, int x) {

	int cpt = 0;
	if(valeurExiste(T, n, x)) {

		for(int i = 0; i < n; i++) {
			if(T[i] == x) {
				cpt++;
			}
		}
	
	}

	return cpt;


}



int main() {

	int T[100];
	int n;
	int A[100];

	do{
		printf("Taper la taille de tableau (Max = 100) : ");
		scanf("%d", &n);
	
	}while((n <= 0) || (n > 100));

	printf("Taper les valeur de Tableau : \n");
	for(int i = 0; i < n; i++) {

		scanf("%d", &T[i]);
	}

	if(estTri(T, n)) {

		for(int i = 0; i < n; i++) {

			int tmp = nombreOccurrence(T, n, T[i]);
			A[i] = tmp;
		
		}
		int max = A[0];
		for(int i = 0; i < n; i++) {
		
			if(A[i] > max) {
				max = A[i];
			}
		}

		printf("La taille de la plus grande sequence : %d \n", max);
	
	}else {
		printf("Le Tableau n'est pas Trier. \n");
	
	}


	return 0;
}

#include <stdio.h>
#include <stdlib.h>


long rechdich(int T[], int N, int x){

	int a = 0, b = N - 1,  p;
	long i = 0;
	while(b >= a) {
		i++;
		p = (a + b) / 2;
		if(T[p] == x) {
			break;
		}else if(T[p] > x) {
			b = p - 1;
		}else {
			a = p + 1;
		}
	
	}
	return i;


}

long rechseq(int T[], int N, int x) {
	long i = 0;
	
	for(int j = 0; j < N; j++) {
		i++;
		if(T[j] == x) {
			break;
		}
	}

	return i;
}



int main() {

	int T[10000];
	int x;
	for(int i = 0; i < 10000; i++) {
		T[i] = i;
	}


	int N = sizeof(T) / sizeof(T[0]);
	printf("Taper la valeur de x : ");
	scanf("%d", &x);
	printf("La recherche sequentielle : %ld \n", rechseq(T, x, N));
	printf("La recherche dichmotomique : %ld \n", rechdich(T, x, N));


	return 0;
}

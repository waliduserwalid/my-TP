#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>



void TriParSelection(int T[]) {

	int m, temp;

	for(int i = 0; i < 999; i++) {
		
		m = i;
		for(int j = i + 1; j < 1000; j++) {
		
			if(T[m] > T[j]) {
			
				m = j;
				temp = T[m];
				T[m] = T[j];
				T[j] = temp;
				m = i;
			}
		}
	}



}



void TriParInsertion(int T[]) {

	int x, y;

	for(int i = 1; i < 1000; i++) {
	
		x = T[i];
		y = i - 1;
		while((y >= 0) && (T[y] > x)) {
		
			T[y + 1] = T[y];
			y--;
		}

		T[y + 1] = x;
	}


}



void TriABulles(int T[]) {

	int temp;
	for(int i = 0; i < 999; i++) {
	
		for(int j = 0; j < 999 - i; j++) {
		
			if(T[j] > T[j + 1]) {
			
				temp = T[j];
				T[j] = T[j + 1];
				T[j + 1] = temp;
			}
		}
	}



}



void Fusion(int T[], int debut, int millieu, int fin) {

	int i1 = debut, i2 = millieu + 1, i = 0, temp[1000];
	while((i1 <= millieu) && (i2 <= fin)) {
	
		if(T[i1] < T[i2]) {
		
			temp[i] = T[i1];
			i1++;

		}else {
		
			temp [i] = T[i2];
			i2++;
		}
		i++;
	}
	while(i1 <= millieu) {
	
		temp[i] = T[i1];
		i++;
		i1++;
	}

	while(i2 <= fin) {
	
		temp[i] = T[i2];
		i++;
		i2++;
	}

	for(int k = 0; k < i; k++) {
		
		T[debut + k] = temp[k];
	}

}



void TriFusion(int T[], int debut, int fin) {

	int millieu;
	if(debut < fin) {
		
		millieu = (debut + fin) / 2;
		TriFusion(T, debut, millieu);
		TriFusion(T, millieu + 1, fin);
		Fusion(T, debut, millieu, fin);
	}




}



int partition(int T[], int debut, int fin) {

        int pivot = T[fin];
        int i = (debut - 1);
        for(int j = debut; j < fin; j++) {

                if(T[j] <= pivot) {

                        i++;
                        int temp = T[i];
                        T[i] = T[j];
                        T[j] = temp;
                }
        }

        int temp = T[i + 1];
        T[i + 1] = T[fin];
        T[fin] = temp;
        return (i + 1);

}



void TriRapide(int T[], int debut, int fin) {

	if(debut < fin) {

		int pi = partition(T, debut, fin);
		TriRapide(T, debut, pi - 1);
		TriRapide(T, pi + 1, fin);
	}


}



int main() {
	
	srand(time(NULL));
	clock_t T1, T2;
	float temps;
	int Tab1[1000];
	int Tab2[1000];
	int Tab3[1000];
	int Tab4[1000];
	int Tab5[1000];


	for(int i = 0; i < 1000; i++) {
		
		Tab1[i] = rand() % 1001;
	}
	
	for(int i = 0; i < 1000; i++) {
	
		Tab2[i] = rand() % 1001;
	} 

	for(int i = 0; i < 1000; i++) {
	
		Tab3[i] = rand() % 1001;
	}

	for(int i = 0; i < 1000; i++) {
	
		Tab4[i] = rand() % 1001;
	}

	for(int i = 0; i < 1000; i++) {
	
		Tab5[i] = rand() % 1001;
	}


	T1 = clock();
	TriParSelection(Tab1);
	T2 = clock();
	temps = (double)(T2 - T1) / (double)CLOCKS_PER_SEC;
	printf("Le temps pour Tri par selection est : %.3f secende(s) .\n", temps);

	T1 = clock();
	TriParInsertion(Tab2);
	T2 = clock();
	temps = (double)(T2 - T1) / (double)CLOCKS_PER_SEC;
	printf("Le temps pour Tri par insertion est : %.3f secende(s) .\n", temps);

	T1 = clock();
	TriABulles(Tab3);
	T2 = clock();
	temps = (double)(T2 - T1) / (double)CLOCKS_PER_SEC;
	printf("Le temps pour Tri a bulles est : %.3f secende(s) .\n", temps);

	T1 = clock();
	TriFusion(Tab4, 0, 999);
	T2 = clock();
	temps = (double)(T2 - T1) / (double)CLOCKS_PER_SEC;
	printf("Le temps pour Tri fusion est : %.3f secende(s) .\n", temps);

	T1 = clock();
	TriRapide(Tab5, 0, 999);
	T2 = clock();
	temps = (double)(T2 - T1) / (double)CLOCKS_PER_SEC;
	printf("Le temps pour Tri rapide est : %.3f secende(s) .\n", temps);


	return 0;

}

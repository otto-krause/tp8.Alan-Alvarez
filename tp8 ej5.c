#include <stdio.h>

#define NUM_SORTEOS 3
#define NUM_NUMEROS 6
#define MIN_NUM 0
#define MAX_NUM 42

int main() {
	int sorteos[NUM_SORTEOS][NUM_NUMEROS];
	int repeticiones[NUM_NUMEROS] = {0};
	int n;
	
	for (int i = 0; i < NUM_SORTEOS; i++) {
		for (int j = 0; j < NUM_NUMEROS; j++) {
			sorteos[i][j] = -1;
		}
	}
	
	for (int s = 0; s < NUM_SORTEOS; s++) {
		printf("Ingresar 6 números para el sorteo %d (de %d a %d, sin repetir):\n", s + 1, MIN_NUM, MAX_NUM);
		for (int i = 0; i < NUM_NUMEROS; i++) {
			int numero;
			int repetido;
			do {
				repetido = 0;
				printf("Número %d: ", i + 1);
				scanf("%d", &numero);
				
				if (numero < MIN_NUM || numero > MAX_NUM) {
					printf("Número fuera de rango. Ingrese un número entre %d y %d.\n", MIN_NUM, MAX_NUM);
					repetido = 1;
				}
				
				for (int j = 0; j < i; j++) {
					if (sorteos[s][j] == numero) {
						printf("Número repetido. Ingrese un número diferente.\n");
						repetido = 1;
						break;
					}
				}
			} while (repetido);
			
			sorteos[s][i] = numero;
		}
	}
	
	for (int s = 0; s < NUM_SORTEOS; s++) {
		for (int i = 0; i < NUM_NUMEROS - 1; i++) {
			for (int j = 0; j < NUM_NUMEROS - i - 1; j++) {
				if (sorteos[s][j] > sorteos[s][j + 1]) {
					int temp = sorteos[s][j];
					sorteos[s][j] = sorteos[s][j + 1];
					sorteos[s][j + 1] = temp;
				}
			}
		}
	}
	
	int maxRepeticiones = 0;
	for (int s = 0; s < NUM_SORTEOS; s++) {
		for (int i = 0; i < NUM_NUMEROS; i++) {
			int numero = sorteos[s][i];
			repeticiones[numero]++;
			if (repeticiones[numero] > maxRepeticiones) {
				maxRepeticiones = repeticiones[numero];
			}
		}
	}
	
	printf("\nNúmeros más repetidos:");
	for (int i = 0; i < NUM_NUMEROS; i++) {
		if (repeticiones[i] == maxRepeticiones) {
			printf(" %d", i);
		}
	}
	
	printf("\n");
	
	printf("\nIngrese un número N: ");
	scanf("%d", &n);
	
	int repeticionesN = 0;
	for (int s = 0; s < NUM_SORTEOS; s++) {
		for (int i = 0; i < NUM_NUMEROS; i++) {
			if (sorteos[s][i] == n) {
				repeticionesN++;
			}
		}
	}
	
	printf("El número %d se repite %d veces entre todos los sorteos.\n", n, repeticionesN);
	
	printf("\nSorteos ordenados:\n");
	for (int s = 0; s < NUM_SORTEOS; s++) {
		printf("Sorteo %d: ", s + 1);
		for (int i = 0; i < NUM_NUMEROS; i++) {
			printf("%d ", sorteos[s][i]);
		}
		printf("\n");
	}
	
	return 0;
}

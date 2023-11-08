#include <stdio.h>

int main() {
	int matriz[6][5] = {0};  
	
	int fila, columna, valor;
	
	while (1) {
		printf("Ingrese el número de fila (1-6) o 0 para finalizar: ");
		scanf("%d", &fila);
		
		if (fila == 0) {
			break;
		}
		
		if (fila < 1 || fila > 6) {
			printf("Número de fila no válido. Ingrese un valor entre 1 y 6.\n");
			continue;
		}
		
		printf("Ingrese el número de columna (1-5): ");
		scanf("%d", &columna);
		
		if (columna < 1 || columna > 5) {
			printf("Número de columna no válido. Ingrese un valor entre 1 y 5.\n");
			continue;
		}
		
		printf("Ingrese el valor a cargar en la posición (%d, %d): ", fila, columna);
		scanf("%d", &valor);
		
		matriz[fila - 1][columna - 1] = valor;
	}
	
	printf("Matriz por filas:\n");
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
	
	printf("Matriz por columnas:\n");
	for (int j = 0; j < 5; j++) {
		for (int i = 0; i < 6; i++) {
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

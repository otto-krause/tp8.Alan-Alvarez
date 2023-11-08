#include <stdio.h>

int main() {
	int matriz[3][3];  
	
	printf("Ingresar valores en las columnas pares:\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j += 2) {
			printf("Ingrese el valor en la fila %d, columna %d: ", i + 1, j + 1);
			scanf("%d", &matriz[i][j]);
		}
	}
	
	printf("Ingresar valores en las columnas impares:\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 1; j < 3; j += 2) {
			printf("Ingrese el valor en la fila %d, columna %d: ", i + 1, j + 1);
			scanf("%d", &matriz[i][j]);
		}
	}
	
	printf("Contenido de la matriz:\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

#include <stdio.h>

int main() {
	int matriz[5][5];  
	
	printf("Ingresar la diagonal principal:\n");
	for (int i = 0; i < 5; i++) {
		printf("Ingrese el valor en la fila %d, columna %d: ", i + 1, i + 1);
		scanf("%d", &matriz[i][i]);
	}
	
	printf("Ingresar el triángulo superior:\n");
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			printf("Ingrese el valor en la fila %d, columna %d: ", i + 1, j + 1);
			scanf("%d", &matriz[i][j]);
		}
	}
	
	printf("Ingresar el triángulo inferior:\n");
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < i; j++) {
			printf("Ingrese el valor en la fila %d, columna %d: ", i + 1, j + 1);
			scanf("%d", &matriz[i][j]);
		}
	}
	
	printf("Contenido de la matriz:\n");
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

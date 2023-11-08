#include <stdio.h>

void ordenarMatriz(int matriz[3][3]) {
	int n = 3; 
	
	for (int k = 0; k < n * n - 1; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int fila1 = i;
				int columna1 = j;
				int fila2 = k / n;
				int columna2 = k % n;
				
				if (matriz[fila1][columna1] > matriz[fila2][columna2]) {
					
					int temp = matriz[fila1][columna1];
					matriz[fila1][columna1] = matriz[fila2][columna2];
					matriz[fila2][columna2] = temp;
				}
			}
		}
	}
}

int main() {
	int matriz[3][3]; 
	
	printf("Ingresar valores en la matriz:\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("Ingrese el valor en la fila %d, columna %d: ", i + 1, j + 1);
			scanf("%d", &matriz[i][j]);
		}
	}
	
	ordenarMatriz(matriz);
	
	printf("Contenido de la matriz ordenada:\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

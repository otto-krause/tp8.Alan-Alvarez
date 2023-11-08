#include <stdio.h>

#define MAX_PERSONAS 10

struct Persona {
	int numeroSocio;
	int edad;
};

int main() {
	struct Persona personas[MAX_PERSONAS];
	int cantidadPersonas = 0;
	
	printf("Ingrese el n�mero de socio y la edad de las personas (0 para terminar):\n");
	
	for (int i = 0; i < MAX_PERSONAS; i++) {
		int numeroSocio, edad;
		printf("N�mero de socio: ");
		scanf("%d", &numeroSocio);
		
		if (numeroSocio == 0) {
			break;
		}
		
		printf("Edad: ");
		scanf("%d", &edad);
		
		personas[cantidadPersonas].numeroSocio = numeroSocio;
		personas[cantidadPersonas].edad = edad;
		cantidadPersonas++;
		
		if (cantidadPersonas == MAX_PERSONAS) {
			printf("Se ha alcanzado el l�mite de personas (%d). Finalizando la carga.\n", MAX_PERSONAS);
			break;
		}
	}
	
	
	for (int i = 0; i < cantidadPersonas - 1; i++) {
		for (int j = i + 1; j < cantidadPersonas; j++) {
			if (personas[i].edad > personas[j].edad) {
				
				struct Persona temp = personas[i];
				personas[i] = personas[j];
				personas[j] = temp;
			}
		}
	}
	
	printf("\nLista ordenada por edades:\n");
	for (int i = 0; i < cantidadPersonas; i++) {
		printf("N�mero de socio: %d, Edad: %d\n", personas[i].numeroSocio, personas[i].edad);
	}
	
	return 0;
}

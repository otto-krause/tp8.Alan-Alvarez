#include <stdio.h>

#define NUM_CLIENTES 100

int main() {
	int numeroCliente;
	int codigoTransaccion;
	double monto;
	double saldos[NUM_CLIENTES] = {0}; 
	
	printf("Ingrese las transacciones (número de cliente, código de transacción, monto):\n");
	printf("Códigos de transacción:\n");
	printf("1. Depósito\n");
	printf("2. Extracción\n");
	printf("3. Comisiones deducidas\n");
	printf("4. Intereses acreditados\n");
	printf("0. Finalizar\n");
	
	while (1) {
		printf("Número de cliente: ");
		scanf("%d", &numeroCliente);
		
		if (numeroCliente == 0) {
			break; 
		}
		
		printf("Código de transacción: ");
		scanf("%d", &codigoTransaccion);
		printf("Monto: ");
		scanf("%lf", &monto);
		
		
		switch (codigoTransaccion) {
		case 1:
			saldos[numeroCliente - 1] += monto;
			break;
		case 2: 
			saldos[numeroCliente - 1] -= monto;
			break;
		case 3: 
			saldos[numeroCliente - 1] -= monto;
			break;
		case 4: 
			saldos[numeroCliente - 1] += monto;
			break;
		default:
			printf("Código de transacción inválido. Ignorando transacción.\n");
			break;
		}
	}
	
	
	int clientesConMayorDeposito[NUM_CLIENTES];
	double mayorDeposito = 0;
	int cantidadClientesConMayorDeposito = 0;
	
	for (int i = 0; i < NUM_CLIENTES; i++) {
		if (saldos[i] > mayorDeposito) {
			mayorDeposito = saldos[i];
			cantidadClientesConMayorDeposito = 1;
			clientesConMayorDeposito[0] = i + 1;
		} else if (saldos[i] == mayorDeposito) {
	
			cantidadClientesConMayorDeposito++;
			clientesConMayorDeposito[cantidadClientesConMayorDeposito - 1] = i + 1;
		}
	}
	
	printf("\nN° De Cliente Total Depósitos Total Extracciones Total Comisiones Total Intereses Saldo\n");
	for (int i = 0; i < NUM_CLIENTES; i++) {
		printf("%d %.2lf %.2lf %.2lf %.2lf %.2lf\n", i + 1, saldos[i], 0.0, 0.0, 0.0, saldos[i]);
	}
	
	printf("\nClientes con mayor depósito:\n");
	for (int i = 0; i < cantidadClientesConMayorDeposito; i++) {
		printf("Cliente %d: %.2lf\n", clientesConMayorDeposito[i], mayorDeposito);
	}
	
	return 0;
}

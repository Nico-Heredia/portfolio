

#include <stdio.h>

int main(int argc, char **argv)
{
	float num1, num2, resultado;
	int opcion;
	printf("Ingrese la opcion deseada\n");
	printf("1 - Suma \n");
	printf("2 - Resta \n");	
	printf("3 - Multiplicacion \n");
	printf("4 - Division \n");
	scanf("%d", &opcion);
	if(opcion < 1 || opcion > 4){
		printf("La opcion ingresada es incorrecta\n");
		}else{
			printf("Por favor ingresa un numero\n");
			scanf("%f", & num1);
			printf("Por favor ingresa otro numero\n");
			scanf("%f", & num2);
	
			switch (opcion){
				case 1 :
					resultado = num1 + num2;
					printf("El resultado de la suma es %.2f \n", resultado);
					break;
					
				case 2 :
					resultado = num1 - num2;
					printf("El resultado de la resta es %.2f \n", resultado);
					break;
						
				case 3 :
					resultado = num1 * num2;
					printf("El resultado de la multiplicacion es %.2f \n", resultado);
					break;
				
				case 4 :
					if (num2 != 0){
						resultado = num1 / num2;
						printf("El resultado de la division es %.2f \n", resultado);
						}else{
							printf("El segundo tiene que ser distinto de cero \n");
						}
					break;		
				
					
			}
	}
	

	
	return 0;
}


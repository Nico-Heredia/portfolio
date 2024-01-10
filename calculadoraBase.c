/*
 * calculadora.c
 * 
 * Copyright 2023 Nicolas <Nicolas@DESKTOP-PF33MJA>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


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




#include <stdio.h>

int main() {
	int uzona = 3, usuc = 3, uven = 2;
	int tot_ven[uzona][usuc][uven], zona, sucursal, vendedor , tot_gen = 0;
	int tot_suc[usuc];
	int tot_zon[uzona];
	
	
	printf("Ingrese el numero de zonas en las cuales desea calcular las ventas: ");
	scanf("%d", &uzona);
	printf("\nIngrese el numero de sucursales en dichas zonas: ");
	scanf("%d", &usuc);
	printf("\nIngrese el numero de vendedores por sucursal: ");
	scanf("%d", &uven);
	
	//ingreso total de ventas:
	for (zona = 0; zona < uzona; zona++) {
		for (sucursal = 0; sucursal < usuc; sucursal++) {
			for (vendedor = 0; vendedor < uven; vendedor++) {
				tot_ven[zona][sucursal][vendedor] = 0.0;
				printf ("\nIngrese el total de ventas en la zona %d, sucursal %d, por el vendedor %d: ", zona + 1, sucursal + 1, vendedor + 1);
				scanf ("%d", &tot_ven[zona][sucursal][vendedor]);
			}
		}
	}
	
	//mostrar total de ventas:
	for (zona = 0; zona < uzona; zona++) {
		tot_zon[zona] = 0.0;
		for (sucursal = 0; sucursal < usuc; sucursal++) {
			tot_suc[sucursal] = 0.0;
			for (vendedor = 0; vendedor < uven; vendedor++) {
				printf("\nEl total de ventas en la zona %d, sucursal %d, por el vendedor %d es de: $%d \n", zona +1, sucursal + 1, vendedor + 1, tot_ven[zona][sucursal][vendedor]);
				tot_gen += tot_ven[zona][sucursal][vendedor];
				tot_suc[sucursal] += tot_ven[zona][sucursal][vendedor];
				tot_zon[zona] += tot_ven[zona][sucursal][vendedor];
			}	
			printf ("El total general de ventas de la sucursal %d es %d\n", sucursal + 1, tot_suc[sucursal]);
		}
		printf ("EL TOTAL GENERAL DE VENTAS EN LA ZONA %d ES: %d\n", zona + 1, tot_zon[zona]);
	}
	printf ("EL TOTAL GENERAL DE VENTAS EN LAS ZONAS ES DE: %d", tot_gen);

	return 0;
}

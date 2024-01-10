
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




	




#define MTITULO 20
#define MCARACTERES 100
#define MTAREAS 100


typedef struct {
		char titulo[MTITULO];
		char descripcion[MCARACTERES];
	}Tarea;
	
	
	
	
	
//prototipos	
	
	
	
	
char* ingresochar();
	
int menu(char *titulo,char *opciones[]);	
	
Tarea crearTarea(int *numTareas);

void guardarTareas(const Tarea *tareas, int numTareas);

int cargarTareas(Tarea *tareas);

void verTareas(const Tarea *tareas, int numTareas);

void eliminarTarea(Tarea *tareas, int *numTareas);

void buscarTarea(const Tarea *tareas, int numTareas);

int buscar (const void *ppelemento, const void *pselemento);

int ordenar (const void *ppelemento, const void *pselemento);



	


int main(int argc, char **argv){
	Tarea tareas[MTAREAS];
	int numTareas = 0;
	
	numTareas = cargarTareas(tareas);
	

	while (1){
	
		char *opciones[] = {"Crear Tarea","Ver Tareas", "Eliminar Tarea","Buscar una tarea", NULL};
		printf("\n\n\n");
		int opcion = menu ("\t\t------BIENVENIDO A TO-DO LIST!------\n\n\n",opciones);
		
		
		
		switch (opcion){
			
			case 1:
			//Crear Tarea
				printf("\n\nSelecciono la opcion %d -CREAR TAREA-\n\n", opcion);
				
				tareas[numTareas] = crearTarea(&numTareas);
				guardarTareas(tareas, numTareas);
				
								
				break;
			case 2:
			//Ver Tareas
				printf("\n\nSelecciono la opcion %d -VER TAREAS-\n\n", opcion);
				
				
				verTareas(tareas, numTareas);		
			
				
					
				break;
			case 3:
			//Eliminar Tarea
				printf("\n\nSelecciono la opcion %d -ELIMINAR TAREA-\n\n", opcion);
				
				eliminarTarea(tareas, &numTareas);
				
				
				
				break;
			case 4:
			//Buscar Tarea
				printf("\n\nSelecciono la opcion %d -BUSCAR TAREA-\n\n", opcion);
				
				buscarTarea(tareas, numTareas);
				
								
				
				break;
				
			case 5:
				printf("\n\nSelecciono la opcion %d -SALIR-\n\n", opcion);
				
			
			
				exit(0);
				break;
			default:
				printf("\n\nOpcion no valida\n\n");
				
		}			
				
				
	}
	
	return 0;
}


//implementacion de funciones



char* ingresochar(){
	char *buffer = malloc(sizeof(char) *21);
	int i = 0;
	char c;
	while ((c = getchar()) != '\n' && i < 20){
		buffer [i] = c;
		i++;
		
	}
	buffer[i] = '\0';
	return strdup(buffer);
}


int menu(char *titulo,char *opciones[]){
	int opcion,ndesde=1 ,nhasta, n;

do{
		printf("\t %s\n", titulo);
		printf("\n");
		n=1;
		while(opciones[n-1] !=NULL){
			printf("\t%3d. %s\n",n,opciones[n-1]);
			n++;
		
		}
		printf("\t%3d. Salir \n",n);
		nhasta = n;
		printf("\n\n");
		printf("Ingrese una opcion: ");
		opcion = atoi(ingresochar());
		if(opcion < ndesde || opcion > nhasta){
			printf("%d es una opcion incorrecta! \n", opcion);
		} else{
			return opcion;
			
		}
	} while (opcion != nhasta );
	return opcion;
}
	

//crear una tarea

Tarea crearTarea(int *numTareas){
	Tarea nuevaTarea;
	
	
	printf("\nPor favor ingrese el titulo de la tarea (max %d caracteres): ", MTITULO -1);
	//fgets(nuevaTarea.titulo, MTITULO, stdin);
		
	char *buffer = malloc(sizeof(char) *MTITULO);
	int i = 0;
	char c;
	while ((c = getchar()) != '\n' && i < MTITULO){
		buffer [i] = c;
		i++;
		
	}
	buffer[i] = '\0';
	strcpy(nuevaTarea.titulo,buffer);
	
	
	printf("\nPor favor ingrese la descripcion de la tarea (max %d caracteres): ", MCARACTERES -1);
	//fgets(nuevaTarea.descripcion, MCARACTERES, stdin);
	
	char *buffer2 = malloc(sizeof(char) *MCARACTERES);
	int i2 = 0;
	char c2;
	while ((c2 = getchar()) != '\n' && i2 < MCARACTERES){
		buffer2 [i2] = c2;
		i2++;
		
	}
	buffer2[i2] = '\0';
	strcpy(nuevaTarea.descripcion,buffer2);
	
	
	(*numTareas)++;
	
	return nuevaTarea;
};

//guardar una tarea

void guardarTareas(const Tarea *tareas, int numTareas){
	FILE *archivo = fopen("tareas.dat", "wb");
	
	if (archivo == NULL){
		printf("\nError al abrir el archivo de tareas.\n");
		return;	
	}
	
	qsort((void*)tareas, numTareas, sizeof(Tarea), ordenar);
	
	fwrite(tareas, sizeof(Tarea), numTareas, archivo);
	
	
	fclose(archivo);
}

//cargar tareas desde un archivo


int cargarTareas(Tarea *tareas){
	FILE *archivo = fopen("tareas.dat", "rb");
	
	if(archivo == NULL){
		printf("\nNo se encontro el archivo de tareas, se creara uno. \n");
		return 0;
	}
	
	int numTareas = fread(tareas, sizeof(Tarea),MTAREAS, archivo);
	
	fclose(archivo);
	return numTareas;
}


void verTareas(const Tarea *tareas, int  numTareas){
	if (numTareas == 0){
		printf("\n\n No hay tareas para mostrar.\n\n");
	} else {
				
		printf ("\nLista de tareas: \n");
	
		for (int i = 0; i < numTareas; i++){
			printf("Tarea %d: \n", i+1);
			printf("\t Titulo: %s \n", tareas[i].titulo);
			printf("\t Descripcion: %s \n", tareas[i].descripcion);
			printf("\n");
			
		}
				
			
		}
		
	}

void eliminarTarea(Tarea *tareas, int *numTareas){
		
		
		//verifico antes si hay tareas que puedan ser eliminadas
		if(*numTareas == 0){
			printf("\nNo hay tareas para eliminar.\n");
			return;	
		}
		
		//Muestro las tareas existentes
		verTareas(tareas, *numTareas);
		
		
		//Pido que la seleccion de tarea sea por numero
		printf("\nIngrese el numero de la tarea que desea eliminar: ");
		int numTareaEliminar;
		scanf("%d", &numTareaEliminar);
		
		//consumo el enter!!
		getchar();
		
		//chequeo si es un numero de tarea valido
		if(numTareaEliminar < 1 || numTareaEliminar > *numTareas){
			printf("\nNumero de tarea invalido. \n");
			return;
		
		}
		
		for (int i = numTareaEliminar - 1; i < *numTareas - 1; i++){
			tareas[i] = tareas [i + 1];
		}
		
		
		//resto la tarea eliminada al total
		(*numTareas)--;
		
		//limpio la ultima posicion para que no quede duplicada
		memset(&tareas[*numTareas], 0, sizeof(Tarea));
		
		guardarTareas(tareas, *numTareas);
		
		printf("\nTarea eliminada con exito. \n");
		
		
}


//Buscar tarea

void buscarTarea(const Tarea *tareas, int numTareas){
	
	
	
	if(numTareas == 0){
		printf("\n\nNo hay tareas para buscar.\n\n");
	} else{	
		Tarea tareaBuscar; 
		
	 
		printf("\n Por favor ingrese el Titulo de la tarea que desea buscar\n");
		//fgets para leer la linea completa y saco el enter
		//fgets(tareaBuscar.titulo, MTITULO, stdin);
		//tareaBuscar.titulo[strcspn(tareaBuscar.titulo, "\n")] = '\0';
		
			
		char *buffer = malloc(sizeof(char) *MTITULO);
		int i = 0;
		char c;
		while ((c = getchar()) != '\n' && i < MTITULO){
			buffer [i] = c;
			i++;	
		
		}
		
		buffer[i] = '\0';
		
		
		strcpy(tareaBuscar.titulo,buffer);
		
		
		
		//utilizo bsearch
		Tarea *resultado = (Tarea *) bsearch(&tareaBuscar,tareas,numTareas, sizeof(Tarea),buscar);
		//clave, base a buscar, cantidad de miembros, tamanio de c miembro,funcion de comp o busq
		
		if (resultado == NULL){
			printf("\n La tarea %s no se encuentra entre las tareas guardadas\n ", tareaBuscar.titulo);
		} else {
			printf("\n %s se encuentra en las tareas guardadas\n", tareaBuscar.titulo);	
			printf("\n \n");
			// muestro la tarea?
			
			printf("\t Titulo: %s \n", resultado ->titulo);
			printf("\t Descripcion: %s \n", resultado ->descripcion);
			printf("\n \n");
		
		free(resultado);
		//free (tareasOrdenadas); 	
		}	
			
	}

}


//funcion de busqueda para bsearch

int buscar (const void *ppelemento, const void *pselemento){
	//los elementos de la estructura son vectores
	const Tarea *pcpelemento = (const Tarea *) ppelemento;
	const Tarea *pcselemento = (const Tarea *) pselemento;
	
	// -> acccede a elemento a traves de puntero
	return strcmp (pcpelemento ->titulo, pcselemento ->titulo);
}



//Ordenar las tareas 

//funcion de ordenamientp para qsort

int ordenar (const void *ppelemento, const void *pselemento){
	//los elementos de la estructura son vectores
	const Tarea *pcpelemento = (const Tarea *) ppelemento;
	const Tarea *pcselemento = (const Tarea *) pselemento;
	
	// -> acccede a elemento a traves de puntero
	return strcmp (pcpelemento ->titulo, pcselemento ->titulo);
}


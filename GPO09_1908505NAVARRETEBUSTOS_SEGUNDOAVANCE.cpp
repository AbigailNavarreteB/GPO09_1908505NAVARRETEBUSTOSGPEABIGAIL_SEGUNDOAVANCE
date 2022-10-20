#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <stdio.h>

using namespace std;

struct empresa
{
	int idcompra, numvid, lanzam;
	string proveedor, nomvid, clasifvid, caract, descrip, genero;
	char tipconsol;
	float subtotal, iva, total;
};

int main()
{
	empresa videojuegos[3];
	int opcion, busqueda;

	do
	{
		printf("\t ***GAMEPLANET***\n");
		printf("1.- Captura de Videojuego\n 2.-Mostrar dato de Videojuego\n  3.- Eliminar Videojuego\n 4.- Total de Videojuegos Vigentes(busqueda)\n 5.- Limpiar Pantalla\n 6.- Salir\n");
		scanf_s("%d", &opcion);

		switch (opcion)
		{
		case 1: //Captura de Videojuego
			for (int i = 1; i < 4; i++)
			{
				videojuegos[i].idcompra = 1000 + (i + 1);
				int n = 1;
				printf("\nID compra: %d\n", videojuegos[i].idcompra);
				printf("\nIngrese el numero del Videojuego\n");
				scanf_s("%d" , &videojuegos[i].numvid);
				printf("\nIngrese el nombre del Videojuego\n");
				cin.ignore();
				getline(cin,videojuegos[i].nomvid);
				printf("\nIngrese fecha de lanzamiento\n");
				scanf_s("%d", &videojuegos[i].lanzam);
				printf("\nIngrese clasificacion\n");
				cin.ignore();
				getline(cin, videojuegos[i].clasifvid);
				printf("\nIngrese breves caracteristicas\n");
				cin.ignore();
				getline(cin, videojuegos[i].caract);
				printf("\nIngrese breve descripcion\n");
				cin.ignore();
				getline(cin, videojuegos[i].descrip);
				printf("\nIngrese genero del Videojuego\n");
				cin.ignore();
				getline(cin, videojuegos[i].genero);
				printf("\nIngrese tipo de consola del Videojuego\n");
				scanf_s("%c", videojuegos[i].tipconsol);
				printf("\nIngrese subtotal\n");
				scanf_s("%f", &videojuegos[i].subtotal);
				videojuegos[i].iva = videojuegos[i].subtotal * 0.16;
				videojuegos[i].total = videojuegos[i].subtotal + videojuegos[i].iva;
				
				for (int k = 0; k <= n; k++)
				{
					if (videojuegos[i].numvid == videojuegos[i - n].numvid || videojuegos[i].numvid == videojuegos[i - (n - 1)].numvid)
					{
						printf("El Numero de Videojuego ya existe\n");
						printf("Ingrese el numero de Videojuego\n");
						scanf_s("%d", &videojuegos[i].numvid);
						if (n <= 4)
						{
							n = n + 1;
						}
						else
						{
							n = 0;
						}

					}
				}

			}
			break;
		case 2: //Modificar dato de Videojuego, aun no se puede realizar 
			printf("Ingrese el numero de Videojuego a modificar");
			scanf_s("%d", &busqueda);

			for (int i = 0; i < 3; i++)
			{
				if (busqueda == videojuegos[i].numvid)
				{
					videojuegos[i].numvid = 0;
					printf("Modificando...\n");
				}
				
			}
			break;

		case 3: //Eliminar dato
			printf("Ingrese el numero de Videojuego");
			scanf_s("%d", &busqueda);

			for (int i = 0; i < 3; i++)
			{
				if (busqueda == videojuegos[i].numvid)
				{
					videojuegos[i].numvid = 0;
					printf("Eliminando...\n");
				}
			}
			break;

		case 4: //Total(busqueda)
			do
			{
				printf("Ingrese el numero de Videojuego");
				scanf_s("%d", &busqueda);
				for (int i = 0; i < 3; i++)
				{
					if (videojuegos[i].idcompra != 0)
					{
						if (busqueda == videojuegos[i].numvid != 0)
						{
							printf("ID compra : %d\n", videojuegos[i].idcompra);
							printf("Numero de Videojuego : %d\n", videojuegos[i].numvid);
							printf("Nombre del Videojuego : %s\n", videojuegos[i].nomvid);
							printf("Fecha de Lanzamiento : %s\n", videojuegos[i].lanzam);
							printf("Clasificacion del Videojuego : %s\n", videojuegos[i].clasifvid);
							printf("Caracteristicas del Videojuego : %s\n", videojuegos[i].caract);
							printf("Descripcion del Videojuego : %s\n", videojuegos[i].descrip);
							printf("Genero de Videojuego : %s\n", videojuegos[i].genero);
							printf("Tipo de consola :%c\n", videojuegos[i].tipconsol);
							printf("Subtotal : %f\n", videojuegos[i].subtotal);
							printf("Iva: %f\n", videojuegos[i].iva);
							printf("Total : %f\n", videojuegos[i].total);
						}
					}
	
						
			
				}
				break;
			} 
			break; 

		case 5:
			system("cls");
			break;

		case 6:
			printf("Saliendo...\n");
			break;
			
		default:
			printf("Intente nuevamente...\n");
			break;

		}
	} while (opcion != 5);
	system("pause");
}

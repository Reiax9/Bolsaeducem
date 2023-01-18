#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>
#include "rlutil.h"

int main(){
	srand(time(NULL));
	const int DIAS=60; //? Modificamos la cantidad de dias que queremos observar
	int min,max,maxdia,mindia,inicial,inicial2,inicial3,minInicial,maxInicial; 
	int i,azar,cotizacioinicial,roto;
	int x,y,X=83,Y=50; //cordenadas
	float sumainicial=0;

	roto=maxdia=mindia=maxInicial=minInicial=inicial2=inicial3=0;

	//! Inicio y preguntas usuarios
	printf("Benvinguts a la borsa EDUCEM-ASIX S.A.\nPrograma realitzat per Xavier Garcia\n\n");
	//* Ubicación de las preguntas
	x=1;
	y=5;
	gotoxy(x,y);

	do{
		printf("Introdueix la cotitzacio minima (0..5) ");
		scanf("%d",&min);
	}while (min<0 || min>5);

	do{
		printf("Introdueix la cotitzacio maxima (35..40) ");
		scanf("%d",&max);
	}while (max<35 || max>40);

	do{
		printf("Introdueix la cotitzacio inicial (%d..%d) ",min,max);
		scanf("%d",&inicial);
	}while (min>inicial || inicial>max);
	cotizacioinicial = inicial;
	
	//? ESQUEMA
	//* Ubicacion del esquema
	i=40;
	y=10;
	x=80;
	
	//!EJE Y
	for(int j = 40; j >= 0; j--){
		gotoxy(x,y);
		printf("%2d|",i);
		if(i==max || i==min){ //! Añadimos las barras de nivel
			for (int i = 0; i < DIAS; i++)
			{
				printf("-");
			}
		}
		y++;
		i--;
	}
	//!EJE X
	x+=2;
	i=0;
	for (int z = 0; z <= 70; z++)
	{
		gotoxy(x,y);
		if (i%5==0 && i <= DIAS)
		{
			gotoxy(x,y);
			if(i>1){printf("|\n");}
			y++;
			gotoxy(x,y);
			printf("%d",i);
			y--;
		}else if (z==70)
		{
			printf(">");
			gotoxy(x-1,y+1);
			printf("dia");
		}else
		{
			printf("-");
		}
		i++;
		x++;		
	}
	//* Ubicación de los dias
	x=1;
	y=10;
	//! Actualización de las cotizaciones
	for (int i = 1; i <= DIAS; i++)
	{
		gotoxy(x,y);	
		printf("Dia %2d:   %2d   %2d   %2d ",i,inicial,inicial2,inicial3);
		inicial3=inicial2;
		inicial2=inicial;
		//* Información del grafico
		
		if (inicial >= 40)
		{
			gotoxy(X,10);
			setColor(GREEN);
			printf("^");
		}else if(inicial <= 0)
		{
			gotoxy(X,50);
			setColor(YELLOW);
			printf("!");
		}else{
			gotoxy(X,Y -(inicial));
			printf("*");
		}
		X++;

		//! Aleatorio
		azar = 1 + rand()%(4-1+1);
        switch (azar)
        {
        case 1: inicial+=3; break;
        case 2: inicial+=2; break;
        case 3: inicial-=3; break;
        case 4: inicial-=2; break;
		}
		//! FALLIDA!
		if (inicial<min)
		{	
			if (roto<5)
			{
				roto+=1;
			}else{
				gotoxy(x,y+2);
				setColor(RED);
				printf("EDUCEM-ASIX HA FET FALLIDA");
				break;
			}	
		}else{
			roto = 0;
		}
		//* Saber el valor maximo y minimo
		if (i==1 || inicial<minInicial)
		{
			minInicial = inicial;
		}else if(i==1 || inicial>maxInicial)
		{
			maxInicial = inicial;
		}
		//* Saber el dia
		if (maxInicial==inicial)
		{
			maxdia = i;
		}else if (minInicial==inicial)
		{
			mindia = i;
		}
		//* Gotoxy
		if (i<=29 || i>=31)
		{
			y+=1;
		}else{
			y=10;
			x=30;
		}
		//* Colores 
		if (inicial<min)
		{
			setColor(RED);
		}else if (inicial>max){
			setColor(BLUE);
		}else{
			setColor(WHITE);
		}
		//? Suma para el promedio
		sumainicial+=inicial;		
	}
	gotoxy(1,40);
	setColor(WHITE);
	printf("\n\n");
	printf("Cotitzacio minima: %d\tCotizacio maxima: %d\tCotizacio inicial: %d\n",min,max,cotizacioinicial);
	printf("El valor promig de la cotizacio ha sigut de: %.2f\n",sumainicial/DIAS);
	printf("El valor maxim donat es de %d en el dia: %d\n",maxInicial,maxdia+1);
	printf("El valor minim donat es de %d en el dia: %d\n",minInicial,mindia+1); 
	
	getch();
	return 0;
}

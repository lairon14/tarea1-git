/*
  Tarea 1
  Programa: scrable.c
  Realizado por: Lairon Acosta
  Version: 1.0
------------------------------
  Includes del sistema
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  Funcion: encuentra letras consecutivas
	y las elimina del arreglo letras[]
  Entrada: arreglo de char.
  Entrada/Salida: arreglo de char.
*/
void duplicada(char *word,char *letras);

/*
  Programa principal: recibe como entrada
	un archivo de texto, y lo lee para
	realizar la tarea en cuestion.
*/
void main (int argc, char *argv[]) {
	int j, e;
	char word[40]="";
	char letras[] = {'A','B','C','D','E','F','G','H','I','J','K','L',
		'M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	FILE *ficheroEntrada;
    
	ficheroEntrada = fopen( argv[1] , "r" );
    
	if  (!ficheroEntrada) {
		//IMPRIME ERROR
		printf("mensaje: **ERROR ABRIENDO ARCHIVO DE ENTRADA\n");

	} else {
		//Extrae cada palabra del archivo
		while (fscanf(ficheroEntrada,"%20s", word) != EOF) { 
			duplicada(word, letras);
			strcpy(word,"");
		}

		fclose(ficheroEntrada);	//CIERRA EL archivo de entrada  

		//imprimo las letras no repetidas
		printf("Letras no repetidas: \n");
		for(j=0;j<26;j++){
			if( letras[j] != ' ' ) {
				printf("\tLetra: %c\n", letras[j]);
			}	
		}
	}
}       

void duplicada(char *word, char *letras) {
	int i,j;
	int lon = strlen(word) - 1;
	//analiza cada palabra del archivo
	for(i=0 ; i < lon; i++) {
		//verifica si dos letras iguales
		//son consecutivas
		if( word[i] == word[i+1] ) {
			j = word[i];
			letras[j-65] = ' ';
		}
	}
}          

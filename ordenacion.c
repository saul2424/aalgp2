/**
 *
 * Descripcion: Implementacion de funciones de ordenacion
 *
 * Fichero: ordenacion.c
 * Autor: Carlos Aguirre
 * Version: 1.0
 * Fecha: 16-09-2017
 *
 */


#include "ordenacion.h"
#include <stdio.h>
#include <stdlib.h>
/***************************************************/
/* Funcion: SelectSort    Fecha:    30/09/2018     */
/* Vuestro comentario                              */
/***************************************************/

int minimo(int *tabla, int ip, int iu,int *cont);
int maximo(int *tabla, int ip, int iu,int *cont);


int SelectSort(int* tabla, int ip, int iu){
    int i,aux,min,cont;
    if (!tabla){
        return ERR;
    }
    cont = 0;
    for (i=ip ; i<iu ; i++){
        min = minimo(tabla,i,iu,&cont);
        aux = tabla[i];
        tabla[i] = tabla[min];
        tabla[min] = aux;
    }
    
    return cont;

}

int SelectSortInv(int* tabla, int ip, int iu){
  int i,aux,max,cont;
  if (!tabla){
      return ERR;
  }
  cont = 0 ;
  for (i=ip ; i<iu ; i++){
      max = maximo(tabla,i,iu,&cont);
      aux = tabla[i];
      tabla[i] = tabla[max];
      tabla[max] = aux;

  }
  return cont;

}

int minimo(int *tabla, int ip, int iu,int *cont){
    int min ,j;
    min = ip;
    for (j =ip+1 ; j<=iu;j++ ){
        if (tabla[j]<tabla[min]){
            min = j;
            *cont = *cont + 1;
        }
    }
    return min;
}

int maximo(int *tabla, int ip, int iu,int *cont){
    int max ,j;
    max = ip;
    for (j =ip+1 ; j<=iu; j++ ){
        if (tabla[j]>tabla[max]){
            max = j;
            *cont = *cont +1;
        }
    }
    return max;
}

/***************************************************/
/* Funcion: MergeSort    Fecha:    30/09/2018     */
/* Vuestro comentario                              */
/***************************************************/
int copiar(int *torgien,int*tdestino,int ip,int iu);
int merge(int *tabla, int ip, int iu, int imedio);
int MergeSort(int* tabla, int ip, int iu){
    int medio;
    if (!tabla ||ip>iu){
        return ERR;
    }
    else if (ip == iu){
        return OK;
    }
    
    medio = (ip+iu)/2;
    MergeSort(tabla,ip,medio);
    MergeSort(tabla,medio+1,iu);
    return merge(tabla,ip,iu,medio);
    
    
}

int merge(int *tabla, int ip, int iu, int imedio){
    int i,j,k,cont;
    int *taux;
    if(!tabla|| ip>iu){
        return ERR;
    }
    taux = malloc(sizeof(int)*ip);
    if (!taux){
        return ERR;
    }
    /*falta copiar la tabla*/
    /*inicializamos las variables*/
    i=ip;
    j=imedio+1;
    k=ip;
    cont =0;
    while(i>=imedio &&j<=iu){
        if(tabla[i]<tabla[j]){
            taux[k] = taux[i];
            i++;
        }
        else {
            taux[k] = tabla[j];
            j++;
        }
    }
    if (i>imedio){
        while(j<iu){
            taux[k] = tabla[j];
            j++;
            k++;
        }
    }
    
    else if(j>iu){
        while(i<=imedio){
            taux[k] = tabla[i];
            i++;
            k++;
        }
    }
    copiar(taux,tabla,ip,iu);
    
    free(taux);
    return cont;
}


int copiar(int *torigen,int*tdestino,int ip,int iu){
    if(!torigen || !tdestino){
        return-1;
    }
    
    
    return 1;
}

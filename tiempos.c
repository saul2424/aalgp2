/**
 *
 * Descripcion: Implementacion de funciones de tiempo
 *
 * Fichero: tiempos.c
 * Autor: Carlos Aguirre Maeso
 * Version: 1.0
 * Fecha: 16-09-2017
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempos.h"
#include "ordenacion.h"
#include "permutaciones.h"
#include <time.h>
#include <sys/time.h>

/***************************************************/
/* Funcion: tiempo_medio_ordenacion Fecha:         */
/*                                                 */
/* Vuestra documentacion (formato igual            */
/* que en el primer apartado):                     */
/***************************************************/

short tiempo_medio_ordenacion(pfunc_ordena metodo, int n_perms, int N, PTIEMPO ptiempo){
  int i, min, max, aux;
  double secs = 0, med = 0;
  struct timeval t_ini, t_fin;  /*las utilizamos para poder utilizar clock gettime*/
  int  **perm;

  if (!metodo || !ptiempo || n_perms<=0 || N<=0){
    return ERR;
  }

  perm = genera_permutaciones(n_perms, N);
  if(!perm){
    return ERR;
  }

  min = -1;
  max = -1;
  for (i = 0 ; i<n_perms ; i++){
    gettimeofday(&t_ini, NULL);
    aux = metodo(perm[i],0,N-1);
    gettimeofday(&t_fin, NULL);
    secs += (double)(t_fin.tv_sec + (double)t_fin.tv_usec/1000000) -
    (double)(t_ini.tv_sec + (double)t_ini.tv_usec/1000000);
    med =  aux + med;

  /*actualizamos el maximo y el minimo de los tiempos del metodo*/
  	if(aux < min || min ==-1){
      min = aux;
    }
  	if(aux > max || max == -1){
      max = aux;
    }

}
/*actualizamos los datos de la structura*/
  ptiempo->N = N;
  ptiempo->n_elems = n_perms;
  ptiempo->tiempo = (secs/n_perms);
  ptiempo->medio_ob = (med/n_perms);
  ptiempo->min_ob = min;
  ptiempo->max_ob = max;

/*liberamos la memoria reservada anteriormente*/
for (i = 0 ; i<n_perms; i++){
  free(perm[i]);
}
free(perm);

return OK;
}

/***************************************************/
/* Funcion: genera_tiempos_ordenacion Fecha:       */
/*                                                 */
/* Vuestra documentacion                           */
/***************************************************/
short genera_tiempos_ordenacion(pfunc_ordena metodo, char* fichero, int num_min, int num_max, int incr, int n_perms){
  int i;
  PTIEMPO tiempo;
  PTIEMPO aux;
  if(!metodo || !fichero || num_min <=0 || num_max <= num_min || incr <= 0 || n_perms <= 0 ){
    return ERR;
  }
   tiempo= (PTIEMPO)malloc(sizeof(TIEMPO)*(((num_max - num_min)/incr) + 1));
  if(!tiempo){
      return ERR;
  }

    aux = tiempo;
      for(i = num_min ; i <= num_max ; i += incr){
  	     if(tiempo_medio_ordenacion( metodo,n_perms, i, aux) == ERR){
           return ERR;
         }
  	      aux++;
        }

      if(guarda_tabla_tiempos(fichero, tiempo, (((num_max - num_min)/incr) + 1)) == ERR){
        return ERR;
      }
      free(tiempo);
      return OK;
  }


/***************************************************/
/* Funcion: guarda_tabla_tiempos Fecha:            */
/*                                                 */
/* Vuestra documentacion (formato igual            */
/* que en el primer apartado):                     */
/***************************************************/
short guarda_tabla_tiempos(char* fichero, PTIEMPO tiempo, int n_tiempos){
  FILE *f = NULL;
    int i;

    f = fopen(fichero,"w");
    if (!f){
      return ERR;
    }
    fprintf(f,"tamaño de los elementos ,numero de elementos a promediar,tiempo medio ,tiempo max, tiempo min\n");
    for(i = 0; i <n_tiempos ; i++){
      /*fprintf (f,"%.20lf\n",tiempo->tiempo);para hacer el grafico*/
        fprintf(f," %d %d %.20f %lf %d %d \n",tiempo->N, tiempo->n_elems,tiempo->tiempo,
          tiempo->medio_ob, tiempo->max_ob, tiempo->min_ob);
	 tiempo++;
    }

    fclose(f);

    return OK;
}

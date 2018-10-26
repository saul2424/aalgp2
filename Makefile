#-----------------------
# IMPORTANTE: Los valores de los parametros de los ejercicio?_test deben ajustarse.
# Se asume que los ficheros fuente se llaman ejercicio1.c, ejercicio2.c,...,ordenar.h
#-----------------------

CC = gcc -ansi -pedantic
CFLAGS = -Wall
EXE = ejercicio1 ejercicio1h ejercicio2 ejercicio3 ejercicio4 ejercicio5

all : $(EXE)

.PHONY : clean
clean :
	rm -f *.o core $(EXE)

$(EXE) : % : %.o ordenacion.o tiempos.o permutaciones.o
	@echo "#---------------------------"
	@echo "# Generando $@ "
	@echo "# Depende de $^"
	@echo "# Ha cambiado $<"
	$(CC) $(CFLAGS) -o $@ $@.o ordenacion.o tiempos.o permutaciones.o

permutaciones.o : permutaciones.c permutaciones.h
	@echo "#---------------------------"
	@echo "# Generando $@"
	@echo "# Depende de $^"
	@echo "# Ha cambiado $<"
	$(CC) $(CFLAGS) -c $<

 ordenacion.o : ordenacion.c ordenacion.h
	@echo "#---------------------------"
	@echo "# Generando $@"
	@echo "# Depende de $^"
	@echo "# Ha cambiado $<"
	$(CC) $(CFLAGS) -c $<

 tiempos.o : tiempos.c tiempos.h
	@echo "#---------------------------"
	@echo "# Generando $@"
	@echo "# Depende de $^"
	@echo "# Ha cambiado $<"
	$(CC) $(CFLAGS) -c $<

ejercicio1_test:
	@echo Ejecutando ejercicio1
	@./ejercicio1 -limInf 1 -limSup 5 -numN 5

ejercicio1h_test:
	@echo Ejecutando ejercicio1h
	@./ejercicio1h -limInf 1 -limSup 10 -numN 100000

ejercicio2_test:
	@echo Ejecutando ejercicio2
	@./ejercicio2 -tamanio 4 -numP 5

ejercicio3_test:
	@echo Ejecutando ejercicio3
	@./ejercicio3 -tamanio 5 -numP 5

ejercicio4_test:
	@echo Ejecutando ejercicio4
	@./ejercicio4 -tamanio 15

ejercicio5_test:
	@echo Ejecutando ejercicio5
	@./ejercicio5 -num_min 1 -num_max 5 -incr 1 -numP 5 -fichSalida ejercicio5.log
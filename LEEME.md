# AlgorithmCompetition
Un pequeño programa para poner a competir algoritmos de ordenamiento.

Este programa sirve para medir los tiempos de ejecucion de varios algoritmos de 
ordenamiento, y en cierta forma enfrentarlos para saber cual de ellos tiene un mejor desempeño.

Para ello he considerado varios algoritmos de ordenamiento (ire agregando mas en el futuro), he creado
una clase de tipo competencia para facilitar las cosas, la clase es una plantilla al igual que las funciones
para cada algoritmo de ordenamiento, por lo que deberas especificar el tipo de dato con el que se va a trabajar
al instaciar un objeto.

El programa solicita un archivo de entrda por consola el cual contiene los datos con los que los algoritmos van a trabajar 
posteriormente se solicita elegir cuales algoritmos se pondran a competir, para finalmente determinar un ganador comparando 
los tiempos de ejecucion de ambos, y los imprime en pantalla(en segundos y milisegundos). el programa puede ejecutarse varias veces
usando un mismo input y seleccionando distintos algoritmos.

Ejemplo de como mandara llamar al programa(linux):
./programa numeros_mediano_03.in

Ejemplo de como se ve el programa en ejecución:
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
El archivo seleccionado es: numeros_mediano_03.in
COMPETENCIA DE ALGORITMOS
Seleccione los algoritmos que van a competir: 
Bubble sort       B
Insertion sort    I
Selection sort    S
Quick sort        Q
Merge sort        M
Quick sort al.    A
Merge hibrido     H
b s
¡El ganador es Selection Sort !
Tiempo de ejecucion de  Bubble Sort
5.33305 S
5333.05 Ms
Tiempo de ejecucion de  Selection Sort
4.8483 S
5333.05 Ms
Repetir la competencia? (S/N) 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////



# Comparador de Algoritmos de Ordenamiento

Este proyecto es un programa en C++ desarrollado para la materia de Programación Competitiva de la UNAP. El programa genera una cantidad N de números aleatorios dentro de un rango específico y evalúa la eficiencia de 6 algoritmos de ordenamiento clásicos: Burbuja, Selección, Inserción, Shell Sort, Merge Sort y Quick Sort.

La comparación se realiza midiendo la cantidad de pasos (comparaciones internas) que realiza cada algoritmo y el tiempo de ejecución en nanosegundos.

## Requisitos y Compilación

Para probar el programa solo se necesita tener instalado el compilador `g++` (MinGW en Windows o GCC en Linux/Mac). No se utilizan librerías externas.

### Cómo compilar el programa
Abre tu terminal, ubícate en la carpeta del proyecto y ejecuta el siguiente comando:

```bash
g++ -o main main.cpp
```

### Cómo ejecutar el programa
Una vez compilado, puedes correrlo con:

En Windows:
```bash
.\main.exe
```

En Linux/Mac:
```bash
./main
```

---

## Ejemplos de Ejecución

A continuación se muestran dos ejemplos de cómo funciona el programa. Se ingresan por consola 3 datos: la cantidad de números a generar, el valor mínimo y el valor máximo.

### Ejemplo 1: Arreglo pequeño (20 elementos)
Este ejemplo es útil para ver los números ordenados rápidamente, aunque el tiempo en nanosegundos marque cero porque la computadora lo procesa de forma casi instantánea.

**Entrada:**
* Cantidad: 20
* Mínimo: 1
* Máximo: 100

**Salida en consola:**
```text
=================================================
   COMPARADOR DE ALGORITMOS DE ORDENAMIENTO      
=================================================

Cuantos numeros quieres generar? : 20
Valor minimo del rango           : 1
Valor maximo del rango           : 100

Arreglo generado (20 elementos):
[ 42, 68, 35, 1, 70, 25, 79, 59, 63, 65, 6, 46, 82, 28, 62, 92, 96, 43, 28, 37 ]

----- RESULTADOS (ordenados por tiempo) -----

Pos     Algoritmo       Pasos           Tiempo (ns)
---     ---------       -----           -----------
1       Burbuja         190             0.00
2       Seleccion       190             0.00
3       Insercion       106             0.00
4       Shell Sort      109             0.00
5       Merge Sort      88              0.00
6       Quick Sort      81              0.00

El algoritmo mas rapido fue: Burbuja con 0.00 ns.
```

### Ejemplo 2: Arreglo grande (10,000 elementos)
Para evaluar correctamente el rendimiento de cada algoritmo, es necesario usar arreglos más grandes. Aquí se nota claramente la diferencia de velocidad entre métodos como Quick Sort y Burbuja.

**Entrada:**
* Cantidad: 10000
* Mínimo: 1
* Máximo: 100000

**Salida en consola:**
```text
=================================================
   COMPARADOR DE ALGORITMOS DE ORDENAMIENTO      
=================================================

Cuantos numeros quieres generar? : 10000
Valor minimo del rango           : 1
Valor maximo del rango           : 100000

Arreglo generado (10000 elementos):
[ 68285, 45155, 9625, ... (se omiten por espacio) ... ]

----- RESULTADOS (ordenados por tiempo) -----

Pos     Algoritmo       Pasos           Tiempo (ns)
---     ---------       -----           -----------
1       Quick Sort      158068          0.00
2       Shell Sort      280068          1514000.00
3       Merge Sort      133616          2035000.00
4       Insercion       25034442        54642000.00
5       Seleccion       49995000        108415000.00
6       Burbuja         49995000        173434000.00

El algoritmo mas rapido fue: Quick Sort con 0.00 ns.
```

*Nota: Quick Sort es tan eficiente que, a veces, incluso con 10,000 elementos termina en un tiempo inferior a la precisión del reloj en milisegundos, registrándose como 0.00 ns, mientras que Burbuja tarda notablemente más.*
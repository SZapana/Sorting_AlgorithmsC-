// Comparador de Algoritmos de Ordenamiento
// Materia: Programacion Competitiva - UNAP
// Compilar: g++ -o main main.cpp
// Ejecutar: ./main

#include <iostream>
#include <string>
#include <stdlib.h>  // para rand() y srand()
#include <time.h>    // para time()
#include <chrono>    // para medir tiempo en nanosegundos

using namespace std;

// Estructura para guardar los resultados
struct Resultado {
    string nombre;
    long long pasos;
    double tiempo; // en nanosegundos
};

// copiar arreglo
void copiarArreglo(int original[], int copia[], int n) {
    for (int i = 0; i < n; i++) {
        copia[i] = original[i];
    }
}

// imprimir arreglo
void imprimirArreglo(int arr[], int n) {
    cout << "[ ";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << " ]" << endl;
}

// ------- BURBUJA -------
double burbuja(int arr[], int n, long long &pasos) {
    pasos = 0;
    auto inicio = chrono::high_resolution_clock::now();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            pasos++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double, nano> duracion = fin - inicio;
    return duracion.count();
}

// ------- SELECCION -------
double seleccion(int arr[], int n, long long &pasos) {
    pasos = 0;
    auto inicio = chrono::high_resolution_clock::now();

    for (int i = 0; i < n - 1; i++) {
        int minimo = i;
        for (int j = i + 1; j < n; j++) {
            pasos++;
            if (arr[j] < arr[minimo]) {
                minimo = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minimo];
        arr[minimo] = temp;
    }

    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double, nano> duracion = fin - inicio;
    return duracion.count();
}

// ------- INSERCION -------
double insercion(int arr[], int n, long long &pasos) {
    pasos = 0;
    auto inicio = chrono::high_resolution_clock::now();

    for (int i = 1; i < n; i++) {
        int clave = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > clave) {
            pasos++;
            arr[j + 1] = arr[j];
            j--;
        }
        pasos++;
        arr[j + 1] = clave;
    }

    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double, nano> duracion = fin - inicio;
    return duracion.count();
}

// ------- SHELL SORT -------
double shellSort(int arr[], int n, long long &pasos) {
    pasos = 0;
    auto inicio = chrono::high_resolution_clock::now();

    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                pasos++;
                arr[j] = arr[j - gap];
                j -= gap;
            }
            pasos++;
            arr[j] = temp;
        }
    }

    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double, nano> duracion = fin - inicio;
    return duracion.count();
}

// ------- MERGE SORT -------
long long pasosGlobalMerge;

void merge(int arr[], int izq, int medio, int der) {
    int n1 = medio - izq + 1;
    int n2 = der - medio;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[izq + i];
    for (int j = 0; j < n2; j++) R[j] = arr[medio + 1 + j];

    int i = 0, j = 0, k = izq;

    while (i < n1 && j < n2) {
        pasosGlobalMerge++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++; k++;
        pasosGlobalMerge++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++; k++;
        pasosGlobalMerge++;
    }

    delete[] L;
    delete[] R;
}

void mergeSortRec(int arr[], int izq, int der) {
    if (izq < der) {
        int medio = (izq + der) / 2;
        mergeSortRec(arr, izq, medio);
        mergeSortRec(arr, medio + 1, der);
        merge(arr, izq, medio, der);
    }
}

double mergeSort(int arr[], int n, long long &pasos) {
    pasosGlobalMerge = 0;
    auto inicio = chrono::high_resolution_clock::now();
    mergeSortRec(arr, 0, n - 1);
    auto fin = chrono::high_resolution_clock::now();
    pasos = pasosGlobalMerge;
    chrono::duration<double, nano> duracion = fin - inicio;
    return duracion.count();
}

// ------- QUICK SORT -------
long long pasosGlobalQuick;

int particion(int arr[], int izq, int der) {
    int pivote = arr[der];
    int i = izq - 1;

    for (int j = izq; j < der; j++) {
        pasosGlobalQuick++;
        if (arr[j] <= pivote) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[der];
    arr[der] = temp;

    return i + 1;
}

void quickSortRec(int arr[], int izq, int der) {
    if (izq < der) {
        int pi = particion(arr, izq, der);
        quickSortRec(arr, izq, pi - 1);
        quickSortRec(arr, pi + 1, der);
    }
}

double quickSort(int arr[], int n, long long &pasos) {
    pasosGlobalQuick = 0;
    auto inicio = chrono::high_resolution_clock::now();
    quickSortRec(arr, 0, n - 1);
    auto fin = chrono::high_resolution_clock::now();
    pasos = pasosGlobalQuick;
    chrono::duration<double, nano> duracion = fin - inicio;
    return duracion.count();
}

// ordenar resultados por tiempo (de menor a mayor)
void ordenarResultados(Resultado res[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (res[j].tiempo > res[j + 1].tiempo) {
                Resultado temp = res[j];
                res[j] = res[j + 1];
                res[j + 1] = temp;
            }
        }
    }
}

// ============ PROGRAMA PRINCIPAL ============
int main() {
    int n, minVal, maxVal;

    cout << "=================================================" << endl;
    cout << "   COMPARADOR DE ALGORITMOS DE ORDENAMIENTO      " << endl;
    cout << "=================================================" << endl;

    cout << "\nCuantos numeros quieres generar? : ";
    cin >> n;
    cout << "Valor minimo del rango           : ";
    cin >> minVal;
    cout << "Valor maximo del rango           : ";
    cin >> maxVal;

    if (n <= 0) {
        cout << "Error: la cantidad debe ser mayor a 0." << endl;
        return 1;
    }
    if (minVal > maxVal) {
        cout << "Error: el minimo no puede ser mayor que el maximo." << endl;
        return 1;
    }

    // generar numeros aleatorios
    srand(time(0));
    int* arreglo = new int[n];
    for (int i = 0; i < n; i++) {
        arreglo[i] = minVal + rand() % (maxVal - minVal + 1);
    }

    cout << "\nArreglo generado (" << n << " elementos):" << endl;
    imprimirArreglo(arreglo, n);

    int* copia = new int[n];

    // ejecutar los 6 algoritmos
    Resultado res[6];

    copiarArreglo(arreglo, copia, n);
    res[0].nombre = "Burbuja";
    res[0].tiempo = burbuja(copia, n, res[0].pasos);

    copiarArreglo(arreglo, copia, n);
    res[1].nombre = "Seleccion";
    res[1].tiempo = seleccion(copia, n, res[1].pasos);

    copiarArreglo(arreglo, copia, n);
    res[2].nombre = "Insercion";
    res[2].tiempo = insercion(copia, n, res[2].pasos);

    copiarArreglo(arreglo, copia, n);
    res[3].nombre = "Shell Sort";
    res[3].tiempo = shellSort(copia, n, res[3].pasos);

    copiarArreglo(arreglo, copia, n);
    res[4].nombre = "Merge Sort";
    res[4].tiempo = mergeSort(copia, n, res[4].pasos);

    copiarArreglo(arreglo, copia, n);
    res[5].nombre = "Quick Sort";
    res[5].tiempo = quickSort(copia, n, res[5].pasos);

    // ordenar de menor a mayor tiempo
    ordenarResultados(res, 6);

    // mostrar resultados con decimales
    cout << fixed;
    cout.precision(2);

    cout << "\n----- RESULTADOS (ordenados por tiempo) -----\n" << endl;
    cout << "Pos\tAlgoritmo\tPasos\t\tTiempo (ns)" << endl;
    cout << "---\t---------\t-----\t\t-----------" << endl;

    for (int i = 0; i < 6; i++) {
        cout << (i + 1) << "\t" << res[i].nombre << "\t\t" << res[i].pasos << "\t\t" << res[i].tiempo << endl;
    }

    cout << "\nEl algoritmo mas rapido fue: " << res[0].nombre << " con " << res[0].tiempo << " ns." << endl;

    delete[] arreglo;
    delete[] copia;

    return 0;
}
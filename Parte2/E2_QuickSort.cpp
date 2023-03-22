#include <iostream>
#include <ctime>
using namespace std;

//Se hace la partición utilizando el sistema de partición de Lomuto
int partition(int arr[], int start, int end) {
//Se selecciona el pivote más a la izquierda como el pivote
    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }

// Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

// Sorting left and right parts of the pivot element
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (arr[i] <= pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

//Intercambia el pivote con el elemento mayor o menor
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

//Devuelve el índice del elemento pivote
    return pivotIndex;
}

void quickSort(int arr[], int start, int end) {
// condición base
    if (start >= end)
        return;

// reorganizar los elementos a través del pivote
    int p = partition(arr, start, end);

// Función recursiva
// Sublista con elementos menores que el pivote
    quickSort(arr, start, p - 1);

// Función recursiva
// Sublista con elementos menores que el pivote
    quickSort(arr, p + 1, end);
}

double mediana(int array[], int n) {
    double mediana;
    if (n % 2 != 0) {
        mediana = array[n/2];
    } else {
        mediana = (array[n/2] + array[(n/2) - 1])/2;
    }

    return mediana;

}

void Imprimir(int array[], int size) {
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

int main() {
    unsigned t0, t1;
    t0 = clock();

    int n = 200000;
    int edades[n];

    srand(time(nullptr));

    for (int i = 0; i < 200000; i++) {
        edades[i] = (rand() % 105 + 1);
    }

    quickSort(edades, 0, n - 1);

    // Imprimir(edades, n);

    cout << "Mediana: "  << mediana(edades, n) << endl;


    t1 = clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;
}

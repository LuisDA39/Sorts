#include <iostream>
#include <cstdlib>
using namespace std;

int shellSort(int arr[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap){
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
    return 0;
}

void insertionSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int pos = i;
        int aux = arr[i];

        while ((pos > 0) && (arr[pos - 1] > aux)) {
            arr[pos] = arr[pos - 1];
            pos--;
        }
        arr[pos] = aux;
    }
}

void mostrar(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}


int main() {
    int n = 100;
    int edadesShell[n];
    int edadesIncersion[n];

    srand(time(nullptr));

    for (int i = 0; i < 100; i++) {
        edadesShell[i] = (rand() % 50 + 1);
        edadesIncersion[i] = (rand() % 50 + 1);
    }

    cout << "Shell desordenado: ";
    mostrar(edadesShell, n);

    cout << "\n";

    shellSort(edadesShell, 100);

    cout << "Shell ordenado: ";
    mostrar(edadesShell, n);

    cout << "\n\n";

    cout << "Insercion desordenado: ";
    mostrar(edadesIncersion, n);

    cout << "\n";

    insertionSort(edadesIncersion, 100);


    cout << "Insercion ordenado: ";
    mostrar(edadesIncersion, n);

}

// Shell mejora al algoritmo de inserción al hacer las comparaciones con elementos distantes en lugar de elementos adyacentes

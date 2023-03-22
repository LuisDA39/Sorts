#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i; // Inicializar el nodo más grande como la raíz
    int l = 2 * i + 1; // índice del hijo izquierdo en el arreglo
    int r = 2 * i + 2; // índice del hijo derecho en el arreglo

// Si el hijo izquierdo es más grande que la raíz
    if (l < n && arr[l] > arr[largest])
        largest = l;

// Si el hijo derecho es más grande que la raíz
    if (r < n && arr[r] > arr[largest])
        largest = r;

// Si el nodo más grande no es la raíz
    if (largest != i) {
        swap(arr[i], arr[largest]);
// Recursivamente heapify el subárbol afectado
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    int c = 1;

    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    } cout << " - Pasada: " << c << endl;

// Construir el heap (reorganizar el arreglo)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

// Extraer elementos uno por uno del heap
    for (int i = n - 1; i >= 0; i--) {
        c++;
// Mover la raíz actual al final
        swap(arr[0], arr[i]);

// Llamar heapify en el heap reducido
        heapify(arr, i, 0);

        for (int i = 0; i < n; i++){
            cout << arr[i] << " ";
        } cout << " - Pasada: " << c << endl;

    }
}

void imprimir(int arr[], int n) {
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
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

int main(){
    int n = 10;
    int arr[10] = {179, 159, 173, 169, 185, 192, 180, 172, 167, 187};

    heapSort(arr, n);

    cout << "Estatura menor: " << arr[0] << " cm" << endl;
    cout << "Estatura mayor: " << arr[n - 1] << " cm" << endl;

    cout << "Mediana: " << mediana(arr, n) << " cm" << endl;


    return 0;
}

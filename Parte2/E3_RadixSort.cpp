#include <bits/stdc++.h>
using namespace std;

int getMax(int arr[], int n){
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)  mx = arr[i];
    return mx;
}

void CountSort(int arr[], int n, int exp){
    int output[n];
    int i, count[10] = {};
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
    return;
}

void Radixsort(int arr[], int n){
    int m = getMax(arr, n);
    int c = 1;

    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    } cout << " - Pasada: " << c << endl;

    for (int exp = 1; m / exp > 0; exp *= 10) {
        c++;
        CountSort(arr, n, exp);

        for (int i = 0; i < n; i++){
            cout << arr[i] << " ";
        } cout << " - Pasada: " << c << endl;

    }

    return;
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

    Radixsort(arr, n);

    cout << "Estatura menor: " << arr[0] << " cm" << endl;
    cout << "Estatura mayor: " << arr[n - 1] << " cm" << endl;

    cout << "Mediana: " << mediana(arr, n) << " cm" << endl;


    return 0;
}

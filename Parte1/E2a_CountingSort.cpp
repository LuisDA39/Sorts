#include <iostream>
using namespace std;

void countSort(int array[], int size) {
    int output[size];
    int count[17];  // count[max + 1]
    int max = array[0];

    // Find the largest element of the array
    for (int i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    // Initialize count array with all zeros.
    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }

    // Store the count of each element
    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }

    // Store the cummulative count of each array
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Find the index of each element of the original array in count array, and
    // place the elements in output array
    for (int i = size - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    // Copy the sorted elements into original array
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
}

void Imprimir(int array[], int size) {
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

int moda(int array[], int n) {
    int number = array[0];
    int moda = number;
    int count = 1;
    int countMode = 1;

    for (int i=1; i<n; i++) {
        if (array[i] == number)
        { // count occurrences of the current number
            ++count;
        }
        else
        { // now this is a different number
            if (count > countMode)
            {
                countMode = count; // mode is the biggest ocurrences
                moda = number;
            }
            count = 1; // reset count for the new number
            number = array[i];
        }
    }
    return moda;
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

int main() {
    int array[] = {13, 15, 8, 16, 8};
    int n = sizeof(array) / sizeof(array[0]);
    countSort(array, n);
    Imprimir(array, n);

   cout << "Moda: " << moda(array, n) << endl;

   cout << "Mediana: " << mediana(array, n) << endl;
}

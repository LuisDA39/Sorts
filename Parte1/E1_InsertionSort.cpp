#include <iostream>
using namespace std;

class PaisesHabitantes {
private:
    string paises[5] = {"Estonia", "Camboya", "Dinamarca", "Brasil", "Argentina"};
    int habitantes[5] = {2, 17, 6, 220, 47};
public:
    void ordenarPorNombres();
    void ordenarPorHabitantes();
    void imprimir();
};

void PaisesHabitantes::ordenarPorNombres() {
    for (int i = 0; i < 5; i++) {
        int pos = i;
        string aux = paises[i];
        int auxhab = habitantes[i];

        while ((pos > 0) && (paises[pos - 1] > aux)) {
            paises[pos] = paises[pos - 1];
            habitantes[pos] = habitantes[pos - 1];
            pos--;
        }

        paises[pos] = aux;
        habitantes[pos] = auxhab;

    }
}

void PaisesHabitantes::ordenarPorHabitantes() {
    for (int i = 0; i < 5; i++) {
        int pos = i;
        string aux = paises[i];
        int auxhab = habitantes[i];

        while ((pos > 0) && (habitantes[pos - 1] > auxhab)) {
            paises[pos] = paises[pos - 1];
            habitantes[pos] = habitantes[pos - 1];
            pos--;
        }

        paises[pos] = aux;
        habitantes[pos] = auxhab;

    }
}

void PaisesHabitantes::imprimir() {
    for (int f = 0; f < 5; f++) {
        cout << paises[f] << " - " << habitantes[f] << "\n";
    }
}

int main() {
    PaisesHabitantes ph;
    ph.ordenarPorNombres();
    cout << "Ordenado por nombres" << "\n";
    ph.imprimir();

    cout << endl;

    ph.ordenarPorHabitantes();
    cout << "Ordenado por cantidad de habitantes" << "\n";
    ph.imprimir();

}

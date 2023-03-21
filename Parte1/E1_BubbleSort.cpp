#include <iostream>
using namespace std;

class PaisesHabitantes {
private:
    string paises[5] = {"Mexico", "USA", "Russia", "Brasil", "Argentina"};
    int habitantes[5] = {129, 330, 147, 220, 47};
public:
    void ordenarPorNombres();
    void ordenarPorHabitantes();
    void imprimir();
};

void PaisesHabitantes::ordenarPorNombres() {
    bool interruptor = true;
    int pasada, j;
    for (pasada = 0; pasada < 5 - 1 && interruptor; pasada++) {
        interruptor = false;
        for (j = 0; j < 5 - pasada - 1; j++)
            if (paises[j] > paises[j + 1]) {
                interruptor = true;
                string auxpais = paises[j];
                paises[j] = paises[j + 1];
                paises[j + 1] = auxpais;
                int auxhabitante;
                auxhabitante = habitantes[j];
                habitantes[j] = habitantes[j + 1];
                habitantes[j + 1] = auxhabitante;
            }
    }
}

void PaisesHabitantes::ordenarPorHabitantes() {
    bool interruptor = true;
    int pasada, j;
    for (pasada = 0; pasada < 5 - 1 && interruptor; pasada++) {
        interruptor = false;
        for (j = 0; j < 5 - pasada - 1; j++)
            if (paises[j] > paises[j + 1]) {
                interruptor = true;
                string auxpais = paises[j];
                paises[j] = paises[j + 1];
                paises[j + 1] = auxpais;
                int auxhabitante;
                auxhabitante = habitantes[j];
                habitantes[j] = habitantes[j + 1];
                habitantes[j + 1] = auxhabitante;
            }
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

    ph.ordenarPorHabitantes();
    cout << "Ordenado por cantidad de habitantes" << "\n";
    ph.imprimir();

}

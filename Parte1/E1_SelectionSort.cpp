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
    for(int i = 0; i < 5 ; i++){
        int min = i;
        for(int j = i + 1; j < 5; j++){
            if(paises[j] < paises[min]){
                min = j;
            }
        }
        string auxpaises = paises[i];
        paises[i] = paises[min];
        paises[min] = auxpaises;
        int auxhabs = habitantes[i];
        habitantes[i] = habitantes[min];
        habitantes[min] = auxhabs;
    }
}

void PaisesHabitantes::ordenarPorHabitantes() {
    for(int i = 0; i < 5 ; i++){
        int min = i;
        for(int j = i + 1; j < 5; j++){
            if(habitantes[j] < habitantes[min]){
                min = j;
            }
        }
        string auxpaises = paises[i];
        paises[i] = paises[min];
        paises[min] = auxpaises;
        int auxhabs = habitantes[i];
        habitantes[i] = habitantes[min];
        habitantes[min] = auxhabs;
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

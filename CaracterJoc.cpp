#include <iostream>
#include <string>

using namespace std;

class CaracterJoc {
private:
    string denumireCaracter;
    int nivelViata;
    int nrAbilitati;
    int* putereAtac;
    double vitezaMiscare; 

public:

    CaracterJoc(string denumireCaracter, int nrAbilitati, int* putereAtac, double vitezaMiscare) {
        this->denumireCaracter = denumireCaracter;
        this->nivelViata = 100;
        this->vitezaMiscare = vitezaMiscare;

        if (putereAtac != nullptr && nrAbilitati > 0) {
            int contor = 0;
            for (int i = 0; i < nrAbilitati; i++) {
                if (putereAtac[i] >= 0 && putereAtac[i] <= 100) {
                    contor++;
                }
            }

            this->nrAbilitati = contor;
            if (this->nrAbilitati > 0) {
                this->putereAtac = new int[this->nrAbilitati];
                int k = 0;
                for (int i = 0; i < nrAbilitati; i++) {
                    if (putereAtac[i] >= 0 && putereAtac[i] <= 100) {
                        this->putereAtac[k++] = putereAtac[i];
                    }
                }
            }
            else {
                this->putereAtac = nullptr;
            }
        }
        else {
            this->nrAbilitati = 0;
            this->putereAtac = nullptr;
        }
    }


    void adaugaPutereAtac(int putereAtac) {
        if (putereAtac >= 0 && putereAtac <= 100) {
            int* copie = new int[this->nrAbilitati + 1];
            for (int i = 0; i < this->nrAbilitati; i++) {
                copie[i] = this->putereAtac[i];
            }
            copie[this->nrAbilitati] = putereAtac;

            delete[] this->putereAtac;
            this->putereAtac = copie;
            this->nrAbilitati++;
        }
    }


    void anuleazaAbilitatiSubPrag(int prag) {
        for (int i = 0; i < this->nrAbilitati; i++) {
            if (this->putereAtac[i] < prag) {
                this->putereAtac[i] = 0;
            }
        }
    }


    void afisare() {
        cout << this->denumireCaracter << " "
            << this->nivelViata << " "
            << this->nrAbilitati << " ";
        for (int i = 0; i < this->nrAbilitati; i++) {
            cout << this->putereAtac[i] << " ";
        }
        cout << this->vitezaMiscare << endl;
    }

    void atacaSiPreluare(int*& putereAtac, int& nrAbilitati) {
        if (putereAtac != nullptr && nrAbilitati > 0) {
            int pozitieMaxim = 0;
            int valoareMaxima = putereAtac[0];

            for (int i = 1; i < nrAbilitati; i++) {
                if (putereAtac[i] > valoareMaxima) {
                    valoareMaxima = putereAtac[i];
                    pozitieMaxim = i;
                }
            }

            this->adaugaPutereAtac(valoareMaxima);

            if (nrAbilitati == 1) {
                delete[] putereAtac;
                putereAtac = nullptr;
                nrAbilitati = 0;
            }
            else {
                int* vectorNou = new int[nrAbilitati - 1];
                int k = 0;
                for (int i = 0; i < nrAbilitati; i++) {
                    if (i != pozitieMaxim) {
                        vectorNou[k++] = putereAtac[i];
                    }
                }
                delete[] putereAtac;
                putereAtac = vectorNou;
                nrAbilitati--;
            }
        }
    }


    ~CaracterJoc() {
        if (this->putereAtac != nullptr) {
            delete[] this->putereAtac;
            this->putereAtac = nullptr;
        }
    }
};

int main() {
    int abilitatiInitiale[] = { 45, 80, 120, -5, 95 };

    CaracterJoc c1("Razboinic", 5, abilitatiInitiale, 14.5);
    cout << "Initial: ";
    c1.afisare();

    c1.adaugaPutereAtac(70);
    cout << "Adaugare: ";
    c1.afisare();

    c1.anuleazaAbilitatiSubPrag(75);
    cout << "Anulare: ";
    c1.afisare();

    int dimensiuneInamic = 3;
    int* abilitatiInamic = new int[dimensiuneInamic] { 30, 99, 50 };

    cout << "Inamic: ";
    for (int i = 0; i < dimensiuneInamic; i++) {
        cout << abilitatiInamic[i] << " ";
    }
    cout << endl;

    c1.atacaSiPreluare(abilitatiInamic, dimensiuneInamic);

    cout << "DupaAtac: ";
    c1.afisare();

    cout << "InamicRamas: ";
    for (int i = 0; i < dimensiuneInamic; i++) {
        cout << abilitatiInamic[i] << " ";
    }
    cout << endl;

    delete[] abilitatiInamic;
    return 0;
}
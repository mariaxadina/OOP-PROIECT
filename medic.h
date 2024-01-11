#ifndef MEDIC_H_INCLUDED
#define MEDIC_H_INCLUDED
#include <iostream>
#include <string>
#include "medical.h"

using namespace std;

class Medic :public Personal_Medical{
protected:
    string specializare;
    int NIM; /// numar de identificare medicala
public:
    Medic(string nume = "Ion", string prenume = "Paul", int varsta = 1, string nr_telefon = "0256738994",float salariu = 4678, string specializare = "Cardiologie", int NIM = 0);
    ~Medic();
    Medic (const Medic& obj);
    Medic &operator= (const Medic& obj);

    friend istream& operator>>(istream& in, Medic& obj);
    friend ostream& operator<<(ostream& out, const Medic& obj);

    void modifica() override {
        Personal_Medical::modifica();
        cout << "Introduceti specializarea:\n";
        cin >> specializare;
        cout << "Introduceti numarul d eidentificare medical(NIM):\n";
    }


};

#endif // MEDIC_H_INCLUDED

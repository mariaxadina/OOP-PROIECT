#ifndef CARDIOLOG_H_INCLUDED
#define CARDIOLOG_H_INCLUDED

#include "medic.h"

using namespace std;

class Cardiolog: public Medic {
protected:
    int nr_interventii;
public:
    Cardiolog(string nume = "Ion", string prenume = "Paul", int varsta = 1, string nr_telefon = "0256738994", float salariu = 4589.3,
            string specializare = "Stomatolog", int NIM = 0, int nr_interventii = 68);
    ~Cardiolog();
    Cardiolog(const Cardiolog& obj);
    Cardiolog &operator=(const Cardiolog& obj);

    friend istream& operator>>(istream& in, Cardiolog& obj);
    friend ostream& operator<<(ostream& out, const Cardiolog& obj);

    void modifica() override
    {
        Personal_Medical::modifica();
        cout << "Introduceti numarul de interventii:\n";
        cin >> nr_interventii;
    }
    int getNr_interventii() const
    {
        return nr_interventii;
    }
};


#endif // CARDIOLOG_H_INCLUDED

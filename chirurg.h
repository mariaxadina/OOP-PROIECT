#ifndef CHIRURG_H_INCLUDED
#define CHIRURG_H_INCLUDED
#include "medic.h"

using namespace std;

class Chirurg: public Medic {
protected:
    int nr_interventii;
public:
    Chirurg(string nume = "Ion", string prenume = "Paul", int varsta = 1, string nr_telefon = "0256738994",float salariu = 2567.9,
            string specializare = "Cardiologie", int NIM = 0, int nr_interventii = 68);
    ~Chirurg();
    Chirurg(const Chirurg& obj);
    Chirurg &operator=(const Chirurg& obj);

    friend istream& operator>>(istream& in, Chirurg& obj);
    friend ostream& operator<<(ostream& out, const Chirurg& obj);

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


#endif // CHIRURG_H_INCLUDED

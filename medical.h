#ifndef MEDICAL_H
#define MEDICAL_H
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Personal_Medical {
protected:
    string nume;
    string prenume;
    int varsta;
    string nr_telefon;
    float salariu;
public:
    Personal_Medical(string nume = "Ion", string prenume = "Paul", int varsta = 1, string nr_telefon = "0256738994", float salariu = 4765.4);
    virtual ~Personal_Medical();
    Personal_Medical(const Personal_Medical& obj);
    Personal_Medical &operator=(const Personal_Medical& obj);

    friend istream& operator>>(istream& in, Personal_Medical& obj);
    friend ostream& operator<<(ostream& out, const Personal_Medical& obj);

    virtual void modifica()
    {
    cout << "Introduceti noul nume: ";
    cin >> nume;
    cout << "Introduceti noul prenume: ";
    cin >> prenume;
    cout << "Introduceti varsta: ";
    cin >> varsta;
    cout << "Introduceti numarul de telefon: ";
    cin >> nr_telefon;
    cout << "Introduceti salariu: ";
    cin >> salariu;
    }

    string getNume() const {
        return nume;
    }

    string getPrenume() const {
        return prenume;
    }

    float getSalariu() const {
        return salariu;
    }
};



#endif

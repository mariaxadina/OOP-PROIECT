#ifndef ASISTENT_H_INCLUDED
#define ASISTENT_H_INCLUDED
#include <iostream>
#include <string>
#include "medical.h"

using namespace std;

class Asistent : public Personal_Medical{
protected:
    int ani_experienta;
public:
    Asistent(string nume = "Ion", string prenume = "Paul", int varsta = 1, string nr_telefon = "0256738994",float salariu = 8743, int ani_experienta = 0);
    ~Asistent();
    Asistent(const Asistent& obj);
    Asistent &operator= (const Asistent& obj);

    friend istream& operator >>(istream& in, Asistent& obj);
    friend ostream& operator<<(ostream& out,const Asistent& obj );

    void modifica() override {
        Personal_Medical::modifica();
        cout << "Introduceti numarul de ani experienta:\n";
        cin >> ani_experienta;
    }
};


#endif // ASISTENT_H_INCLUDED

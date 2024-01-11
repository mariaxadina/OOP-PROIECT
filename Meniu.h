#ifndef MENIU_H_INCLUDED
#define MENIU_H_INCLUDED
#include <vector>
#include "medical.h"
using namespace std;

class Meniu{
private:
    static vector<Personal_Medical*> personalMedicalVector;
    Meniu(){ };
public:
    Meniu(Meniu const&) = delete;
    void operator=(Meniu const&) = delete;

    static Meniu& getInstance()
    {
        static Meniu instance;
        return instance;
    }
    static vector<Personal_Medical*>& getPersonalMedicalVector()
    {
        return personalMedicalVector;
    }

    void afiseazaMeniu() const;
    void startMeniu();

    template <typename T, typename U>
    static T suma(T (U::*membru)() const);




};


#endif // MENIU_H_INCLUDED

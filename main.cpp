#include <iostream>
#include <conio.h>
#include <vector>
#include "medical.h"
#include "asistent.h"
#include "medic.h"
#include "cardiolog.h"
#include "chirurg.h"
#include "Meniu.h"

using namespace std;

int main()
{
    Asistent asistent1("Popescu", "Ana", 30, "0755123456", 4567.3, 5);
    Medic medic1("Ionescu", "Mihai", 35, "0722334455", 3259.4, "Cardiologie", 12345);
    Chirurg chirurg1("Radulescu", "Ioana", 40, "0711223344", 5559.4, "Chirurgie", 54321, 20);
    Cardiolog cardiolog1("Pasalan", "Lavinia", 55, "0711227444", 8859.4, "Cardiologie", 54331, 28);
    vector<Personal_Medical*>& PersonalMedicalVector = Meniu::getPersonalMedicalVector();
    PersonalMedicalVector.push_back(&asistent1);
    PersonalMedicalVector.push_back(&medic1);
    PersonalMedicalVector.push_back(&chirurg1);
    PersonalMedicalVector.push_back(&cardiolog1);

    Meniu& m = Meniu::getInstance();
    m.startMeniu();

    return 0;
}

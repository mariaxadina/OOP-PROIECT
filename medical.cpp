#include "medical.h"
#include "asistent.h"
#include "medic.h"
#include "chirurg.h"
#include "cardiolog.h"
#include "Meniu.h"
#include "exceptii.h"
#include <vector>
#include <string>
#include <stdexcept>
#include <memory>



using namespace std;

///Clasa Personal_Medical

//constructor
Personal_Medical::Personal_Medical(string nume, string prenume, int varsta, string nr_telefon, float salariu)
{

    this->nume = nume;
    this->prenume = prenume;
    this->varsta = varsta;
    this->nr_telefon = nr_telefon;
    this->salariu = salariu;
}

//destructor
Personal_Medical:: ~Personal_Medical()
{
    if(!this->nume.empty()) this->nume.clear();
    if(!this->prenume.empty()) this->prenume.clear();
    if(!this->nr_telefon.empty()) this->nr_telefon.clear();
}

//constructor de copiere
Personal_Medical::Personal_Medical(const Personal_Medical& obj)
{
    this->nume = obj.nume;
    this->prenume = obj.prenume;
    this->varsta = obj.varsta;
    this->nr_telefon = obj.nr_telefon;
    this->salariu = obj.salariu;
}
//operator de copiere
Personal_Medical &Personal_Medical ::operator=(const Personal_Medical& obj)
{
    if(this != &obj)
    {
        this->nume = obj.nume;
        this->prenume = obj.prenume;
        this->varsta = obj.varsta;
        this->nr_telefon = obj.nr_telefon;
        this->salariu = obj.salariu;
    }
    return *this;
}

//istream
istream &operator>>(istream& in, Personal_Medical& obj)
{
    cout << "Introduceti numele: " << endl;
    in >> obj.nume;

    cout << "Introduceti prenumele: " << endl;
    in >> obj.prenume;

    try
    {
        cout << "Introduceti varsta: " << endl;
        in >> obj.varsta;
        if(obj.varsta < 20)
        {
            throw VarstaInvalidaException();
        }
    }
    catch(const VarstaInvalidaException& e)
    {
        cout << e.what() << "\n";
        cout << "Varsta introdusa: " << obj.varsta << "\n";
    }
    try
    {
        cout << "Introduceti numarul de telefon: " << endl;
        in >> obj.nr_telefon;
        if(obj.nr_telefon.length() != 10)
        {
            throw NumarTelefonInvalidException();
        }
    }
    catch (const NumarTelefonInvalidException& e)
    {
        cout << e.what() << "\n";
        cout << "Numarul " << obj.nr_telefon << " este invalid.\n";
    }
    cout << "Introduceti salariul: " << endl;
        in >> obj.salariu;

    return in;
}

//ostream
ostream& operator<<(ostream& out, const Personal_Medical& obj)
{
    out << "Nume: " << obj.nume << endl;
    out << "Prenume: " << obj.prenume << endl;
    out << "Varsta: " << obj.varsta << endl;
    out << "Numar de telefon: " << obj.nr_telefon << endl;
    out << "Salariu: " << obj.salariu << endl;
    return out;
}


///Clasa Asistent

//constructor
Asistent::Asistent(string nume, string prenume, int varsta, string nr_telefon,float salariu, int ani_experienta):Personal_Medical(nume, prenume, varsta, nr_telefon),ani_experienta(ani_experienta)
{
    //this->ani_experienta = ani_experienta;
}
//destructor
Asistent::~Asistent()
{
    if(!this->nume.empty()) this->nume.clear();
    if(!this->prenume.empty()) this->prenume.clear();
    if(!this->nr_telefon.empty()) this->nr_telefon.clear();
}
//constr copiere
Asistent::Asistent(const Asistent& obj)
{
    this->nume = obj.nume;
    this->prenume = obj.prenume;
    this->varsta = obj.varsta;
    this->nr_telefon = obj.nr_telefon;
    this->salariu = obj.salariu;
    this->ani_experienta = obj.ani_experienta;
}
//op copiere
Asistent &Asistent :: operator=(const Asistent& obj)
{
    if(this != &obj)
    {
        Personal_Medical::operator = (obj); ///!!!!!!
        this->ani_experienta = obj.ani_experienta;
    }
    return *this;
}
//istream
istream& operator>>(istream& in, Asistent& obj)
{
    /*
    cout << "Introduceti numele: " << endl;
    in >> obj.nume;

    cout << "Introduceti prenumele: " << endl;
    in >> obj.prenume;

    cout << "Introduceti varsta: " << endl;
    in >> obj.varsta;

    cout << "Introduceti numarul de telefon: " << endl;
    in >> obj.nr_telefon;
    */
    in >> dynamic_cast<Personal_Medical&>(obj);
    cout << "Introduceti numarul de ani experienta: " << endl;
    in >> obj.ani_experienta;

    return in;

}
//ostream
ostream& operator<<(ostream& out,const Asistent& obj )
{
    //out << "Nume: " << obj.nume << endl;
    //out << "Prenume: " << obj.prenume << endl;
    //out << "Varsta: " << obj.varsta << endl;
    //out << "Numar de telefon: " << obj.nr_telefon << endl;
    out << dynamic_cast<const Personal_Medical&>(obj);
    out << "Ani experienta: " << obj.ani_experienta << endl;
    return out;
}

///Clasa Medic

//constructor
Medic::Medic(string nume, string prenume, int varsta,
             string nr_telefon, float salariu, string specializare,  int NIM):Personal_Medical(nume, prenume, varsta, nr_telefon)
{
    this->specializare = specializare;
    this->NIM = NIM;
}
//destr
Medic::~Medic()
{
    if(!this->nume.empty()) this->nume.clear();
    if(!this->prenume.empty()) this->prenume.clear();
    if(!this->nr_telefon.empty()) this->nr_telefon.clear();
    if(!this->specializare.empty()) this->specializare.clear();
}
//constr de  copiere
Medic:: Medic(const Medic& obj):Personal_Medical(obj)
{
    this->specializare = obj.specializare;
}
//operator de copiere
Medic &Medic::operator=(const Medic& obj)
{
    if(this != &obj)
    {
        Personal_Medical::operator = (obj);
        this->specializare = obj.specializare;
    }
    return *this;
}
//istream
istream& operator>>(istream& in, Medic& obj)
{
    cout << "Introduceti numele: " << endl;
    in >> obj.nume;

    cout << "Introduceti prenumele: " << endl;
    in >> obj.prenume;

    cout << "Introduceti varsta: " << endl;
    in >> obj.varsta;

    cout << "Introduceti numarul de telefon: " << endl;
    in >> obj.nr_telefon;

    cout << "Introduceti salariul: " << endl;
    in >> obj.salariu;

    cout << "Introduceti specializarea: " << endl;
    in >> obj.specializare;

    return in;

}
//ostream
ostream& operator<<(ostream& out, const Medic& obj)
{
    out << "Nume: " << obj.nume << endl;
    out << "Prenume: " << obj.prenume << endl;
    out << "Varsta: " << obj.varsta << endl;
    out << "Numar de telefon: " << obj.nr_telefon << endl;
    out << "Salariu: " << obj.salariu << endl;
    out << "Specializare: " << obj.specializare << endl;
    out << "Numar de identificare medicala: " << obj.NIM << endl;
    return out;
}

///Clasa Chirurg

//constructor
Chirurg::Chirurg(string nume, string prenume, int varsta, string nr_telefon, float salariu, string specializare, int NIM, int nr_interventii): Medic(nume, prenume, varsta, nr_telefon, salariu, specializare, NIM)
{
    this->nr_interventii = nr_interventii;
}
//destructor
Chirurg::~Chirurg()
{
    if(!this->nume.empty()) this->nume.clear();
    if(!this->prenume.empty()) this->prenume.clear();
    if(!this->nr_telefon.empty()) this->nr_telefon.clear();
    if(!this->specializare.empty()) this->specializare.clear();
}
//constr de  copiere
Chirurg::Chirurg(const Chirurg& obj):Medic(obj)
{
    this->nr_interventii = obj.nr_interventii;
}
//operator de copiere
Chirurg &Chirurg::operator=(const Chirurg& obj)
{
    if(this != &obj)
    {
        Medic::operator = (obj);
        this->nr_interventii = obj.nr_interventii;
    }
    return *this;
}
//istream
istream& operator>>(istream& in, Chirurg& obj)
{
    cout << "Introduceti numele: " << endl;
    in >> obj.nume;

    cout << "Introduceti prenumele: " << endl;
    in >> obj.prenume;

    cout << "Introduceti varsta: " << endl;
    in >> obj.varsta;

    cout << "Introduceti numarul de telefon: " << endl;
    in >> obj.nr_telefon;

    cout << "Introduceti salariul: " << endl;
    in >> obj.salariu;

    cout << "Introduceti specializarea: " << endl;
    in >> obj.specializare;

    cout << "Introduceti numarul de interventii: " << endl;
    in >> obj.nr_interventii;

    return in;

}
//ostream
ostream& operator<<(ostream& out, const Chirurg& obj)
{
    out << "Nume: " << obj.nume << endl;
    out << "Prenume: " << obj.prenume << endl;
    out << "Varsta: " << obj.varsta << endl;
    out << "Numar de telefon: " << obj.nr_telefon << endl;
    out << "Salariu: " << obj.salariu << endl;
    out << "Specializare: " << obj.specializare << endl;
    out << "Numar de identificare medicala: " << obj.NIM << endl;
    out << "Numar de interventii: " << obj.nr_interventii << endl;
    return out;
}

///Cardiolog

//constructor
Cardiolog::Cardiolog(string nume, string prenume, int varsta, string nr_telefon, float salariu, string specializare, int NIM, int nr_interventii): Medic(nume, prenume, varsta, nr_telefon, salariu, specializare, NIM)
{
    this->nr_interventii = nr_interventii;
}
//destructor
Cardiolog::~Cardiolog()
{
    if(!this->nume.empty()) this->nume.clear();
    if(!this->prenume.empty()) this->prenume.clear();
    if(!this->nr_telefon.empty()) this->nr_telefon.clear();
    if(!this->specializare.empty()) this->specializare.clear();
}
//constr de  copiere
Cardiolog::Cardiolog(const Cardiolog& obj):Medic(obj)
{
    this->nr_interventii = obj.nr_interventii;
}
//operator de copiere
Cardiolog &Cardiolog::operator=(const Cardiolog& obj)
{
    if(this != &obj)
    {
        Medic::operator = (obj);
        this->nr_interventii = obj.nr_interventii;
    }
    return *this;
}
//istream
istream& operator>>(istream& in, Cardiolog& obj)
{
    cout << "Introduceti numele: " << endl;
    in >> obj.nume;

    cout << "Introduceti prenumele: " << endl;
    in >> obj.prenume;

    cout << "Introduceti varsta: " << endl;
    in >> obj.varsta;

    cout << "Introduceti numarul de telefon: " << endl;
    in >> obj.nr_telefon;

    cout << "Introduceti salariu: " << endl;
    in >> obj.salariu;

    cout << "Introduceti specializarea: " << endl;
    in >> obj.specializare;

    cout << "Introduceti numarul de interventii: " << endl;
    in >> obj.nr_interventii;

    return in;

}
//ostream
ostream& operator<<(ostream& out, const Cardiolog& obj)
{
    out << "Nume: " << obj.nume << endl;
    out << "Prenume: " << obj.prenume << endl;
    out << "Varsta: " << obj.varsta << endl;
    out << "Numar de telefon: " << obj.nr_telefon << endl;
    out << "Salariu: " << obj.salariu << endl;
    out << "Specializare: " << obj.specializare << endl;
    out << "Numar de identificare medicala: " << obj.NIM << endl;
    out << "Numar de interventii: " << obj.nr_interventii << endl;
    return out;
}
///functie template
template <typename T, typename U>
T Meniu::suma(T (U::*membru)() const) {
    T sum = 0;
    for (auto p : personalMedicalVector) {
        sum += (static_cast<U*>(p)->*membru)();
    }
    return sum;
}


///Meniu
void Meniu::afiseazaMeniu() const
{
    cout << "                     BAZA DE DATE A PERSONALULUI MEDICAL\n\n";
    cout << "-Meniu-\n";
    cout << "1 -> Adauga un nou angajat - Personal Medical\n";
    cout << "2 -> Afiseaza detalii angajati\n";
    cout << "3 -> Modifica angajat - Personal Medical\n";
    cout << "4 -> Afisare buget de salarii." << endl;
    cout << "5 -> Afisare numar de interventii per spital." << endl;
    cout << "0 -> Inchide aplicatia\n";
    cout << endl << endl;

}

vector<Personal_Medical*> Meniu::personalMedicalVector;

void Meniu::startMeniu()
{
    this->afiseazaMeniu();
    while(true)
    {
        int option;
        cout << "\nIntroduceti optiune:\n";
        cin >> option;
        cin.get();
        try
        {
            switch(option)
            {
            case 0:
            {
                return;
            }
            case 1:
            {
                int tipPersonal;
                cout << "Selectati tipul de personal (1 - Asistent, 2 - Medic, 3 - Chirurg, 4 - Cardiolog): ";
                cin >> tipPersonal;
                // vector <Personal_Medical*> PersonalMedicalVector;
                vector <Personal_Medical*>& PersonalMedicalVector = Meniu::getPersonalMedicalVector();

                switch (tipPersonal)
                {
                case 1:
                    PersonalMedicalVector.push_back(new Asistent());
                    cin >> *dynamic_cast<Asistent*>(PersonalMedicalVector.back());
                    cout << endl << "INFORMATII ADAUGATE\n";
                    cout << *dynamic_cast<Asistent*>(PersonalMedicalVector.back());

                    break;
                case 2:
                    PersonalMedicalVector.push_back(new Medic());
                    cin >> *dynamic_cast<Medic*>(PersonalMedicalVector.back());
                    cout << endl << "INFORMATII ADAUGATE\n";
                    cout << *dynamic_cast<Medic*>(PersonalMedicalVector.back());
                    break;
                case 3:
                    PersonalMedicalVector.push_back(new Chirurg());
                    cin >> *dynamic_cast<Chirurg*>(PersonalMedicalVector.back());
                    cout << endl << "INFORMATII ADAUGATE\n";
                    cout << *dynamic_cast<Chirurg*>(PersonalMedicalVector.back());
                    break;
                case 4:
                    PersonalMedicalVector.push_back(new Cardiolog());
                    cin >> *dynamic_cast<Cardiolog*>(PersonalMedicalVector.back());
                    cout << endl << "INFORMATII ADAUGATE\n";
                    cout << *dynamic_cast<Cardiolog*>(PersonalMedicalVector.back());
                    break;
                default:
                    cout << "Tip de personal invalid.\n";
                    continue;
                }
                cout << "\n~Pernoal medical adaugat cu succes.~\n";
                break;
            }

            case 2:
            {
                cout << "1 -> Afisati toti angajatii." << endl;
                cout << "2 -> Afisati asistenti." << endl;
                cout << "3 -> Afisati medici." << endl;
                cout << "4 -> Afisati chirurgi." << endl;
                cout << "5 -> Afisati cardiologi." << endl;
                int tipPersonal;
                cout << "Introduceti optiune: ";
                cin >> tipPersonal;
                switch(tipPersonal)
                {
                case 1:
                {
                    for(auto p = personalMedicalVector.begin(); p != personalMedicalVector.end(); p++)
                    {
                        cout << *(*p) << endl;
                    }
                    break;

                }
                case 2: //asistenti
                {
                    vector <Personal_Medical*>& PersonalMedicalVector = Meniu::getPersonalMedicalVector();
                    for (auto p : PersonalMedicalVector)
                    {
                        if (typeid(*p) == typeid(Asistent))
                        {
                            Asistent* asistentPtr = dynamic_cast<Asistent*>(p);
                            if (asistentPtr != nullptr)
                            {
                                cout << *asistentPtr << endl;
                            }
                        }
                    }
                    break;
                }
                case 3: // medici
                {
                    vector <Personal_Medical*>& PersonalMedicalVector = Meniu::getPersonalMedicalVector();
                    for (auto p : PersonalMedicalVector)
                    {
                        if (typeid(*p) == typeid(Medic))
                        {
                            Medic* medicPtr = dynamic_cast<Medic*>(p);
                            if (medicPtr != nullptr)
                            {
                                cout << *medicPtr << endl;
                            }
                        }
                    }
                    break;
                }
                case 4: // chirurgi
                {
                    vector <Personal_Medical*>& PersonalMedicalVector = Meniu::getPersonalMedicalVector();
                    for (auto p : PersonalMedicalVector)
                    {
                        if (typeid(*p) == typeid(Chirurg))
                        {
                            Chirurg* chirurgPtr = dynamic_cast<Chirurg*>(p);
                            if (chirurgPtr != nullptr)
                            {
                                cout << *chirurgPtr << endl;
                            }
                        }
                    }
                    break;
                }
                case 5: // cardiologi
                {
                    vector <Personal_Medical*>& PersonalMedicalVector = Meniu::getPersonalMedicalVector();
                    for (auto p : PersonalMedicalVector)
                    {
                        if (typeid(*p) == typeid(Cardiolog))
                        {
                            Cardiolog* cardiologPtr = dynamic_cast<Cardiolog*>(p);
                            if (cardiologPtr != nullptr)
                            {
                                cout << *cardiologPtr << endl;
                            }
                        }
                    }
                    break;
                }
                }
                break;
            }
            case 3:
            {
                cout << "MODIFICARE DATE\n";
                string nume1, prenume1;
                cout << "Introduceti numele angajatului: " << endl;
                cin >> nume1;
                cout << "Introduceti prenumele angajatului: " << endl;
                cin >> prenume1;
                for(auto p:personalMedicalVector)
                {
                    if(p->getNume() == nume1 && p->getPrenume() == prenume1)
                    {
                        p->modifica();
                        cout << "Angajat modificat cu succes.\n";
                        break;
                    }
                    else
                    {
                        cout << "Angajatul nu a fost gasit.\n";
                    }
                }
                break;
            }
            case 4:
            {
                float sumaSalarii = Meniu::suma<float, Personal_Medical>(&Personal_Medical::getSalariu);
                cout << "Bugetul total de salarii pentru personalul medical este: ";
                cout << sumaSalarii << endl;
                break;
            }
            case 5:
            {
                int sumaInterventii1 = Meniu::suma<int, Chirurg>(&Chirurg::getNr_interventii);
                int sumaInterventii2 = Meniu::suma<int, Cardiolog>(&Cardiolog::getNr_interventii);
                cout << "Suma numarului de interventii: " << sumaInterventii1 + sumaInterventii2<< endl;
                break;
            }
            default:
                throw OptiuneInvalida();
            }
        }
        catch(OptiuneInvalida& e)
        {
            cout<<e.what()<<endl;
        }
    }
}

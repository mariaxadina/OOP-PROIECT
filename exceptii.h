#ifndef EXCEPTII_H_INCLUDED
#define EXCEPTII_H_INCLUDED

class OptiuneInvalida : public exception{
public:
    const char* what() const throw(){
        return "Optiune invalida!";
    }
};

class VarstaInvalidaException : public std::exception
{
public:
    const char* what() const noexcept override {
        return "Varsta invalida - Personalul medical are varsta minima de 20 ani.";
    }
};

class NumarTelefonInvalidException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Numarul este invalid - Acesta trebuie sa contina 10 cifre.";
    }
};


#endif // EXCEPTII_H_INCLUDED

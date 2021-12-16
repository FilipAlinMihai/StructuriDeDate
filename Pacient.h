#ifndef PACIENT_H
#define PACIENT_H
#include <string>
#include <iostream>
using namespace std;
class Pacient
{
    private:
        int cod;
        string nume;
        int varsta;
        string numeMedic;
    public:
        Pacient(int,string,int,string);
        Pacient(const Pacient&);
        Pacient();
        virtual ~Pacient();
        int getCod();
        int getVarsta();
        string getNume();
        string getNumeM();
        void setCod(int);
        void setNume(string);
        void setNumeM(string);
        void setVarsta(int);
        Pacient& operator=(const Pacient&);
        friend ostream & operator << (ostream &, const Pacient &);
        string toString();
    protected:


};

#endif // PACIENT_H

#ifndef CONSULTATIE_H
#define CONSULTATIE_H
#include "Pacient.h"
#include <string>
#include <iostream>
using namespace std;

class Consultatie
{
    private:
        int ID;
        string numeM;
        Pacient pacient;
        string data;
    public:

        Consultatie(int,string ,Pacient ,string);
        Consultatie(const Consultatie&);
        virtual ~Consultatie();
        int getID();
        string getNumeM();
        string getData();
        Pacient getPacient();
        void setID(int);
        void setNumeM(string);
        void setData(string);
        void setPacient(Pacient);
        Consultatie& operator=(const Consultatie&);
        friend ostream & operator << (ostream &, const Consultatie &);
};

#endif // CONSULTATIE_H

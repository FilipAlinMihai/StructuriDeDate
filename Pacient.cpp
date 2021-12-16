#include "Pacient.h"
using namespace std;
Pacient::Pacient(int cod,string nume,int varsta,string numeMedic)
{
        this->cod=cod;
        this->nume=nume;
        this->numeMedic=numeMedic;
        this->varsta=varsta;
}
Pacient::Pacient(const Pacient &x)
{
    this->cod=x.cod;
    this->nume=x.nume;
    this->numeMedic=x.numeMedic;
    this->varsta=x.varsta;
}
Pacient::Pacient()
{

}
Pacient::~Pacient()
{

}

ostream & operator << (ostream &st, const Pacient &x)
{
     st <<"Codul pacientului "<<x.nume<<" este "<<x.cod<<" el are "<<x.varsta
     <<" ani si e tratat de medicul "<<x.numeMedic<<endl;
    return st;
}

int Pacient::getCod()
{
    return this->cod;
}
string Pacient::getNumeM()
{
    return this->numeMedic;
}
string Pacient::getNume()
{
    return this->nume;
}
int Pacient::getVarsta()
{
    return this->varsta;
}
void Pacient::setCod(int x)
{
    this->cod=x;
}
void Pacient::setNume(string x)
{
    this->nume=x;
}
void Pacient::setNumeM(string x)
{
    this->numeMedic=x;
}
void Pacient::setVarsta(int x)
{
    this->varsta=x;
}
Pacient& Pacient::operator=(const Pacient&x)
{
    this->cod=x.cod;
    this->nume=x.nume;
    this->numeMedic=x.numeMedic;
    this->varsta=x.varsta;
    return *this;
}

string Pacient::toString()
{
    return to_string(this->cod)+","+this->nume+","+to_string(this->varsta)+","+this->numeMedic+"\n";
}

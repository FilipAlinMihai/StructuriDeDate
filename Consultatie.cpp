#include "Consultatie.h"
using namespace std;
Consultatie::Consultatie(int a,string b,Pacient c,string d)
{
   this->ID=a;
   this->numeM=b;
   this->pacient=c;
   this->data=d;
}

Consultatie::~Consultatie()
{
    //dtor
}
Consultatie::Consultatie(const Consultatie& x)
{
    this->ID=x.ID;
    this->numeM=x.numeM;
    this->pacient=x.pacient;
    this->data=x.data;
}

int Consultatie::getID()
{
    return this->ID;
}
string Consultatie::getNumeM()
{
    return this->numeM;
}
string Consultatie::getData()
{
    return this->data;
}
Pacient Consultatie::getPacient()
{
    return this->pacient;
}

void Consultatie::setID(int x)
{
    this->ID=x;
}
void Consultatie::setNumeM(string x)
{
    this->numeM=x;
}
void Consultatie::setData(string x)
{
    this->data=x;
}
void Consultatie::setPacient(Pacient x)
{
    this->pacient=x;
}
Consultatie& Consultatie::operator=(const Consultatie& x)
{
    this->ID=x.ID;
    this->numeM=x.numeM;
    this->data=x.data;
    this->pacient=x.pacient;
    return *this;
}
ostream & operator << (ostream &st, const Consultatie &x)
{
     st <<"Consultatia pacientului  "<<x.pacient.getNume()<<" va avea loc in dadta de "
     <<x.data<<" si va fi realizata de medicul "<<x.numeM<<endl;
    return st;
}

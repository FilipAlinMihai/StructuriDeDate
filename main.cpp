#include <iostream>
#include <string>
#include "Pacient.h"
#include "RBNode.h"
#include <iostream>
#include <fstream>
#include<stdio.h>
#include<bits/stdc++.h>
#include "Consultatie.h"
using namespace std;

void cautare(RBTree* RB)
{
    int k;
    cout<<"Introduceti codul :";
    cin>>k;
    RBNode* n;
    n=RB->root;
    while(n!=RBNode::Nil && n->key.getCod()!=k)
    {
        if(n->key.getCod()>k)
            n=n->left;
        else
            n=n->right;
    }
    if(n!=RBNode::Nil)
        cout<<"Pacientul cu codul "<<k<<" a fost gasit"<<endl;
    else
        cout<<"Pacientul cu codul "<<k<<" nu a fost gasit"<<endl;
}

RBNode* cautareNod(RBTree* RB,int k)
{
    RBNode* n;
    n=RB->root;
    while(n!=RBNode::Nil && n->key.getCod()!=k)
    {
        if(n->key.getCod()>k)
            n=n->left;
        else
            n=n->right;
    }
    if(n!=RBNode::Nil)
        return n;
    else
        return NULL;
}

bool validare(int cod,RBTree* RB)
{
    RBNode* n;
    n=RB->root;
    while(n!=RBNode::Nil && n->key.getCod()!=cod)
    {
        if(n->key.getCod()>cod)
            n=n->left;
        else
            n=n->right;
    }
    if(n!=RBNode::Nil)
        return false;

    return true;
}

void inserareRB(RBTree* RB)
{
    cout<<"Introduceti datele pacientului \nCod:";
    int cod,v;
    string nume,med;

    cin>>cod;
    if(validare(cod,RB))
    {
        cout<<"Nume: ";
        cin.get();
        getline(cin,nume);
        cout<<"Varsta: ";
        cin>>v;
        cin.get();
        cout<<"Numele Medicului: ";
        getline(cin,med);
        Pacient t(cod,nume,v,med);
        RB->RBInsert(RB->createNode(t));
    }
    else
        cout<<"Codul este deja utilizat"<<endl;
}

void citirefisier(RBTree* RB)
{
    string linie,nume,numeM,cod,varsta;
    ifstream Fisier("Pacienti.csv");
    int c,v;
    while(getline(Fisier,linie))
    {
        stringstream linie1(linie);
        getline(linie1,cod,',');
        getline(linie1,nume,',');
        getline(linie1,varsta,',');
        getline(linie1,numeM,',');
        c=stoi(cod);
        v=stoi(varsta);
        Pacient p(c,nume,v,numeM);
        RB->RBInsert(RB->createNode(p));
    }
    Fisier.close();
}
void parcurgere(RBNode* x)
{

    if(x!=RBNode::Nil)
    {
        parcurgere(x->left);
        cout<<x->key;
        parcurgere(x->right);
    }

}

void meniu(RBTree*);

void scriere(RBNode* root)
{
    stack<RBNode *> s;
    RBNode *curr = root;
    ofstream Fisier("Pacienti.csv");

    while (curr != RBNode::Nil || s.empty() == false)
    {
        while (curr != RBNode::Nil)
        {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();

        Fisier<< curr->key.toString();

        curr = curr->right;

    }
    Fisier.close();
}

void modificare(RBTree* RB)
{
    cout<<"Introduceti codul pacieltului : ";
    int k;
    cin>>k;
    RBNode* n;
    n=RB->root;
    while(n!=RBNode::Nil && n->key.getCod()!=k)
    {
        if(n->key.getCod()>k)
            n=n->left;
        else
            n=n->right;
    }
    if(n!=RBNode::Nil)
        {
            cout<<"Ce doriti sa modificati (1-cod 2-nume 3-varsta 4-numele medicului) : ";
            int m;
            cin>>m;
            switch (m){
                case 1:
                {
                    cout<<"Introduceti codul nou : ";
                    int codnou;
                    cin>>codnou;
                    n->key.setCod(codnou);
                    break;
                }
                case 2:
                {
                    cout<<"Introduceti noul nume : ";
                    string nume;
                    cin.get();
                    getline(cin,nume);
                    n->key.setNume(nume);
                    break;
                }
                case 3:
                {
                    cout<<"Introduceti noua varsta : ";
                    int varsta;
                    cin>>varsta;
                    n->key.setVarsta(varsta);
                    break;
                }
                case 4:
                {
                    cout<<"Introduceti numele medicului : ";
                    string numeM;
                    cin.get();
                    getline(cin,numeM);
                    n->key.setNumeM(numeM);
                    break;
                }
            }
            cout<<"Au fost modificate datele pacientului "<<n->key.getCod()<<endl;
        }
    else
        cout<<"Nu am gasit pacientul!"<<endl;
}

string numarMaxPacienti(RBTree* RB)
{
    map<string, int> aparitii;

    stack<RBNode *> s;
    RBNode *curr = RB->root;

    while (curr != RBNode::Nil || s.empty() == false)
    {
        while (curr != RBNode::Nil)
        {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();
        string nume;
        nume=curr->key.getNumeM();
        if(aparitii.count(nume))
        {
            int numar;
            numar=aparitii[nume];
            aparitii.insert({nume,numar});
        }
        else
            aparitii.insert({nume,1});

        curr = curr->right;

    }

    int maxim=0;
    string doctor;
    for(auto i:aparitii)
        if(i.second>maxim)
        {
            maxim=i.second;
            doctor=i.first;
        }
    return doctor;
}
void actiune(int o,RBTree* RB)
{
    switch (o) {

    case 1:
        {
            inserareRB(RB);
            scriere(RB->root);
            meniu(RB);
            break;
        }
    case 2:
        {
            cautare(RB);
            meniu(RB);
            break;
        }
    case 3:
        {
            int cod;
            cout<<"Introduceti codul pacientului : ";
            cin>>cod;
            RBNode* n=cautareNod(RB,cod);
            if(n!=NULL)
            {
                RB->del(n);
                cout<<"Nodul a fost sters."<<endl;
            }
            else
                cout<<"Nodul nu a fost gasit."<<endl;
            scriere(RB->root);
            meniu(RB);
            break;
        }
    case 4:
        {
            modificare(RB);
            scriere(RB->root);
            meniu(RB);
            break;
        }
    case 5:
        {
            parcurgere(RB->root);
            meniu(RB);
            break;
        }
    case 6:
        {

            cout<<numarMaxPacienti(RB)<<endl;
            break;
        }
    case 7:
        {

            break;
        }
    }
}
void meniu(RBTree* RB)
{
    int optiune;
    cout<<"1--Adauga un pacient"<<endl;
    cout<<"2--Cauta un pacient"<<endl;
    cout<<"3--Sterge un pacient"<<endl;
    cout<<"4--Modificati un pacient"<<endl;
    cout<<"5--Afisarea Pacientilor"<<endl;
    cout<<"6--Medicul cu programul cel mai incarcat"<<endl;
    cout<<"7--Iesire"<<endl;
    cout<<"Introduceti optiunea dorita (1-7) : ";
    cin>>optiune;
    if(optiune<1 || optiune>7)
        cout<<"Optiunea nu a fost recunoscuta . Incercati un numar intre 1 si 7 ";
    else
        actiune(optiune,RB);

}
int main()
{

    RBTree* RB = new RBTree();


    citirefisier(RB);
     meniu(RB);
    scriere(RB->root);

    return 0;
}

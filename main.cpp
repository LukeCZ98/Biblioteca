#include <iostream>
#include <string>
#include "biblioteca.h"
using namespace std;

void printmenu();

int main(){
    unsigned chase=99;
    Biblioteca b1;
    while(chase!=8){
        printmenu();
        cin>>chase; cout<<"\n";
        switch (chase)
        {
        case 0:
            b1.AggiungiLibro();
            break;
        case 1:
            b1.RimuoviLibro();
            break;
        case 2:  
            b1.AggiungiCliente();    
            break;
        case 3:
            b1.RimuoviCliente();
            break;
        case 4:
            b1.Prestito();
            break;
        case 5:
            b1.Riconsegna();
            break;
        case 6:
            b1.printlibrprest();
            break;
        case 7:
            b1.printlibprestclient();
        case 8:
            break;
        case 9:
            b1.CercaLibro();
            break;
        case 10:
            b1.CercaCliente();
            break;
        }
    }
    return 0;
}

void printmenu()
{
  cout<<"Scegli la funzione:"<<endl;
  cout<<"\t"<<"0 – Inserisci un libro"<<endl;
  cout<<"\t"<<"1 – Rimuovi un libro"<<endl;
  cout<<"\t"<<"2 – Inserisci un cliente"<<endl;
  cout<<"\t"<<"3 – Rimuovi un cliente"<<endl;
  cout<<"\t"<<"4 – Inserisci un prestito"<<endl;
  cout<<"\t"<<"5 – Consegna un libro"<<endl;
  cout<<"\t"<<"6 – Stampa i libri in prestito"<<endl;
  cout<<"\t"<<"7 – Stampa i clienti che hanno un libro in prestito"<<endl;
  cout<<"\t"<<"8 – Termina il programma"<<endl;
  cout<<"\t"<<"9 – Cerca un libro"<<endl;
  cout<<"\t"<<"10 – Cerca un cliente"<<endl;
  cout<<"Inserisci : ";
}
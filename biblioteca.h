#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream>
#include <string>
#include <vector>
#include "libri.h"
#include "clienti.h"
using namespace std;

class Biblioteca{
  private:
    vector<Libri> lista;
    vector<clienti> elenco;
  public:
    Biblioteca(){}
    
    int findbookbystr(string nome)
    {
          for(int i=0;i<lista.size();i++)
          {
            if(lista[i].Gettitolo()==nome){
              return i;
            }
          }
          return -1;
    }


    int findbookbycod(int codice)
      {        
          for(int i=0;i<lista.size();i++)
          {
            if(lista[i].Getcod()==codice){
              return i;
            }
          }
          return -1;
      }
    
    int findclibycod(int codice)
      {        
          for(int i=0;i<lista.size();i++)
          {
            if(elenco[i].Getcod()==codice){
              return i;
            }
          }
          return -1;
      }
    
    void CercaLibro()
      {
        unsigned chase,cod,index;
        string nome;
        cout<<"Vuoi cercare il libro per nome(0) o per codice(1)? ";
        cin>>chase;
        if(chase == 0){
          cout<<"Inserisci nome libro: "; cin>>nome; cout<<"\n";
          if(findbookbystr(nome)==-1){
            cout<<"Il libro cercato non esiste"<<endl;
          }
          else{
            index=findbookbystr(nome);
            cout<<lista[index];
            cout<<"Stato: ";
            if(lista[index].getdisp()) 
            {
              cout<<"Disponibile"<<endl; cout<<"\n";
            }
            else{
              cout<<"In prestito"<<endl; cout<<"\n";
            }
          }
        }
        else if(chase == 1){
          cout<<"Inserisci codice libro: "; cin>>cod;
          if(findbookbycod(cod)==-1){
            cout<<"Il libro cercato non esiste"<<endl;
          }
          else{
            index=findbookbycod(cod);
            cout<<lista[index];
            cout<<"Stato: ";
            if(lista[index].getdisp()) 
            {
              cout<<"Disponibile"<<endl; cout<<"\n";
            }
            else{
              cout<<"In prestito"<<endl; cout<<"\n";
            }
          }
        }
        
      }

    void printlibprestclient()
    {
      int indlibro=0;
      cout<<"Clienti momentaneamente con un prestito"<<endl;
      for(int i=0;i<elenco.size();i++)
        {
          if(elenco[i].GetPrestito()){
            indlibro=findbookbycod(elenco[i].Getcodlibro());
            cout<<elenco[i];
            cout<<"Ha in prestito: \n"<<lista[indlibro]<<endl;
           }
        }
    }
    
    void printlibrprest()
    {
        int indcli=0;
        cout<<"Libri momentaneamente in prestito"<<endl;
        for(int i=0;i<lista.size();i++)
          {
            if(lista[i].getdisp()==false){
              indcli=findclibycod(lista[i].Getcodcl());
              cout<<lista[i];
              cout<<"E' in prestito a: \n"<<elenco[indcli]<<endl;
            }
          }
    }

    void printclienti()
    {
      for(int i=0;i<elenco.size();i++)
      {
        cout<<elenco[i];
      }
    }
    
    void AggiungiCliente()
    {       
      clienti client;
      cin>>client;
      elenco.push_back(client);
    }
    
    void RimuoviCliente()
    {
      if(elenco.size()>0){
      cout<<"Inserisci codice cliente da rimuovere: "; unsigned code; cin>>code;
      for(int i=0;i<elenco.size();i++)
      {
        if(elenco[i].Getcod()==code){
            elenco.erase(elenco.begin()+i);
        }
      }
      }
      else{
        cout<<"Nessun cliente da rimuovere"<<endl;
      }
    }

    void AggiungiLibro()
    {
      Libri libro;
      cin>>libro;
      lista.push_back(libro);
    }
    
    void RimuoviLibro()
    {
      if(lista.size()>0){
      cout<<"Inserisci codice libro da rimuovere: "; unsigned code; cin>>code;
      for(int i=0;i<lista.size();i++)
      {
        if(lista[i].Getcod()==code){
            lista.erase(lista.begin()+i);
        }
      }
      }
      else{cout<<"nessun libro da rimuovere";}
    }
    
    void CercaCliente()
    {
      if(elenco.size()>0)
      {
      unsigned c;
      cout<<"Vuoi cercare il cliente per codice int(0) o per codice fisc(1)? ";
      cin>>c;
      if(c == 0)
      {
        cout<<"Inserisci cod interno cliente: "; unsigned n; cin>>n;
        for(int i=0;i<elenco.size();i++) {if(elenco[i].Getcod()==n){cout<<elenco[i]; break;}}
      }
      else if(c == 1)
      {
        cout<<"Inserisci cod fiscale cliente: "; string cod; cin>>cod;
        for(int i=0;i<elenco.size();i++) {if(elenco[i].Getcodfisc()==cod){cout<<elenco[i]; break;}}
      }
      }
      else{
        cout<<"Nessun cliente da cercare"<<endl;
      }
    }
    
    bool checkcli(clienti cli)
    {
      if(cli.GetPrestito())
        return false;                //se il cliente ha giá un prestito restituisci false
      return true;                   //altrimenti restituisci true
    }

    bool checkbook(Libri libro)
    {
      if(!libro.getdisp())
        return false;                //se il libro é giá in prestito restituisci false
      return true;                   //altrimenti restituisci false
    }

    void Prestito()
    {
      unsigned codlibro,codcliente;
      cout<<"Inserisci codice libro: "; cin>>codlibro; cout<<"\n"; cout<<"Inserisci codice cliente: "; cin>>codcliente; cout<<"\n";
      for(int i=0;i<elenco.size();i++)
      {
        if(elenco[i].Getcod()==codcliente)
        {
        if(!checkcli(elenco[i])){cout<<"Il cliente ha giá un prestito in corso! "<<endl; break;}
        else
        {
          for(int j=0;j<lista.size();j++)
          {
          if(lista[j].Getcod()==codlibro)
          {
            if(!checkbook(lista[j])){cout<<"Il libro é giá in prestito!"<<endl; break;}
            else{elenco[i].SetPrestito(true); elenco[i].Setcodlibro(codlibro); lista[j].setdisp(false); lista[j].Setcodcl(elenco[i].Getcod()); break; }
          }
          }      
        }
      }
      else{cout<<"Nessun cliente per il codice inserito"<<endl; break;}
      }
    }
    
    void Riconsegna()
    {
      unsigned codlibro,codcliente;
      cout<<"Inserisci codice libro: "; cin>>codlibro; cout<<"\n"; cout<<"Inserisci codice cliente: "; cin>>codcliente; cout<<"\n";
      for(int i=0;i<elenco.size();i++)
      {
        if(elenco[i].Getcod()==codcliente)
        {
        if(checkcli(elenco[i])){cout<<"Il cliente non ha nessun prestito in corso! "<<endl; break;}
        else
        {
          for(int j=0;j<lista.size();j++)
          {
          if(lista[j].Getcod()==codlibro)
          {
            if(checkbook(lista[j])){cout<<"Il libro non é in prestito!"<<endl; break;}
            else{elenco[i].SetPrestito(false); elenco[i].Setcodlibro(0); lista[j].setdisp(true); lista[j].Setcodcl(0); break; }
          }
          }      
        }
      }
      else{cout<<"Nessun cliente per il codice inserito"<<endl; break;}
      }
    }


};

#endif
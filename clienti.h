#ifndef CLIENTI_H
#define CLIENTI_H

#include<iostream>
#include<string>
using namespace std;

class clienti{
    friend istream& operator>>(istream& in, clienti& client)
    {
     cout<<"Inserisci codice cliente: "; unsigned codice; in>>codice; client.Setcod(codice); cout<<"\n";
     cout<<"Inserisci nome cliente: "; string nome; in>>nome; client.SetNome(nome); cout<<"\n";
     cout<<"Inserisci cognome cliente: "; string cognome; in>>cognome; client.SetCognome(cognome); cout<<"\n"; 
     cout<<"Inserisci cod fiscale cliente: "; string codfiscale; in>>codfiscale; client.Setcodfisc(codfiscale); cout<<"\n";
     client.SetPrestito(false);
     return in;
    }
    
    friend ostream& operator<<(ostream& out, clienti& client)
    {
      out<<"codice cliente: "<<client.Getcod()<<endl;
      out<<"nome cliente: "<<client.GetNome()<<endl;
      out<<"cognome cliente: "<<client.GetCognome()<<endl;
      out<<"cod fiscale cliente: "<<client.Getcodfisc()<<endl;
      return out;
    }

    private:
        unsigned codice;
        string nome;
        string cognome;
        string codfiscale;
        bool prestito;
        unsigned codlibro;
     
    public:
      clienti(){}
  
      bool GetPrestito()
      {
        return prestito;
      }

      void SetPrestito(bool pres)
      {
        prestito=pres;
      }
      
      string GetNome()
      {
        return nome;
      }
      
      void SetNome(string name)
      {
        nome=name;
      }

      string GetCognome()
      {
        return cognome;
      }
      
      void SetCognome(string cog)
      {
        cognome=cog;
      }

      string Getcodfisc()
      {
        return codfiscale;
      }

      void Setcodfisc(string cod)
      {
        codfiscale=cod;
      }
      
      unsigned Getcod()
      {
        return codice;
      }
      
      void Setcod(unsigned codi)
      {
        codice=codi;
      }
      
      unsigned Getcodlibro()
      {
        return codlibro;
      }
      
      void Setcodlibro(unsigned codic)
      {
        codlibro=codic;
      }
      
};
#endif

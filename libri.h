#ifndef LIBRI_H
#define LIBRI_H

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Libri{
  friend istream& operator>>(istream& in, Libri& libro)
    {
     cout<<"Inserisci codice libro: "; unsigned codice; in>>codice; libro.Setcod(codice); cout<<"\n";
     cout<<"Inserisci titolo libro: "; string nome; in>>nome; libro.Settitolo(nome); cout<<"\n";
     cout<<"Inserisci casa editrice: "; string cased; in>>cased; libro.Setcasaed(cased); cout<<"\n"; 
     cout<<"Inserisci numero autori: "; unsigned n; in>>n; libro.Setnaut(n); cout<<"\n";
     for(int i=0;i<libro.Getnaut();i++){string aut; cout<<"Autore "<<i+1<<": "; cin>>aut; libro.Setaut(aut); }
     libro.setdisp(true);
     return in;
    }
    
    friend ostream& operator<<(ostream& out, Libri& libro)
    {
      out<<"codice libro: "<<libro.Getcod()<<endl;
      out<<"titolo libro: "<<libro.Gettitolo()<<endl;
      out<<"casa editrice: "<<libro.Getcasaed()<<endl;
      out<<"autori: "; libro.Getaut();
      return out;
    }

  private:
        unsigned codice;
        unsigned n_aut=0; 
        string titolo;
        vector<string> autori;
        string casaed;
        bool disponibile=true;
        unsigned codclient;
    public:
      Libri(){}
      
      void setdisp(bool c)
      {
        disponibile=c;
      }

      bool getdisp()
      {
        return disponibile;
      }

      unsigned Getcod()
      {
        return codice;
      }
      
      void Setcod(unsigned cod)
      {
       codice=cod;
      }
      
      string Gettitolo()
      {
        return titolo;
      }
      
      void Settitolo(string name)
      {
        titolo=name;
      }
      
      string Getcasaed()
      {
        return casaed;
      }
      
      void Setcasaed(string name)
      {
        casaed=name;
      }
      
      unsigned Getnaut()
      {
        return n_aut;
      }
      
      void Setnaut(unsigned n)
      {
        n_aut=n;
      }
      
      void Getaut()
      {
        for(int i=0;i<autori.size();i++)
        {
          cout<<autori[i];
          if(i<autori.size()-1){cout<<", ";}
        }
        cout<<"\n";
      }
      
      void Setaut(string aut)
      {
        autori.push_back(aut);
      }

      unsigned Getcodcl()
      {
        return codclient;
      }
      
      void Setcodcl(unsigned c)
      {
        codclient=c;
      }
      
    
};

#endif
//conversione Decimale Esadecimale e viceversa

#include <iostream>
#include <unistd.h>
#include <list>
#include <stdlib.h>

using namespace std;

//Lista di tipo string (usata per invertire l'ordine)
list<string> val;

//menu 
void menu(){
  cout << "|-------Inserisci l'operazione da eseguire: -------!";
  cout << "\n";  
  cout << "\n";
  usleep(1000000);

  cout << "1. Conversione Esadecimale --> Decimale \n";
  usleep(500000);
  cout << "2. Conversione Decimale --> Esadecimale \n";
  usleep(500000);
  cout << "e. Esci\n";
  cout << "\n";
  usleep(500000);
}

//conversione decimale --> esadecimale 
list<string> DectoHex(int n){

  while(n>0){
    
    if(n%16<10){
      val.push_front(to_string(n%16));
    }
    else{
      switch(n%16){
        case 10: val.push_front("A");
        break;
        
        case 11: val.push_front("B");
        break;
        
        case 12: val.push_front("C");
        break;
        
        case 13: val.push_front("D");
        break;
        
        case 14: val.push_front("E");
        break;
        
        case 15: val.push_front("F");
        break;
      }
    }
    n= n/16; //n è il numero in decimale
  }
  return(val);
}

//conversione da esadecimale a decimale
 int hexToDec(string val) 
 { 
     int len = val.size();  //len prende la grandezza della stringa
   
     int base = 1; 

      int i;
      int dec = 0; //valore convertito in decimale

   //per i numeri 
     for ( i = len; i >= 0; i--) {  //parte dalla fine ed esegue fino al al carattere in posizione 0
         if (val[i] >= '0' && val[i] <= '9') { 
             dec += (val[i]-48)  * base;  //val[i] - 48 (sposta nella tabella Ascii perche sono caratteri e non numeri)
             base = base * 16; 
         } 

       //per i caratteri
        switch(val[i]){
          case 'a':
          case 'A': dec += 10 * base;
            base = base * 16;
          break;
          case 'b':
          case 'B': dec += 11 * base;
            base = base * 16;
          break;
          case 'c':
          case 'C': dec += 12 * base;
            base = base * 16;
          break;
          case 'd':
          case 'D': dec += 13 * base;
            base = base * 16;
          break;
          case 'e':
          case 'E': dec += 14 * base;
            base = base * 16;
          break;
          case 'f':
          case 'F': dec += 15 * base;
            base = base * 16;
          break;
        }
     } 
     return (dec); 
 } 

//funzione di uscita
void exit(){
  cout << "chiusura in corso...\n";
  usleep(1000000); //funzione di pausa
  cout << "Arrivederci! ";
}

int main() {
  char x; //variabile per la scelta dell'opzione

  menu(); //richiamo menu

  //lettura sicura
  do{
    cout << "-> ";
    cin >> x;
    if(x !='1' && x != '2' && x!='e'){
      cout << "Operazione selezionata non valida, riprova: \n";
    }
  }
    while(x<'1' || x>'2' && x !='e');

  //opzione 2 (conversione da decimale a esadecimale)
  if(x=='2'){
  int a; //numero da convertire
  cout<< "inserisci il numero da convertire: ";
  cin >> a;
  DectoHex(a); //richiamo funzione 

  //scrittura della lista
  for(auto i:val){
    cout << i;
  }
  }

    //opzione 1 (conversione da esadecimale a decimale)
  else if(x=='1'){
    string b; //numero da convertire
    cout << "inserisci il numero da convertire: ";
    cin >> b;
    cout << hexToDec(b); //richiamo funzione
  }

    //uscita 
  else{
    exit(); //richiamo funzione di uscita 
  }
    }
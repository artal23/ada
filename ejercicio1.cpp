#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int resuelve(int vagones[], int nVagones){
  return rand()%100;
}


int main() {
  int nCasos, nVagones;
  int vagones[52];
  
  // LA LECTURA DE LA ENTRADA DEL PROBLEMA
  cin >> nCasos;
  for(int caso{0}; caso<nCasos; caso++){
    cin >> nVagones;
    
    for(int i{0}; i<nVagones; i++){
      cin >> vagones[i];
    }

    int resultado = resuelve(vagones, nVagones);

    cout << "La mejor cantidad de swaps de trenes es "<<resultado<<" swaps." << endl;

  }
}


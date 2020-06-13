#include <stdlib.h>
#include <time.h>
#include<iostream>
#include <ctime>

clock_t t0, t1;
using namespace std;

void burbuja(int arr[],int n){
	t0 = clock();
	int asignacion=0;
	int comparacion=0;
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for (j=n-1;j>=i+1;j--){
        	comparacion++;
            if(arr[j]>arr[j-1]){
                temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
                asignacion+=3;
            }
        }
    }
    t1 = clock();
    double tiempo = (double)(t1-t0) / CLOCKS_PER_SEC;
    cout << "Tiempo de burbuja: " << tiempo << endl;
    cout << "Comparaciones: "<<comparacion<<endl;
    cout << "Asignaciones:  "<<asignacion<<endl;
    cout << "Costo: "<<comparacion+asignacion<<endl;
}


void insercion(int arr[], int arr_size){
  t0 = clock();
  int asignacion=0;
  int comparacion=0;
  if(arr_size > 1){
    int size = arr_size;
    for(int i = 1; i < size; ++i){
      int j = i - 1;
      int key = arr[i];
      comparacion++;
      asignacion+=2;
      while(j >= 0 && arr[j] < key){
        arr[j+1] = arr[j];
        --j;
        asignacion+=2;
      }
      arr[j+1] = key;
      asignacion++;
    }
  }
  t1 = clock();
  double tiempo = (double)(t1-t0) / CLOCKS_PER_SEC;
  cout << "Tiempo de insercion: " << tiempo << endl;
  cout << "Comparaciones: "<<comparacion<<endl;
  cout << "Asignaciones:  "<<asignacion<<endl;
  cout << "Costo: "<<comparacion+asignacion<<endl;
}

void generador(int lista[],int aux[],int tam){
	for (int i = 0; i < tam; ++i)
	{
		lista[i]= 1 + rand() % (tam*2 - 1);
		aux[i]=lista[i];
	}
}



int main()
{

    int num, i;
    int A[6]={500,1000,2000,5000,10000,20000};
    int tam;
    int *l = new int[tam];
    int *aux = new int[tam];

    for(i=0;i<6;i++){
	tam = A[i];
	generador(l,aux,tam);
        cout << "lista de "<<tam<<" elementos"<<endl;
        burbuja(l,tam);
        insercion(aux,tam);

        cout << "\n-------------------\n\n";
    }
    delete l;
    delete aux;
    return 0;
}


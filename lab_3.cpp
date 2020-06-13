#include <bits/stdc++.h> 
#include <time.h>
#include <ctime>
#include <stdlib.h>

clock_t t0, t1;
using namespace std; 
  
void insertionSort(int arr[], int n)  
{  
    t0=clock();
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
  
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }
    t1 = clock();
    double tiempo = (double)(t1-t0) / CLOCKS_PER_SEC;
    cout<<"tiempo insertSort: "<<tiempo<<endl;  
}  
    
void printArray(int arr[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        cout << arr[i] << " ";  
    cout << endl; 
} 

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    // arrays temporales
    int L[n1], R[n2]; 
  
    // copiar datos en arrays temporales 
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    
    i = 0; 
    j = 0;  
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 

} 
  
void mergeSort(int arr[], int l, int r) 
{
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
   
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    }
} 
void timeMS(int arr[], int l, int r){
	t0=clock();
	mergeSort(arr,l,r);
	t1 = clock();
    	double tiempo = (double)(t1-t0) / CLOCKS_PER_SEC;
    	cout<<"tiempo MergeSort: "<<tiempo<<endl;
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
    int A[15]={100,300,500,1000,2000,4000,5000,6000,7000,8000,9000,10000,11000,12000,13000};
    int tam;
    int *l = new int[tam];
    int *aux = new int[tam];
    
    for(i=0;i<15;i++){
	tam = A[i];
	generador(l,aux,tam);
        cout << "lista de "<<tam<<" elementos"<<endl;
        
	insertionSort(l,tam);
	//printArray(l,tam);
	
	timeMS(l,0,tam-1);
        //printArray(aux,tam);
	
        cout << "\n-------------------\n\n";
    } 
    delete l;
    delete aux;
    return 0;  
}  

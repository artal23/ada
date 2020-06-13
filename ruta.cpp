#include <iostream>
using namespace std;




void suma_m(int A[],int x){
	int aux=A[0];
	int ind1,ind2;
	int pos=0;
	int cont,i,j;
	for(i=0;i<x-1;i++){
		cont=0;
		for(j=i;j<x-1;j++){
			cont+=A[j];
			if(cont > aux)
				aux=cont;
				ind1=i+1;
				ind2=j+2;
		}
			
	}
	if(aux>0){
		cout<<aux<<" La mejor parte de la ruta es entre las calles "<<ind1<<" y "<<ind2<<endl;
	}
	else{
		cout<<"La ruta  no tiene calles interesantes"<<endl;
	}	
}

void sub_ruta(int A[],int tam){
	int aux;
	for (int i = 0; i < tam-1; ++i)
	{	
		cin>>aux;
		A[i]=aux;
	}
}

void rutas(int R){
	int x,tam,i,j;
	int l[R];
	int *A = new int[tam];
	for(i=0; i < R; i++){
		cin>>x;
		l[i]=x;
		tam = x;
		sub_ruta(A,tam);
		suma_m(A,tam);
	}
}


int main(){
	int R;
	cin>>R;
	rutas(R);
}






















/*

sub_rutas(x);
	}
	for(int i=0;i<R;i++){
			cout<<"La mejor parte de la ruta "<<i+1<<" es entre las calles "<<l[i][0]<<" y "<<l[i][1]<<endl;
		//else
		//	cout<<"La ruta "<<i+1<<" no tiene calles interesantes"<<endl;
	}*/

#include <bits/stdc++.h>
using namespace std;

void merge(int *v, int p, int q, int r,int *aux){ //Intercala
	int tam= r-p;
	int i = p; //Cursor 1
	int j = q; //Cursor 2
	int k = 0; //Cursor para aux
	while(i<q && j<r){
		if(v[i] <= v[j])
			aux[k++] = v[i++];
		else
			aux[k++] = v[j++];
	}
	while(i < q) //Dois while para preencher o restante
		aux[k++] = v[i++];
	while(j < r)
		aux[k++] = v[j++];
	for(k=0;k < tam; k++) //transferindo o ordenado p/ o original
		v[p+k] = aux[k];
}
void mergeSort(int *v, int p, int r,int *aux){ //Divide and conquer
	if(p< r-1){
		int meio= (p+r)/2;
		mergeSort(v,p,meio,aux);
		mergeSort(v,meio,r,aux);
		merge(v,p,meio,r,aux); /* intercala */
	}
}

void mergeSort2(int *v, int n){
	int *aux = new int [n];
	mergeSort(v,0,n,aux);
	delete []aux;
}

int main(){
	int n;
	cin >> n;
	int *arr=new int[n];
	
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	
	mergeSort2(arr,n);
	
	for(int i=0;i<n;i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	delete []arr;
	return 0;
}
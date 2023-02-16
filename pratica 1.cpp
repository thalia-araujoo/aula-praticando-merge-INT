#include <stdio.h>
#include <stdlib.h>


//para juntar
void mergeInt(int v[], int i, int meio, int j, int fim, int k, int aux[]){
	if(i <= meio && (j > fim || v[i] < v[j])){
		aux[k] = v[i];
		mergeInt(v, i + 1, meio, j, fim, k + 1, aux);
	}else if(j <= fim){
		aux[k] = v[j];
		mergeInt(v, i, meio, j + 1, fim, k + 1, aux);
	}
}







//função de dividir
void mergeSortInt(int v[], int inicio, int fim, int aux[]){
	int meio = (inicio + fim) / 2;
	
	if(inicio < fim){
		mergeSortInt(v, inicio, meio, aux);
		mergeSortInt(v, meio + 1, fim, aux);
		mergeSortInt(inicio, meio, meio + 1, fim, 0, aux);
		
		for(int l = 0; l < fim - inicio +1; l++){
			v[inicio +l] = aux[l];
		}
	}
}





//função de ordenar
void mergeSort(int v[], int tamanho){
	int *aux = (int *) malloc(sizeof(int) * tamanho); // malloc, é guardar espaço na memoria//
	mergeSortInt(v, 0, tamanho, aux);
	free(aux);
}





int main(){
	int a[] = {10, 7, 1, 4, 9, 3, 8, 0, 5, 6};
	
	int tamanh_vetor = sizeof(a)/sizeof(a[0]);
	mergeSort(a, tamanho_vetor); //o nome da variavel e o tamanho
	for(int i=0; i<tamanho_vetor; i++){
		printf("%d", a[i]);
	}
	

	return 0;
}

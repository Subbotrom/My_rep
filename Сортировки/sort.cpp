#include <iostream>
#include <valarray>

#define N 21

void buble(int *a, int size){
	for(int i = 0; i < size; i++){
		for(int j = 1; j < size-i; j++){
			if(a[j-1]>a[j]){
				std::swap(a[j-1], a[j]);
			}
		}
	}
}

void select(int *a, int size){
	for(int i = 0; i < size; i++){
		int min = i;
		for(int j = i+1; j < size; j++){
			if (a[j] < a[min]){
				min = j;
			}
		}
		std::swap(a[min], a[i]);
	}
}

void insert(int *a, int size){
	for(int i = size-1; i > 0; i--){
		int j = i-1;
		while((j<size-1)&&(a[j]>a[j+1])){
			std::swap(a[j], a[j+1]);
			j++;
		}
	}
}

void merge(int *a, int *b, int *c, int n1, int n2){
	int k=0, i=0, j=0;
	while(i<n1&&j<n2){
		if (a[i]<=b[j]){
			c[k] = a[i];
			i++;
		}
		else{
			c[k] = b[j];
			j++;
		}
		k++;
	}
	for(i; n1-i>0; i++){
		c[k] = a[i];
		k++;
	}
	for(j; n2-j>0; j++){
		c[k] = b[j];
		k++;
	}
}

void merge_sort(int *a, int *res, int size){
	if(size > 1){
		int *r1 = new int[size/2];
		int *r2 = new int[size-size/2];
		merge_sort(a, r1, size/2);
		merge_sort(a + size/2, r2, size-size/2);
		merge(r1, r2, res, size/2, size-size/2);
		delete []r1;
		delete []r2;
	}
	else{
		res[0] = a[0];
	}
}


int main(){
	return 0;
}
#include <iostream>
#include <random>
#include <chrono>

#define N 100000

void rand(int (*arr), unsigned size){
	unsigned seed = 1050;
	std :: default_random_engine rng(seed); 
	std :: uniform_int_distribution<unsigned> dstr (0, 100000);
	for (unsigned counter = size-1; counter != -1; --counter){
			arr[counter] = dstr(rng);
	}
}

void forward_step(int arr [] , unsigned const end_idx, int step, int& flag, int& counter){
    int j = 0;
	while(j+step <= end_idx){
		if(arr[j+step]<arr[j]){
            flag = 1;
			std::swap(arr[j+step], arr[j]);
            counter++;
		}
        j++;
	}
}

void comb_sort(int arr [], unsigned const end_idx, int& counter){
    int step = end_idx/2;
    int flag = 0;
    while(step > 1){
        forward_step(arr, end_idx, step, flag, counter);
        step *= 0.8;
    }
    flag = 1;
    while (flag)
    {
        flag = 0;
        forward_step(arr, end_idx, 1, flag, counter);
    }
    
}

void buble(int *a, int size){
	for(int i = 0; i < size; i++){
		for(int j = 1; j < size-i; j++){
			if(a[j-1]>a[j]){
				std::swap(a[j-1], a[j]);
			}
		}
	}
}

int main(){
    int *a = new int[N];
    int *b = new int[N];
    int c = 0, flag = 0;
    rand(a, N);
    comb_sort(a, N-1, c);
    rand(b, N);
    buble(b, N);
    for(int i = 0; i < N; i++){
        if(a[i] != b[i]){
            flag = -1;
        }
    }
    std::cout << flag << std::endl;
}
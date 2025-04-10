#include <iostream>
#include <random>
#include <chrono>

#define N 50000

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
    int c;
    for (unsigned len = 1000; len < N; len=len + len/40){
        c = 0;
        rand(a, len);
        auto begin = std :: chrono :: steady_clock ::now();
        comb_sort(a, len-1, c);
        auto end = std :: chrono :: steady_clock ::now();
        auto time_span = std :: chrono :: duration_cast<std :: chrono :: milliseconds >(end - begin );

        //for(int i = 0; i < N-1; i++){
        //    std::cout << a[i] << std::endl;
        //}
        std::cout << c << std::endl;
        std::cout << len*(len-1)/2 << std::endl;
        std :: cout << time_span.count() << std :: endl;
        rand(a, len);
        begin = std :: chrono :: steady_clock ::now();
        buble(a, len);
        end = std :: chrono :: steady_clock ::now();
        time_span = std :: chrono :: duration_cast<std :: chrono :: milliseconds >(end - begin );
        std :: cout << time_span.count() << std :: endl;
    }
    delete []a;
    return 0;
}
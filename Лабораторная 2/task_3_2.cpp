#include <iostream>
#include <random>
#include <chrono>
#include <cmath>

#define N 80000

void rand(int (*arr), unsigned size){
	unsigned seed = 1050;
	std :: default_random_engine rng(seed); 
	std :: uniform_int_distribution<unsigned> dstr (0, 100000);
	for (unsigned counter = size-1; counter != -1; --counter){
			arr[counter] = dstr(rng);
	}
}

void insert(int *a, int size, int step, int& c){
	for(int i = size-1; i > 0; i-= step){
		int j = i-1;
		while((j<size-step)&&(a[j]>a[j+step])){
			std::swap(a[j], a[j+step]);
			c++;
			j+= step;
		}
	}
}

void shel_1(int *a, int size, int& c){
	int step = size/2;
	while(step > 1){
		insert(a, size, step, c);
		step *= 0.8;
	}
	insert(a, size, 1, c);
}

void shel_2(int *a, int size, int& c){
	int step, i = 1;
	while(std::pow(2, i)-1 < N){
		step = std::pow(2, i)-1;
		i++;
	}
	while(step > 0){
		insert(a, size, step, c);
		i--;
		step = std::pow(2, i)-1;
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
    int c, flag = 0;
	//rand(a, N);
	//rand(b, N);
	//shel_2(a, N, c);
	//buble(b, N);
	//for(int i = 0; i < N-1; i++){
      //     if(a[i] != b[i]){
		//	flag = -1;
		  // }
        //}
	//std::cout << flag << std::endl;
	for (unsigned len = 1000; len < N; len=len + len/50){
        c = 0;
        rand(a, len);
        auto begin = std :: chrono :: steady_clock ::now();
        shel_2(a, len-1, c);
        auto end = std :: chrono :: steady_clock ::now();
        auto time_span = std :: chrono :: duration_cast<std :: chrono :: milliseconds >(end - begin );

        //for(int i = 0; i < N-1; i++){
        //    std::cout << a[i] << std::endl;
        //}
        std::cout << c << std::endl;
        std :: cout << time_span.count() << std :: endl;
		c = 0;
		rand(a, len);
		begin = std :: chrono :: steady_clock ::now();
		shel_1(a, len-1, c);
		end = std :: chrono :: steady_clock ::now();
        time_span = std :: chrono :: duration_cast<std :: chrono :: milliseconds >(end - begin );
		std::cout << c << std::endl;
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
#include <iostream>

void forward_step(unsigned arr [] , unsigned const begin_idx , unsigned const end_idx){
	for(int j = begin_idx+1; j <= end_idx; j++){
		if(arr[j-1]>arr[j]){
			std::swap(arr[j-1], arr[j]);
		}
	}
}

void backward_step(unsigned arr [] , unsigned const begin_idx , unsigned const end_idx){
    for(int j = end_idx; j > begin_idx; j--){
        std::cout << j  << "j " << std::endl;
		if(arr[j-1]>arr[j]){
			std::swap(arr[j-1], arr[j]);
		}
	}
}

void shaker_sort(unsigned arr [] , unsigned const begin_idx , unsigned const end_idx){
    for(int step = 0; step <= (end_idx-begin_idx)/2; step++){
        forward_step(arr, step, end_idx-begin_idx-step);
        backward_step(arr, step, end_idx-begin_idx-1-step);
    }
}
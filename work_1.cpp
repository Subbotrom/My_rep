#include <iostream>
#include <random>
#include <chrono>
#include <new>
#include <bits/stdc++.h>

#define N 500000

void rand(int (*arr)){
	unsigned seed = 1050;
	std :: default_random_engine rng(seed); 
	std :: uniform_int_distribution<unsigned> dstr (0, 100000);
	for (unsigned counter = N; counter != -1; --counter){
			arr[counter] = dstr(rng);
	}
}

int search(int arr[1000000], int len, int n){
	for(int i = 0; i < len; ++i){
		if(arr[i] == n){
			return 0;
		}
	}
	return -1;
}

int search_a(int arr[N], int (*ref), int len, int n){
	for(int i = 0; i < len; ++i){
		if(arr[i] == n){
			int tmp = ref[i];
			ref[i] = ref[0];
			ref[0] = tmp;
			return 0;
		}
	}
	return -1;
}

int search_b(int arr[N], int (*ref), int len, int n){
	for(int i = 0; i < len; ++i){
		if(arr[i] == n){
			if(i > 0){
				int tmp = ref[i];
				ref[i] = ref[i-1];
				ref[i-1] = tmp;
			}
			return 0;
		}
	}
	return -1;
}

int search_c(int arr[N], int (*ref), int (&m)[N], int len, int n){
	for(int i = 0; i < len; ++i){
		if(arr[i] == n){
			++m[i];
			if(m[i] > m[i-1]){
				int tmp = ref[i];
				ref[i] = ref[i-1];
				ref[i-1] = tmp;
			}
			return 0;
		}
	}
	return -1;
}

int binarySearch(int arr[1000000], int len, int x){
	int low = 0, high = len-1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return 0;
        if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int sum_search(int arr[N], int len, int sum){
	for (int i = 0; i < len; i++){
		for (int j = i; j < len; j++){
			if((arr[i]+arr[j])==sum){
				return 0;
			}
		}
	}
	return -1;
}

int sum_optimal(int arr[N], int len, int sum){
	int right = len-1, left = 0;
	while(left <= right){
		if(arr[left]+arr[right] == sum){
			return 0;
		}
		else{
			if(arr[left]+arr[right]<sum){
				++left;
			}
			else{
				if(arr[left]+arr[right]>sum){
					--right;
				}
			}
		}
	}
	return -1;
}

void my_qsort(int arr[N], int (*ref), int l, int r)
{
    int left = l;
    int right = r;
    int mid = arr[(left + right) / 2];

    while (left <= right) {
        while (arr[left] < mid) {
            left++;
        }
        while (arr[right] > mid) {
            right--;
        }
        if (left <= right) {
            std::swap(ref[left++], ref[right--]);
        }
    }
    if (l < right) {
        my_qsort(arr, ref, l, right);
    }
    if (r > left) {
        my_qsort(arr, ref, left, r);
    }
}

int main(){
	int *m = new int[N];
	int s;
	//for(int i = 0; i < 200; i++){
		//std::cout << m[i] << std::endl;
	//}
	for (unsigned len = 100; len !=N+100; len+=100){
		rand(m);
		std::default_random_engine generator;
		std::uniform_int_distribution<int> distribution(0,100000);
		if(len%5000==0){
			s = 1;
		}
		else{
			if (len%3000==0){
				s = 2;
				}
				else{
					if (len%7000==0){
						s = 3;
					}
					else{
						s = distribution(generator);
					}
					
				}
			
		}
		
		auto begin = std :: chrono :: steady_clock ::now();
		//for (int i = 0; i < 300; i++){
		//search(m, len, distribution(generator));
		//}
		//auto end = std :: chrono :: steady_clock ::now(); 
		//auto time_span = std :: chrono :: duration_cast<std :: chrono :: milliseconds >(end - begin );
		//std :: cout << time_span.count() << std :: endl ;
		int nuls[N] = {0};
		for (int i = 0; i < 50; i++){
			search_c(m, m, nuls, len, s);
		}
		auto end = std :: chrono :: steady_clock ::now(); 
		auto time_span = std :: chrono :: duration_cast<std :: chrono :: milliseconds >(end - begin );
		std :: cout << time_span.count() << std :: endl ;
	}
	delete []m;
	return 0;
}
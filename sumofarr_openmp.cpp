#include<omp.h> 
#include <bits/stdc++.h> 
using namespace std; 

int main(){
	vector<int> arr{1, 1, 1, 1, 1, 1}; 
	queue<int> data; 
	int arr_sum = accumulate(arr.begin(), arr.end(), 0); 
	int arr_size = arr.size(); 
	int new_data_size, x, y;

	for(int i=0; i<arr_size; i++){ 
		data.push(arr[i]); 
	}
	omp_set_num_threads(ceil(arr_size/2));
	
	#pragma omp parallel 
		{ 
			#pragma omp critical 
			{ 
				new_data_size = data.size(); 
				for(int j=1; j<new_data_size; j=j*2){ 
					x = data.front(); 
					data.pop(); 
					y = data.front(); 
					data.pop(); 
					data.push(x+y); 
				} 
			} 

		} 


	cout << "Array prefix sum:" << data.front() << endl; 
	if(arr_sum == data.front())
		{ cout << "Correct sum" << endl; 
	}else{ 
		cout << "Incorrect Answer" << endl; 
	} 
	return 0;
}
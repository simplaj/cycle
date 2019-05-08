#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

void sort_2_3(int* arr, int p, int q, int* arr_min_max) {
	int n2 = q - p + 1;
	int len = 0;
	if (n2 == 2) {
		len = 2;
	}
	else if (n2 == 3) {
		len = 3;
	}
	for (int i = p; i < p + len; i++) {
		if (arr[i] < arr_min_max[0]) {
			arr_min_max[0] = arr[i];
		}
		if (arr[i] > arr_min_max[1]) {
			arr_min_max[1] = arr[i];
		}
	}
}

void sqrt_n_sort(int* arr, int p, int q, int* arr_min_max) {
	cout << "deviation" << endl;
	int n = q - p + 1;
	int n2 = int(sqrt(n));
	if (n2 > 1) {
		int i = 0;
		for (; i < n2 - 1; i++) {
			cout << p + n2 * i << "," << p + n2 * (i + 1) - 1 << endl;
			sqrt_n_sort(arr, p + n2 * i, p + n2 * (i + 1) - 1, arr_min_max);
			//sort_2_3(arr, p + n2*i, p + n2*(i+1) - 1);
		}
		cout << p + n2 * i << "," << q << endl;
		sqrt_n_sort(arr, p + n2 * i, q, arr_min_max);
		//sort_2_3(arr, p + n2*i, q);
		//Merge(arr, p, q);
		//Max_MIN()
	}
	else {
		sort_2_3(arr, p, q, arr_min_max);
	}
}

//void Merge(int*arr, int p, int q){}

int main()
{
	int arr[17] = { 3,9,11,25,18,21,19,7,6,19,22,15,19,24,2,1,16 };
	int arr_min_max[2] = { INT_MAX,INT_MIN };
	sqrt_n_sort(&arr[0], 0, 16, &arr_min_max[0]);

	//cout<<"begin:"<<endl;
	for (int i = 0; i < 2; i++) {
		cout << arr_min_max[i] << " " << endl;
	}
	return 0;
}
